//
// Created by owen on 17/04/2026.
//

#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;

#endif