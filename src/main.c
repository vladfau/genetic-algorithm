#include <time.h>
#include "util.h"

#include "env.h"
#include "population.h"

int main() {
    printf("Builds\n");
    srand(time(NULL));
/**	cfg_t a = {0};
	configureGA(&a);
	printf("Initial population: %d\nCrossing point: %d\nUniform rate: %f\nMutation rate: %f\n", a.initialPopulation, a.crossingPoint, a.uniformRate, a.mutationRate);
    **/
    population p = createPopulation(20);
    for (uint8_t i = 0; i < 20;i++) {
        print_str(p[i].genes);
        printf("\n");
    }
	return 0;
}
