#include <stdio.h>
#include "/Users/ashton/Documents/GitHub/PQWA_Final_Project/include/io.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

double RMS(double *vol, int size)
{
    double sumOfSquares = 0.0;
    double *ptr = vol;

    for (int i = 0; i < size; i++){
        sumOfSquares += ptr[i] * ptr[i];
    }

    return sqrt(sumOfSquares / size);
};

double PeakToPeak(double *vol, int size)
{
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

double DCOffset(double *vol, int size)
{
    double mean = 0.0;
    double *ptr = vol;
    for (int i = 0; i < size; i++){
        mean += ptr[i];
    }
    mean /= size;
    return mean;
}

bool detectClipping(double *vol, int size)
{
    double *ptr = vol;
    for (int i = 0; i < size; i++){
        if (abs(ptr[i] >= 324.9)){
            return true;
        }
    }
    return false;
}

void WaveFormCalculations(WaveformData *dataArray)
{
    double phaseArms = RMS(dataArray->phase_a_voltage, dataArray->size);
    double phaseBrms = RMS(dataArray->phase_b_voltage, dataArray->size);
    double phaseCrms = RMS(dataArray->phase_c_voltage, dataArray->size);

    double phaseApeak = PeakToPeak(dataArray->phase_a_voltage, dataArray->size);
    double phaseBpeak = PeakToPeak(dataArray->phase_b_voltage, dataArray->size);
    double phaseCpeak = PeakToPeak(dataArray->phase_c_voltage, dataArray->size);

    double phaseAoffset = DCOffset(dataArray->phase_a_voltage, dataArray->size);
    double phaseBoffset = DCOffset(dataArray->phase_b_voltage, dataArray->size);
    double phaseCoffset = DCOffset(dataArray->phase_c_voltage, dataArray->size);

    double tolerance = 0.1;
    double expectedValue = 230;
    double lower = expectedValue * (1.0 - tolerance);
    double higher = expectedValue * (1.0 + tolerance);

    bool phaseAcompliance = true;
    bool phaseBcompliance = true;
    bool phaseCcompliance = true;

    bool phaseAclipping = detectClipping(dataArray->phase_a_voltage, dataArray->size);
    bool phaseBclipping = detectClipping(dataArray->phase_b_voltage, dataArray->size);
    bool phaseCclipping = detectClipping(dataArray->phase_c_voltage, dataArray->size);

    if (phaseArms < lower && phaseArms > higher) phaseAcompliance = false;
    if (phaseBrms < lower && phaseBrms > higher) phaseBcompliance = false;
    if (phaseCrms < lower && phaseCrms > higher)  phaseCcompliance = false;

    FILE *fptr;
    fptr = fopen("sampleData.txt", "w");
    fprintf(fptr, "Phase  ||  RMS  ||  Peak to Peak || DC Offset  ||  Tolerance Compliant  ||  Clipping\n");
    fprintf(fptr, "----------------------------------------------------------------------\n");
    fprintf(fptr, "  A      %.2f       %.2f         %.2f             %s             %s \n", phaseArms, phaseApeak, phaseAoffset,
                                                                                    phaseAcompliance ? "Compliant" : "Non-compliant",
                                                                                    phaseAclipping ? "Clipping" : "OK");
    fprintf(fptr, "  B      %.2f       %.2f         %.2f             %s             %s \n", phaseBrms, phaseBpeak, phaseBoffset,
                                                                                    phaseBcompliance ? "Compliant" : "OK",
                                                                                    phaseBclipping ? "Clipping" : "No clipping");
    fprintf(fptr, "  C      %.2f       %.2f         %.2f             %s             %s \n", phaseCrms, phaseCpeak, phaseCoffset,
                                                                                    phaseCcompliance ? "Compliant" : "Non-compliant",
                                                                                    phaseCclipping ? "Clipping" : "OK");

    fclose(fptr);
}

