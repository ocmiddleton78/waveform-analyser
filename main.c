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

    double rmsA = calculate_rms(data, count, 'A');
    double rmsB = calculate_rms(data, count, 'B');
    double rmsC = calculate_rms(data, count, 'C');

    double p2pA = calculate_peak_to_peak(data, count, 'A');
    double p2pB = calculate_peak_to_peak(data, count, 'B');
    double p2pC = calculate_peak_to_peak(data, count, 'C');

    int clipA = detect_clipping(data, count, 'A');
    int clipB = detect_clipping(data, count, 'B');
    int clipC = detect_clipping(data, count, 'C');

    int tolA = within_tolerance(rmsA);
    int tolB = within_tolerance(rmsB);
    int tolC = within_tolerance(rmsC);

    write_results("results.txt",
                  rmsA, rmsB, rmsC,
                  p2pA, p2pB, p2pC,
                  dcA, dcB, dcC,
                  clipA, clipB, clipC);

    free(data);

    return 0;
}

