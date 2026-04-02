//
// Created by Ashton C on 29/03/2026.
//
#ifndef PQWA_FINAL_PROJECT_WAVEFORM_H
#define PQWA_FINAL_PROJECT_WAVEFORM_H
#include <stdbool.h>
#include "io.h"

typedef struct
{
    double rms;
    double peak2peak;
    double dcOffset;
    bool isCompliant;
}WaveFormCalculations; //Structure to hold the calculations to return

void Peak2Peak(WaveformData *dataArray); //TODO: ask how to access io.c dataarray in this file

void DCOffset(WaveformData *dataArray);

void RMS(const WaveformData *dataArray);

#endif //PQWA_FINAL_PROJECT_WAVEFORM_H