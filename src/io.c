#include "../include/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WaveformData* LoadData(char fname[])
{
    /*--------------OPENING FILE--------------*/
    FILE *csvFile = fopen(fname, "r"); /*Open user specified file*/
    if (csvFile == NULL){ /*Check if file is valid*/
        perror("Can't open file");
        exit(1);
    }

    //--------------FILE FORMAT CHECK--------------
    char header[100];
    fgets(header, sizeof(header), csvFile);
    if (strstr(header, "phase_A_voltage") == NULL ||
        strstr(header, "phase_B_voltage") == NULL ||
        strstr(header, "phase_C_voltage") == NULL)
    {
        printf("Incorrect file format\n");
        fclose(csvFile);
        return NULL;
    }

    /*--------------CREATE STRUCTURE AND ALLOCATE MEMORY--------------*/
    int rowCount = 0;
    char line[256];
    fgets(line, sizeof(line), csvFile); /*Skips the header*/
    while (fgets(line, sizeof(line), csvFile)) rowCount++; /* Count number of rows to allocate right amount of memory*/
    fseek(csvFile, 0, SEEK_SET); /*Move back to start*/
    fgets(line, sizeof(line), csvFile); // Skips header again

    /*--------------STORE CONTENTS IN STRUCTURE--------------*/

    //TODO: CHANGE ARRAY INDEXING FOR POINTER PARSING
    WaveformData *dataArray = malloc(sizeof(WaveformData));
    dataArray->size = rowCount;
    int count = 0; /*Loop through rows*/
    while (fgets(line, sizeof(line), csvFile)) /*Loop through contents of file*/
    {
        line[strcspn(line, "\n")] = '\0'; /*Removes new line after rows*/
        char *token = strtok(line, ","); /*Pointer for where csv data should be split*/
        int col = 0; /*Count columns for structures*/
        while (token){
            double value = atof(token);
            switch (col){
                //Store data in each variable in the structure
                case 0: dataArray->timestamp[count] = value; break;
                case 1: dataArray->phase_a_voltage[count] = value; break;
                case 2: dataArray->phase_b_voltage[count] = value; break;
                case 3: dataArray->phase_c_voltage[count] = value; break;
                case 4: dataArray->line_current[count] = value; break;
                case 5: dataArray->frequency[count] = value; break;
                case 6: dataArray->power_factor[count] = value; break;
                case 7: dataArray->thd_percent[count] = value; break;
                default: ;
            }
            token = strtok(NULL, ",");
            col++;
           // printf("Col %d token: '%s' -> %f\n", col, token, value); //debugging
        }
        if (col != 8) //If a csv gets past the first check, this will make sure every line has 8 pieces of data
        {
            printf("Not enough Data at line %d\n", count);
            fclose(csvFile);
            return NULL;
        }
        count++;
        //printf("Line %d: '%s'\n", count, line); //debugging
    }
    fclose(csvFile); /*Close the file */
    return dataArray;

}