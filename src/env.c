#include "env.h"

void getFromEnv(const char * variable, char * result, int bufSize) {
    char * readEnv;
    readEnv = getenv(variable);
    if (readEnv != NULL)
        strncpy(result, readEnv, bufSize - 1);
    else
        *result = '\0';
    result[bufSize - 1] = '\0';
}

void configureGA(cfg_t * config){
    const char * vars[] = {"IP", "UR", "MR", "TG"};

    char _popSize[20];
    getFromEnv(vars[0], _popSize, sizeof(_popSize));
    sscanf(_popSize, "%"SCNu16"\n" , &config->initialPopulation);

    char _uniformRate[40];
    getFromEnv(vars[1], _uniformRate, sizeof(_uniformRate));
    sscanf(_uniformRate, "%f" , &config->uniformRate);

    char _mutationRate[40];
    getFromEnv(vars[2], _mutationRate, sizeof(_mutationRate));
    sscanf(_mutationRate, "%f" , &config->mutationRate);

    char _targetGenome[MAX_GENOME + 1];
    getFromEnv(vars[3], _targetGenome, sizeof(_targetGenome));
    memcpy(&config->targetGenome, _targetGenome, strlen(_targetGenome));
}

