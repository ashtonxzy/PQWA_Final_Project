#include "../include/waveform.h"
#include "../include/io.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void Peak2Peak(WaveformData *dataArray)
{

    /*TODO: PeakToPeak
     * Loop through and find max/min
     * Difference between the two
     */
};

void DCOffset(WaveformData *dataArray)
{
    /*TODO: DC Offset
     *Sum of voltages in each phase halved
     */

};

void RMS(const WaveformData *dataArray)
{
    /*TODO: RMS
     *Loop through structure down each phase column
     *sum_sq = current + current index^2
     *sqrt sum_sq/count
     */

    double sum_sq = 0.0;
    for (int i = 0; i < 8; i++) //TODO: Find size to stop errors
    {
        sum_sq += dataArray[i].phase_a_voltage * dataArray[i].phase_a_voltage;
    }


};

WaveFormCalculations WaveformCalcs(WaveformData *dataArray)
{
    WaveFormCalculations phaseAreturn;
    //TODO: CALCULATE RMS | P2P | DC OFFSET

    //--------------RMS--------------
    //  = RMS(dataArray);
    // if (RMS(dataArray) <= 207 || RMS(dataArray) >= 253)
    // {
    //         phaseAreturn.isCompliant = true;
    // }
    // else
    // {
    //     phaseAreturn.isCompliant = false;
    // }

    //--------------P2P--------------


    //--------------DC OFFSET--------------

    //TODO: ASK BEST WAY TO FORMAT STRUCTURE FOR EACH PHASE
}

