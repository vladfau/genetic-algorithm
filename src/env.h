#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

struct inputCfg {
    uint16_t initialPopulation;
    float uniformRate;
    float mutationRate;
};

typedef struct inputCfg cfg_t;

void configureGA(cfg_t * config);
