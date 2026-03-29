//
// Created by Ashton C on 29/03/2026.
//

#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"

WaveformData *loadFileData(const char *fName, int *count)
{
    /*--------------VARIABLE DECLARATION--------------*/
    char fname[256];
    const FILE *file;

    /*--------------FILE INPUT--------------*/
    printf("Please enter file location: \n");
    printf(">>");
    fgets(fname, 256, stdin);

    /*--------------FILE SAFETY CHECK--------------*/
    file = fopen(fName, "r"); /*Sets pointer to first char*/
    if (file == NULL)
    {
        printf("Error opening file\n");
        /*Return to main*/
    }
    else
    {
        
    }




    return 0;
}
