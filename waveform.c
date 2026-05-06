//
// Created by owen on 17/04/2026.
//

#include "waveform.h"
#include <math.h>

double calculate_dc_offset(const WaveformSample *samples, size_t count, char phase) {
    double total = 0.0;

    for (size_t i = 0; i < count; i++) {
        if (phase == 'A') {
            total += samples[i].phase_A_voltage;
        } else if (phase == 'B') {
            total += samples[i].phase_B_voltage;
        } else if (phase == 'C') {
            total += samples[i].phase_C_voltage;
        }
    }

    return total / count;
}

double calculate_rms(const WaveformSample *samples, size_t count, char phase) {
    double total = 0.0;

    for (size_t i = 0; i < count; i++) {
        double value = 0.0;

        if (phase == 'A') {
            value = samples[i].phase_A_voltage;
        } else if (phase == 'B') {
            value = samples[i].phase_B_voltage;
        } else if (phase == 'C') {
            value = samples[i].phase_C_voltage;
        }

        total += value * value;
    }

    double mean = total / count;
    return sqrt(mean);
}

double calculate_peak_to_peak(const WaveformSample *samples, size_t count, char phase) {
    double min = 0.0;
    double max = 0.0;

    for (size_t i = 0; i < count; i++) {
        double value = 0.0;

        if (phase == 'A') {
            value = samples[i].phase_A_voltage;
        } else if (phase == 'B') {
            value = samples[i].phase_B_voltage;
        } else if (phase == 'C') {
            value = samples[i].phase_C_voltage;
        }

        if (i ==0 || value < min) {
            min = value;
        }

        if (i == 0 || value > max) {
            max = value;
        }
    }

    return max - min;
}

int detect_clipping(const WaveformSample *samples, size_t count, char phase) {
    int clipped_count = 0;

    for (size_t i = 0; i < count; i++) {
        double value = 0.0;

        if (phase == 'A') {
            value = samples[i].phase_A_voltage;
        } else if (phase == 'B') {
            value = samples[i].phase_B_voltage;
        } else if (phase == 'C') {
            value = samples[i].phase_C_voltage;
        }

        if (value >= 324.9 || value <= -324.9) {
            clipped_count++;
        }
    }

    return clipped_count;
}