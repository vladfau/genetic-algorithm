#include <time.h>
#include "util.h"

#include "env.h"
#include "population.h"

int main() {
    srand(time(NULL));
    cfg_t cfg = {0};
    configureGA(&cfg);
    printf("Initial population: %d\nUniform rate: %f\nMutation rate: %f\nTarget genome: %s\n"
            , cfg.initialPopulation
            , cfg.uniformRate
            , cfg.mutationRate
            , cfg.targetGenome);

    population p = createPopulation(cfg.initialPopulation, true);
    for (uint8_t i = 0; i < cfg.initialPopulation; i++) {
        calcFitness(p[i], cfg.targetGenome);
        printf("%s (fit: %d)\n", p[i]->genes, p[i]->fitnessValue);
    }
    individual * ind = createIndividual(false);
    uint16_t counter = 0;
    evolve(p, &cfg, ind, counter);


    return 0;
}
