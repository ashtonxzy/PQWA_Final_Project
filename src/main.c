#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/io.h"
#include "../include/waveform.h"

int main(void)
{
    /* --------------VARIABLES-------------- */
    char fname[256] = "";
    bool exit = false;

    do{
        /* --------------MENU-------------- */
        printf("-----------------------------------------------------------------\n");
        printf(" ____                ___            __        __          \n"
               "|  _ \\ _____      __/ _ \\ _   _  __ \\ \\      / /_ ___   __\n"
               "| |_) / _ \\ \\ /\\ / / | | | | | |/ _` \\ \\ /\\ / / _` \\ \\ / /\n"
               "|  __/ (_) \\ V  V /| |_| | |_| | (_| |\\ V  V / (_| |\\ V /\n"
               "|_|   \\___/ \\_/\\_/  \\__\\_\\\\__,_|\\__,_| \\_/\\_/ \\__,_| \\_/  \n");
        printf("V1.0                                              By Ashton Crane\n ");
        printf("-----------------------------------------------------------------\n");
        printf("\n");
        printf("('99' to exit)\n");
        printf("Please enter file location:\n");
        printf(">>");
        fgets(fname, sizeof(fname), stdin);
        fname[strcspn(fname, "\n")] = 0;
        if (strcmp(fname, "99") == 0) //Exit case
        {
            exit = true;
            continue;
        }
        if (strcmp(fname, "") == 0) //Nothing entered case
        {
            printf("No valid file entered.");
            continue;
        }


        /*--------------FILE HANDLING--------------*/
        fname[strcspn(fname, "\n")] = 0;/*Removes \n from end of string*/
        printf("Opening file: %s\n", fname); /*Debug to check if right file is being opened - was having issues*/
        WaveformData *data = LoadData(fname);
        WaveFormCalculations(data);
        free(data);



    } while (exit == false);
    return 0;
}