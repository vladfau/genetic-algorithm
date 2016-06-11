#include <stdlib.h>
#include "env.h"

int main() {
    printf("Builds\n");
	cfg_t a = {0};
	configureGA(&a);
	printf("Initial population: %d\nCrossing point: %d\nUniform rate: %f\nMutation rate: %f\n", a.initialPopulation, a.crossingPoint, a.uniformRate, a.mutationRate);
	return 0;
}
