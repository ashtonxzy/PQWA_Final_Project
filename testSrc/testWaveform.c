#include <stdio.h>
#include <tgmath.h>

#include "../include/waveform.h"

//Test to ensure RMS is working correctly
double RMS(double *vol, int size)
{
    //Calculate RMS
    double sum_sq = 0.0;
    double *ptr = vol;

    for (int i = 0; i < size; i++){
        sum_sq += ptr[i] * ptr[i];
    }

    return sqrt(sum_sq / size);
};


int main() {
    double testData[] = {230.0, -230.0, 230.0, -230.0};
    int size = 4;

    double rms = RMS(testData, size);

    printf("RMS = %f\n", rms);

    if (rms > 229 && rms < 231) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    return 0;
}