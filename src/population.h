#pragma once
#include <malloc.h>
#include <stdbool.h>

#include "util.h"
#include "env.h"


typedef char * genome;

struct ind {
    genome genes;
    uint16_t fitnessValue;
};

typedef struct ind individual;
typedef individual ** population;

individual * createIndividual(bool generate);

population createPopulation(uint16_t size, bool generate);

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

void getFittest(population pop,
        individual * best,
        uint8_t populationSize);

void calcFitness(individual * ind, genome g);
