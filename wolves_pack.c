#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wolves_pack.h"
#include "utils.h"

void initializeWolvesPack(wolvesPack* pack, int populationSize, int dim,
                          double lBound, double  uBound,
                          double (*f)(const double [], int))
{
    // initialize and allocate memory
    pack->a = 2; // initial value of parameter a
    pack->populationSize = populationSize;
    pack->dimension = dim;
    pack->alphaScore = INFINITY;
    pack->betaScore = INFINITY;
    pack->deltaScore = INFINITY;
    pack->avgScore = INFINITY;
    pack->alphaIndex = 0; // default value
    pack->betaIndex = 0;
    pack->deltaIndex = 0;
    // dynamic memory allocation
    pack->upperBounds = (double*)malloc(dim*sizeof(double));
    pack->lowerBounds = (double*)malloc(dim*sizeof(double));
    pack->fitnessIndices = (int*)malloc(populationSize*sizeof(int));
    pack->fitnessIndicesReversed = (int*)malloc(populationSize*sizeof(int));
    pack->fitnessValues = (double*)malloc(populationSize*sizeof(double));
    pack->solution = (double**)malloc(populationSize*sizeof(double*));
    pack->f = f;
    for(int i=0; i<populationSize; ++i)
    {
        pack->solution[i] = (double*)malloc(dim*sizeof(double));
    }
    for(int i=0; i<dim; ++i)
    {
        pack->upperBounds[i] = uBound;
        pack->lowerBounds[i] = lBound;
    }
    for (int i=0; i<populationSize; ++i)
    {
        for (int j=0; j<dim; ++j)
        {
            double lb = pack->lowerBounds[j];
            double ub = pack->upperBounds[j];
            double fi = getRandomFloat(0, 1);
            pack->solution[i][j] = lb + fi*(ub - lb);
        }
    }
};

void printSolutions(wolvesPack pack)
{
    printf("Solution: \n[");
    for (int i=0; i<pack.populationSize; ++i)
    {
        for(int j=0; j<pack.dimension; ++j)
        {
            printf("%.4f", pack.solution[i][j]);
        }
        if (i==pack.populationSize-1)
        {
            printf("]");
        }
        printf("\n");
    }
};

void printFitness(wolvesPack pack)
{
    printf("Fitness values: \n[");
    for (int i=0; i<pack.populationSize; ++i)
    {
        printf("%.4f", pack.fitnessValues[i]);

        if (i==pack.populationSize-1)
        {
            printf("]");
        }
        printf("\n");
    }
    for (int i=0; i<pack.populationSize; ++i)
    {
        printf("Fitness index [%d] %d", i, pack.fitnessIndices[i]);
        printf("\n");
    }
};

void printBest(wolvesPack pack)
{
    printf("Best fitness by far = %.4f\n", pack.alphaScore);
    printf("Best solution found by far:\n");
    printf("[");
    for (int i=0; i<pack.dimension; ++i)
    {
        if (i == pack.dimension-1)
        {
            printf("%.4f]", pack.solution[pack.alphaIndex][i]);
        }
        else
        {
            printf("%.4f\n", pack.solution[pack.alphaIndex][i]);
        }
    }
}