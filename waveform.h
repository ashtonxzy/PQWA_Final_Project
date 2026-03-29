//
// Created by Ashton C on 29/03/2026.
//
#ifndef PQWA_FINAL_PROJECT_WAVEFORM_H
#define PQWA_FINAL_PROJECT_WAVEFORM_H

typedef struct
{
    float timestamp;
    double phase_a_voltage;
    double phase_b_voltage;
    double phase_c_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
}WaveformData;

#endif //PQWA_FINAL_PROJECT_WAVEFORM_H