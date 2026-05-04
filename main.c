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

    free(data);

    return 0;
}

