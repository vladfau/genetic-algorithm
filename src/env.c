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
    const char * vars[] = {"IP", "CP", "UR", "MR"};

    char _popSize[20];
    getFromEnv(vars[0], _popSize, sizeof(_popSize));

    sscanf(_popSize, "%"SCNu16"\n" , &config->initialPopulation);

    char _crossingPoint[80];
    getFromEnv(vars[1], _crossingPoint, sizeof(_crossingPoint));
    sscanf(_crossingPoint, "%"SCNu16"\n" , &config->crossingPoint);

    char _uniformRate[40];
    getFromEnv(vars[2], _uniformRate, sizeof(_uniformRate));
    sscanf(_uniformRate, "%f" , &config->uniformRate);

    char _mutationRate[40];
    getFromEnv(vars[3], _mutationRate, sizeof(_mutationRate));
    sscanf(_mutationRate, "%f" , &config->mutationRate);
}

