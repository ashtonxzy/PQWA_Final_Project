#include <stdio.h>
#include "/Users/ashton/Documents/GitHub/PQWA_Final_Project/include/io.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/syslimits.h>
#include <unistd.h>


double Mean(double *vol, int size)
{
    double mean = 0.0;
    double *ptr = vol;
    for (int i = 0; i < size; i++){
        mean += ptr[i];
    }
    mean /= size;
    return mean;
}

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

double PeakToPeak(double *vol, int size)
{
    //Calculate peak to peak
    double maxSample = 0;
    double minSample = 0;
    double *ptr = vol;
    for (int i = 0; i < size; i++){
        if (ptr[i] > maxSample){
            maxSample = ptr[i];
        }
    }
    for (int i = 0; i < size; i++){
        if (ptr[i] < minSample){
            minSample = ptr[i];
        }
    }
    const double peakToPeak = maxSample - minSample;
    return peakToPeak;
}

bool DetectClipping(double *vol, int size)
{
    //Detects if values are greater than 324.9
    double *ptr = vol;
    for (int i = 0; i < size; i++){
        if (abs(ptr[i] >= 324.9)){
            return true;
        }
    }
    return false;
}

double VarianceCalc(double *vol, int size)
{
    double mean = Mean(vol, size);
    double *ptr = vol;
    double sum = 0.0;
    //Variance
    for (int i = 0; i < size; i++){
        sum += fabs(pow((ptr[i] - mean), 2));
    }
    return sum / size;
}

void WaveFormCalculations(WaveformData *dataArray)
{
    //--------------VARIABLE DECLARATION AND LOGIC--------------
    double rmsA = RMS(dataArray->phase_a_voltage, dataArray->size);
    double rmsB = RMS(dataArray->phase_b_voltage, dataArray->size);
    double rmsC = RMS(dataArray->phase_c_voltage, dataArray->size);

    double peakA = PeakToPeak(dataArray->phase_a_voltage, dataArray->size);
    double peakB = PeakToPeak(dataArray->phase_b_voltage, dataArray->size);
    double peakC = PeakToPeak(dataArray->phase_c_voltage, dataArray->size);

    double offsetA = Mean(dataArray->phase_a_voltage, dataArray->size);
    double offsetB = Mean(dataArray->phase_b_voltage, dataArray->size);
    double offsetC = Mean(dataArray->phase_c_voltage, dataArray->size);

    double tolerance = 0.1;
    double expectedValue = 230;
    double lower = expectedValue * (1.0 - tolerance);
    double higher = expectedValue * (1.0 + tolerance);

    double varianceA = VarianceCalc(dataArray->phase_a_voltage, dataArray->size);
    double varianceB = VarianceCalc(dataArray->phase_b_voltage, dataArray->size);
    double varianceC = VarianceCalc(dataArray->phase_c_voltage, dataArray->size);

    bool complianceA = true;
    bool complianceB = true;
    bool complianceC = true;

    bool clippingA = DetectClipping(dataArray->phase_a_voltage, dataArray->size);
    bool clippingB = DetectClipping(dataArray->phase_b_voltage, dataArray->size);
    bool clippingC = DetectClipping(dataArray->phase_c_voltage, dataArray->size);

    if (rmsA < lower && rmsA > higher) complianceA = false;
    if (rmsB < lower && rmsB > higher) complianceB = false;
    if (rmsC < lower && rmsC > higher)  complianceC = false;


    //--------------STORE DATA FILE--------------
    FILE* fptr = fopen("sampleData.txt", "w");
    fprintf(fptr, "Phase  ||  RMS  ||  Peak to Peak || DC Offset  ||  Tolerance Compliant  ||  Clipping\n");
    fprintf(fptr, "----------------------------------------------------------------------\n");
    fprintf(fptr, "  A      %.2f       %.2f         %.2f             %s             %s \n", rmsA, peakA, offsetA,
                                                                                    complianceA ? "Compliant" : "Non-compliant",
                                                                                    clippingA ? "Clipping" : "OK");
    fprintf(fptr, "  B      %.2f       %.2f         %.2f             %s             %s \n", rmsB, peakB, offsetB,
                                                                                    complianceB ? "Compliant" : "OK",
                                                                                    clippingB ? "Clipping" : "No clipping");
    fprintf(fptr, "  C      %.2f       %.2f         %.2f             %s             %s \n", rmsC, peakC, offsetC,
                                                                                    complianceC ? "Compliant" : "Non-compliant",
                                                                                    clippingC ? "Clipping" : "OK");

    fprintf(fptr, "======================================================================\n");
    fprintf(fptr, "Phase ||  Variance ||  Std Dev  \n");
    fprintf(fptr, "----------------------------------------------------------------------\n");
    fprintf(fptr, "  A       %.2f     %.2f \n", varianceA, sqrt(varianceA));
    fprintf(fptr, "  B       %.2f     %.2f \n", varianceB, sqrt(varianceB));
    fprintf(fptr, "  C       %.2f     %.2f \n", varianceC, sqrt(varianceC));
    fclose(fptr);

    //--------------PRINT DATA FILE--------------

    printf("\n");
    printf("\n");
    FILE* fptr2 = fopen("sampleData.txt", "r");
    char ch;
    while ((ch = fgetc(fptr2)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    printf("\n");
    printf("\n");

}
