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
    individual ind;
    getFittest(p, &ind, cfg.initialPopulation);
    printf("fittet: %s (fit: %d)\n", ind.genes, ind.fitnessValue);

    for (int i = 0; i < 100; i++) {
        mutate(&ind, 0.05);
        calcFitness(&ind, cfg.targetGenome);
        printf("mutation %i: %s (%d)\n", i, ind.genes, ind.fitnessValue);


    }

    individual * fr = p[0];
    individual * mr = p[1];
    for (int i = 0; i < 50; i++) {
    individual * child = createIndividual(false);
        crossover(fr, mr, child, 0.45);
        calcFitness(child, cfg.targetGenome);
        printf("child %d: %s (%d)\n", i, child->genes, child->fitnessValue);
    }


    return 0;
}
