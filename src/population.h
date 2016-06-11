#pragma once
#include <malloc.h>

#include "util.h"
#include "env.h"


typedef char * genome;

struct ind {
    genome genes;
    uint16_t fitnessValue;
};

typedef struct ind individual;
typedef individual * population;

individual createIndividual();

population createPopulation(uint16_t size);

void evolve(population * pop,
        cfg_t * config,
        uint16_t counter);

void tournament(population * ancestors,
        population * successors,
        uint16_t tournamentSize);

void crossover(individual * father,
        individual * mother,
        individual * child,
        float uniformRate);

void mutate(individual * ind,
        float mutationRate);

void getFittest(population * pop,
        genome * g,
        individual * best);

void calcFitness(individual * ind, genome g);
