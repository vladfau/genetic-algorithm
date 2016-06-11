#include "population.h"


individual createIndividual() {
   individual ind;
   uint8_t * g = malloc(sizeof(uint8_t) * MAX_GENOME);
   for (uint8_t i = 0; i < MAX_GENOME; i++) {
        g[i] = rand() & 1;
   }
   ind.genes = g;
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

