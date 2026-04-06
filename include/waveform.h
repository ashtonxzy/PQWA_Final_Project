//
// Created by Ashton C on 29/03/2026.
//
#ifndef PQWA_FINAL_PROJECT_WAVEFORM_H
#define PQWA_FINAL_PROJECT_WAVEFORM_H
#include <stdbool.h>

#include "io.h"

void WaveFormCalculations(WaveformData* dataArray);

double RMS(double *vol, int size);

double DCOffset(double *vol, int size);

double PeakToPeak(double *vol, int size);

bool detectClipping(double *vol, int size);

double ReturnData(double *vol, int size);
#endif //PQWA_FINAL_PROJECT_WAVEFORM_H