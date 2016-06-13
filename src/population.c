#include "population.h"

uint8_t randr(uint8_t min, uint8_t max) {
    double scaled = (double)rand()/RAND_MAX;
    return (max - min + 1) * scaled + min;
}

char inverse(char ch) {
    return (ch == '1')? '0':'1';
}

individual * createIndividual() {
    individual * ind = (individual *) malloc(sizeof(individual));
    char * g;
    g = malloc(sizeof(char) * MAX_GENOME + 1);
    for (uint8_t i = 0; i < MAX_GENOME; i++)
        if (rand() & 1) g[i] = '1'; else g[i] = '0';
    g[MAX_GENOME] = '\0';
    ind->genes = g;
    return ind;
}

population createPopulation(uint16_t size) {
    population newP = malloc(sizeof(individual * ) * size);
    for (uint16_t i = 0; i < size; i++) {
        individual * ind = createIndividual();
        printf("create individual @ %d\n", ind->genes, ind);
        newP[i] = ind;
    }

    return newP;
}

void mutate(individual * ind, float mutationRate) {
    float a = 1.0;
    float chance = (float)rand()/(float)(RAND_MAX/a);
    for (uint8_t i = 0; i < MAX_GENOME; i++)
        if (chance <= mutationRate) {
            uint8_t mutatedGene = randr(0, MAX_GENOME - 1);
            ind->genes[mutatedGene] = inverse(ind->genes[mutatedGene]);
        }
}

void getFittest(population pop, individual * best, uint8_t populationSize) {
    uint16_t bestFV = pop[0]->fitnessValue;
    int bestIdx = 0;
    for (uint8_t i = 1; i < populationSize; i++) {
        if (pop[i]->fitnessValue < bestFV) {
            bestFV = pop[i]->fitnessValue;
            bestIdx = i;
        }
    }
    *best = *pop[bestIdx];
}

void calcFitness(individual * ind, genome g) {
    uint16_t _ind, _gen;

    _ind = strtol(ind->genes, NULL, 2);
    _gen = strtol(g, NULL, 2);

    ind->fitnessValue = _ind ^ _gen;
}
