#include <stdio.h>
#include "/Users/ashton/Documents/GitHub/PQWA_Final_Project/include/io.h"
#include <math.h>

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

double detectClipping(double *vol, int size)
{

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

    printf("RMS Phase A: %f V \n", phaseArms);
    printf("RMS Phase B: %f V \n", phaseBrms);
    printf("RMS Phase C: %f V \n", phaseCrms);

    printf("Phase A peak to peak: %f V \n", phaseApeak);
    printf("Phase B peak to peak: %f V \n", phaseBpeak);
    printf("Phase C peak to peak: %f V \n", phaseCpeak);

    printf("Phase A DC Offset: %f V \n", phaseAoffset);
    printf("Phase B DC Offset: %f V \n", phaseBoffset);
    printf("Phase C DC Offset: %f V \n", phaseCoffset);
}

