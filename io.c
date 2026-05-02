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

    printf("File opened inside load_csv\n");

    fclose(file);

    *count = 0;
    return (WaveformSample *)1;
}