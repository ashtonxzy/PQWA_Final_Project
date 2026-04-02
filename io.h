#ifndef PQWA_FINAL_PROJECT_IO_H
#define PQWA_FINAL_PROJECT_IO_H
#include "waveform.h"

void loadData(char fname[]);

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

#endif //PQWA_FINAL_PROJECT_IO_H