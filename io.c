//
// Created by Ashton C on 29/03/2026.
//

#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "waveform.h"

WaveformData loadData(char fname[])
{
    FILE *csvFile = fopen(fname, "r"); /*Open user specified file*/
    if (csvFile == NULL) /*Check if file is valid*/
    {
        printf("Can't open file %s\n", fname);
        /*TODO: RETURN NULL*/
    }
    char line[256];
    while (fgets(line, sizeof(line), csvFile)) /*Loop through contents of file*/
    {
        char *token = strtok(line, ","); /*Pointer for where csv data should be split*/

        while (token != NULL)
        {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }


}