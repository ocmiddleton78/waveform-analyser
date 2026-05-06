#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "waveform.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    size_t count = 0;

    WaveformSample *data = load_csv(argv[1], &count);

    if (data == NULL) {
        printf("File could not be loaded\n");
        return 1;
    }

    double dcA = calculate_dc_offset(data, count, 'A');
    double dcB = calculate_dc_offset(data, count, 'B');
    double dcC = calculate_dc_offset(data, count, 'C');

    printf("DC Offset A: %f\n", dcA);
    printf("DC Offset B: %f\n", dcB);
    printf("DC Offset C: %f\n", dcC);

    double rmsA = calculate_rms(data, count, 'A');
    double rmsB = calculate_rms(data, count, 'B');
    double rmsC = calculate_rms(data, count, 'C');

    printf("RMS A: %f\n", rmsA);
    printf("RMS B: %f\n", rmsB);
    printf("RMS C: %f\n", rmsC);

    double p2pA = calculate_peak_to_peak(data, count, 'A');
    double p2pB = calculate_peak_to_peak(data, count, 'B');
    double p2pC = calculate_peak_to_peak(data, count, 'C');

    printf("Peak to peak A: %f\n", p2pA);
    printf("Peak to peak B: %f\n", p2pB);
    printf("Peak to peak C: %f\n", p2pC);

    int clipA = detect_clipping(data, count, 'A');
    int clipB = detect_clipping(data, count, 'B');
    int clipC = detect_clipping(data, count, 'C');

    printf("Clipping count A: %d\n", clipA);
    printf("Clipping count B: %d\n", clipB);
    printf("Clipping count C: %d\n", clipC);

    int tolA = within_tolerance(rmsA);
    int tolB = within_tolerance(rmsB);
    int tolC = within_tolerance(rmsC);

    printf("Tolerance A: %d\n", tolA);
    printf("Tolerance B: %d\n", tolB);
    printf("Tolerance C: %d\n", tolC);

    free(data);

    return 0;
}

