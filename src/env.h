#pragma once
#include "util.h"

struct inputCfg {
    uint16_t initialPopulation;
    float uniformRate;
    float mutationRate;
};

typedef struct inputCfg cfg_t;

void getFromEnv(const char * variable, char * result, int bufSize);
void configureGA(cfg_t * config);
