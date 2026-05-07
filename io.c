//
// Created by owen on 17/04/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include "io.h"

WaveformSample *load_csv(const char *filename, size_t *count) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    char line[256];

    fgets(line, sizeof(line), file);

    size_t rows = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        rows++;
    }

    WaveformSample *samples = malloc(rows * sizeof(WaveformSample));

    if (samples == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    rewind(file);

    fgets(line, sizeof(line), file);

    size_t i = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        int fields_read = sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                                 &samples[i].timestamp,
                                 &samples[i].phase_A_voltage,
                                 &samples[i].phase_B_voltage,
                                 &samples[i].phase_C_voltage,
                                 &samples[i].line_current,
                                 &samples[i].frequency,
                                 &samples[i].power_factor,
                                 &samples[i].thd_percent);

        if (fields_read != 8) {
            printf("Problem reading row %zu, fields read: %d\n", i, fields_read);
        }

        i++;
    }

    fclose(file);

    *count = rows;
    return samples;
}

int write_results(const char *filename,
                  double rmsA, double rmsB, double rmsC,
                  double p2pA, double p2pB, double p2pC,
                  double dcA, double dcB, double dcC,
                  int clipA, int clipB, int clipC) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error writing results\n");
        return 1;
    }

    fprintf(file, "Power Quality Waveform Analyser Results\n");
    fprintf(file, "---------------------------------------\n\n");

    fprintf(file, "RMS Voltage:\n");
    fprintf(file, "Phase A: %.2f V\n", rmsA);
    fprintf(file, "Phase B: %.2f V\n", rmsB);
    fprintf(file, "Phase C: %.2f V\n\n", rmsC);

    fprintf(file, "Peak-to-Peak Voltage:\n");
    fprintf(file, "Phase A: %.2f V\n", p2pA);
    fprintf(file, "Phase B: %.2f V\n", p2pB);
    fprintf(file, "Phase C: %.2f V\n\n", p2pC);

    fprintf(file, "DC Offset:\n");
    fprintf(file, "Phase A: %.2f V\n", dcA);
    fprintf(file, "Phase B: %.2f V\n", dcB);
    fprintf(file, "Phase C: %.2f V\n\n", dcC);

    fprintf(file, "Clipping Count:\n");
    fprintf(file, "Phase A: %d\n", clipA);
    fprintf(file, "Phase B: %d\n", clipB);
    fprintf(file, "Phase C: %d\n", clipC);

    fclose(file);
    return 0;
}