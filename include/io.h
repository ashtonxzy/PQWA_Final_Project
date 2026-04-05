#ifndef PQWA_FINAL_PROJECT_IO_H
#define PQWA_FINAL_PROJECT_IO_H

typedef struct
{
    int size;
    double timestamp[1000];
    double phase_a_voltage[1000];
    double phase_b_voltage[1000];
    double phase_c_voltage[1000];
    double line_current[1000];
    double frequency[1000];
    double power_factor[1000];
    double thd_percent[1000];
}WaveformData;

WaveformData* loadData(char fname[]);


#endif //PQWA_FINAL_PROJECT_IO_H