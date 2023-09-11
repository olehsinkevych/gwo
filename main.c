
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wolves_pack.h"
#include "gwo.h"
#include "functions.h"

/* Control Parameters of GWO algorithm */
const int solutionNumber = 10;
const int dimension = 5;
const int maxCycles = 100;
const double lowerBound = -32;
const double upperBound = 32;

int main(void)
{
    time_t start, stop;
    srand(time(NULL));
    start = time(NULL);

    wolvesPack pack;
    initializeWolvesPack(&pack, solutionNumber, dimension,
                       lowerBound, upperBound, Ackley);
    runGWO(&pack, maxCycles);
    stop = time(NULL);
    printf("The number of seconds for loop to run was %ld\n", stop - start);
    printBest(pack);
    printf("\n");
    printFitness(pack);
    return 0;
}
