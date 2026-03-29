#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "waveform.h"
#include "io.h"


int main(void)
{
    /* --------------VARIABLES-------------- */
    char choice[2] = "w";
    bool exit = false;

    do
    {
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

        printf("Press any key to continue...      ('99' to exit)\n");
        fgets(choice, 3, stdin);
        if (strcmp(choice, "99") == 0)
        {
            exit = true;
        }
        else
        {
            /*--------------FILE HANDLING--------------*/

        }

    } while (exit == false);
    return 0;
}