#include "population.h"


individual createIndividual() {
    individual ind;
    char * g;
    g = malloc(sizeof(char) * MAX_GENOME + 1);
    for (uint8_t i = 0; i < MAX_GENOME; i++)
        if (rand() & 1) g[i] = '1'; else g[i] = '0';
    g[MAX_GENOME] = '\0';
    memcpy(&ind.genes, &g, sizeof(g));
    return ind;
}

population createPopulation(uint16_t size) {
    population newP = malloc(sizeof(individual) * size);
    for (uint16_t i = 0; i < size; i++) {
        individual ind = createIndividual();
        memcpy(&newP[i], &ind, sizeof(individual));
    }
    return newP;
}

void calcFitness(individual * ind, genome g) {
    uint16_t _ind, _gen;

    _ind = strtol(ind->genes, NULL, 2);
    _gen = strtol(g, NULL, 2);

    ind->fitnessValue = _ind ^ _gen;
}
