//
// Created by owen on 17/04/2026.
//

#ifndef IO_H
#define IO_H

#include <stddef.h>
#include "waveform.h"

WaveformSample *load_csv(const char *filename, size_t *count);

int write_results(const char *filename,
                  double rmsA , double rmsB , double rmsC ,
                  double p2pA , double p2pB , double p2pC ,
                  double dcA , double dcB , double dcC ,
                  int clipA , int clipB , int clipC);

#endif
