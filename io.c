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

    printf("Rows found: %zu\n", rows);

    WaveformSample *samples = malloc(rows * sizeof(WaveformSample));

    if (samples == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    fclose(file);

    *count = rows;
    return samples;
}