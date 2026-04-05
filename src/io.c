#include "../include/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

WaveformData* loadData(char fname[])
{
    /*--------------OPENING FILE--------------*/
    FILE *csvFile = fopen(fname, "r"); /*Open user specified file*/
    if (csvFile == NULL) /*Check if file is valid*/
    {
        perror("Can't open file"); /*Gives error feedback*/
        exit(1);
    }


    /*--------------CREATE STRUCTURE AND ALLOCATE MEMORY--------------*/
    int rowCount = 0;
    char line[256];

    fgets(line, sizeof(line), csvFile); /*Skips the header*/
    while (fgets(line, sizeof(line), csvFile) != NULL)
    {
        rowCount++; /* Count number of rows to allocate right amount of memory*/
    }
    fseek(csvFile, 0, SEEK_SET); /*Move back to start*/

    WaveformData *dataArray = malloc(sizeof(WaveformData) * rowCount); /*Structure to store each line from csv*/


    /*--------------STORE CONTENTS IN STRUCTURE--------------*/

    //TODO: CHANGE ARRAY INDEXING FOR POINTER PARSING
    fgets(line, sizeof(line), csvFile);
    int count = 0; /*Loop through rows*/
    while (fgets(line, sizeof(line), csvFile)) /*Loop through contents of file*/
    {
        line[strcspn(line, "\n")] = '\0'; /*Removes new line after rows*/
        const char *token = strtok(line, ","); /*Pointer for where csv data should be split*/
        int col = 0; /*Count columns for structures*/
        while (token != NULL)
        {
            switch (col) //Case for each column
            {
                //Store data in each variable in the structure
                case 0: dataArray->timestamp[count] = atof(token); break;
                case 1: dataArray->phase_a_voltage[count] = atof(token); break;
                case 2: dataArray->phase_b_voltage[count] = atof(token); break;
                case 3: dataArray->phase_c_voltage[count] = atof(token); break;
                case 4: dataArray->line_current[count] = atof(token); break;
                case 5: dataArray->frequency[count] = atof(token); break;
                case 6: dataArray->power_factor[count] = atof(token); break;
                case 7: dataArray->thd_percent[count] = atof(token); break;
                default: ;
            }
            token = strtok(NULL, ",");
            col++;
        }
        count++;
    }

    fclose(csvFile); /*Close the file */
  //  return dataArray;


    //Print out structure for debugging
    for (int j = 0;j < count; j++) {
        printf("%f %f %f %f %f %f %f %f\n",
               *dataArray->timestamp[j],
               *dataArray->phase_a_voltage[j],
               *dataArray->phase_b_voltage[j],
               *dataArray->phase_c_voltage[j],
               *dataArray->line_current[j],
               *dataArray->frequency[j],
               *dataArray->power_factor[j],
               *dataArray->thd_percent[j]);
    }
}