//
// Created by Ashton C on 29/03/2026.
//

#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "waveform.h"

WaveformData *loadFileData()
{
    /*--------------VARIABLE DECLARATION--------------*/
    char fname[256];
    FILE *file;
    char *buffer;
    int fileSize;
    int lineCount;

    /*--------------FILE INPUT--------------*/
    printf("Please enter file location: \n");
    printf(">>");
    fgets(fname, 256, stdin); /*Store user input*/
    fname[strcspn(fname, "\n")] = '\0'; /*Removes \n from end of user input*/


    /*--------------FILE SAFETY CHECK--------------*/
    file = fopen(fname, "r"); /*Sets pointer to first char*/
    if (file == NULL) /*Check if file is empty*/
    {
        printf("Error opening file\n");
        /*Return to main*/
    }
    else
    {
        fseek(file, 0, SEEK_END); /*Get file size by setting pointer to end of file*/
        fileSize = ftell(file);
        fseek(file, 0, SEEK_SET); /*Set pointer to start again*/
        buffer = (char *)malloc(fileSize); /*Allocate memory for the data inside the file*/
        if (buffer == NULL) /*Check for errors*/
        {
            printf("Error allocating memory\n");
        }
        else
        {
            fread(buffer, 1, fileSize, file); /*Read data from file into buffer*/
            fclose(file);
            fwrite(buffer, 1, fileSize, stdout);
        }

    }

    return 0;
}
