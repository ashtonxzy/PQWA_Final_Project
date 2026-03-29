//
// Created by Ashton C on 29/03/2026.
//

#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"

WaveformData *loadFileData(char *fName, int *count)
{
    char fname[256];
    const FILE *file;

    /*--------------FILE INPUT--------------*/
    printf("Please enter file location: \n");
    printf(">>");
    fgets(fname, 256, stdin);

    /*--------------FILE SAFETY CHECK--------------*/
    if (file == NULL)
    {
        printf("Error opening file\n");
    }

    return 0;
}
