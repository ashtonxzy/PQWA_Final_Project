#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "waveform.h"

void loadData(char fname[])
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
    fgets(line, sizeof(line), csvFile);
    int count = 0; /*Loop through rows*/
    while (fgets(line, sizeof(line), csvFile)) /*Loop through contents of file*/
    {
        line[strcspn(line, "\n")] = '\0'; /*Removes new line after rows*/
        const char *token = strtok(line, ","); /*Pointer for where csv data should be split*/
        int col = 0; /*Count columns for structures*/
        while (token != NULL) /*Count skips first line*/
        {
            switch (col)
            {
                case 0: dataArray[count].timestamp = atof(token); break;;
                case 1: dataArray[count].phase_a_voltage = atof(token); break;
                case 2: dataArray[count].phase_b_voltage= atof(token); break;
                case 3: dataArray[count].phase_c_voltage = atof(token); break;
                case 4: dataArray[count].line_current = atof(token); break;
                case 5: dataArray[count].frequency = atof(token); break;
                case 6: dataArray[count].power_factor = atof(token); break;
                case 7: dataArray[count].thd_percent = atof(token); break;
                default: ;
            }
            token = strtok(NULL, ",");
            col++;
        }
        count++;
    }
    fclose(csvFile); /*Close the file */
    for (int j = 0; j < count; j++) {
        printf("%f %f %f %f %f %f %f %f\n",
               dataArray[j].timestamp,
               dataArray[j].phase_a_voltage,
               dataArray[j].phase_b_voltage,
               dataArray[j].phase_c_voltage,
               dataArray[j].line_current,
               dataArray[j].frequency,
               dataArray[j].power_factor,
               dataArray[j].thd_percent);
    }
    free(dataArray); /*Free the allocated memory*/



}