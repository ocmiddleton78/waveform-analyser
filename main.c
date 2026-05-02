#include <stdio.h>
#include <stdlib.h>
#include "io.h"

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

    printf("File opened successfully\n");

    //free(data);

    return 0;
}

