#include <time.h>
#include "util.h"

#include "env.h"
#include "population.h"

int main() {
    srand(time(NULL));
    cfg_t cfg = {0};
    configureGA(&cfg);
    printf("Initial population: %d\nUniform rate: %f\nMutation rate: %f\n"
            , cfg.initialPopulation
            , cfg.uniformRate
            , cfg.mutationRate);

    genome g[MAX_GENOME];
    getFromEnv("TG", g, MAX_GENOME);

    printf("Target Genome: %s\n", g);
    population p = createPopulation(cfg.initialPopulation);
    for (uint8_t i = 0; i < cfg.initialPopulation; i++) {
        calcFitness(&p[i], g);
        printf("%s (fit: %d)\n", p[i].genes, p[i].fitnessValue);
    }
    return 0;
}
