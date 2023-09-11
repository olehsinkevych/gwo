#include <stdlib.h>
#include <math.h>
#include "gwo.h"
#include "wolves_pack.h"
#include "utils.h"

#define ROLES 3
#define A 2 // upper bound for a value


void updateAlphaBetaDeltaPosition(wolvesPack* pack)
{
    // calculate fitness function
    double avg = 0;
    for (int i=0; i<pack->populationSize; ++i)
    {
        double func = pack->f(pack->solution[i], pack->dimension);
        pack->fitnessValues[i] = func;
        avg += func;
    }
    // sort fitness values and obtain corresponding indices (starting from worst)
    getIndicesSortedOneDimArray(pack->fitnessIndices, pack->fitnessValues, pack->populationSize);

    pack->alphaIndex = pack->fitnessIndices[pack->populationSize-1];
    pack->betaIndex = pack->fitnessIndices[pack->populationSize-2];
    pack->deltaIndex = pack->fitnessIndices[pack->populationSize-3];
    // update alpha, beta and delta wolf fitness values
    pack->alphaScore = pack->fitnessValues[pack->alphaIndex];
    pack->betaScore = pack->fitnessValues[pack->betaIndex];
    pack->deltaScore = pack->fitnessValues[pack->deltaIndex];
    pack->avgScore = avg/pack->populationSize;
};

void vectorA(double vector_a[], double a)
{
    //Generates vector A = 2*a*r1 - a
    double r1;
    for (int i=0; i<ROLES; ++i)
    {
        r1 = getRandomFloat(0, 1);
        vector_a[i] = 2*a*r1 - a;
    }
};

void vectorC(double vector_c[])
{
    //Generates vector C = 2*r2
    double r2;
    for (size_t i=0; i<ROLES; ++i)
    {
        r2 = getRandomFloat(0, 1);
        vector_c[i] = 2*r2;
    }
};

void vectorD(double d[], const double c[], const double rolePosition[], double x)
{
    for (size_t i=0; i<ROLES; ++i)
    {
        d[i] = fabs(c[i]*rolePosition[i] - x);
    }
};

double vectorX(double x[], const double rolePosition[], const double a[],
               const double d[])
{
    for (size_t i=0; i<ROLES; ++i)
    {
        x[i] = rolePosition[i] - a[i]*d[i];
    }
};

void verifyBounds(double* x, double lBound, double uBound)
{
    if (*x < lBound) {
        *x = lBound;
    }
    if (*x  > uBound) {
        *x =  uBound;
    }
};

void calculateLeaders(wolvesPack* pack, double x[], double a, int dim, int sol)
{
    double* vector_a = (double *) calloc(ROLES, sizeof(double));
    double* vector_c = (double *) calloc(ROLES, sizeof(double));
    double* vector_d = (double *) calloc(ROLES, sizeof(double));
    // Vector A update
    vectorA(vector_a, a);
    // Vector C update
    vectorC(vector_c);
    // D_alpha, D_beta, D_delta (D) update
    double rolePosition[ROLES] = {pack->solution[pack->alphaIndex][dim],
                                  pack->solution[pack->betaIndex][dim],
                                  pack->solution[pack->deltaIndex][dim]};
    vectorD(vector_d, vector_c, rolePosition,
            pack->solution[sol][dim]);
    // X1, X2, X3 update
    vectorX(x, rolePosition, vector_a, vector_d);
    free(vector_a);
    free(vector_c);
    free(vector_d);
};

void makeStepWolfPack(wolvesPack* pack)
{
    // Allocate vectors A, C, D_alpha, D_beta, D_delta and X1..X3
    double* vector_x = (double *) calloc(ROLES, sizeof(double));
    double* xGWO = (double *) calloc(pack->dimension, sizeof(double));

    // Solution update loop
    for (int j = 0; j < pack->populationSize; ++j) {
        // Iterate over dimensions
        for (int k = 0; k < pack->dimension; ++k) {
            calculateLeaders(pack, vector_x, pack->a, k, j);
            double value = 0.0;
            for (int t = 0; t < ROLES; ++t) {
                value += vector_x[t];
            }
            value /= ROLES;
            verifyBounds(&value, pack->lowerBounds[k], pack->upperBounds[k]);
            xGWO[k] = value;
        } // dimension loop
        if (pack->f(xGWO, pack->dimension) < pack->fitnessValues[j])
        {
            for (int k = 0; k < pack->dimension; ++k){
                pack->solution[j][k] = xGWO[k];
            }
        }
    } // population loop
    // Release memory for vectors
    updateAlphaBetaDeltaPosition(pack);
    free(vector_x);
};

void runGWO(wolvesPack* pack, int maxCycles)
{
    /*Main function to run grey wolf optimization.
    * Holds classic GWO implementation.*/
    // Get alpha, beta and delta wolves
    updateAlphaBetaDeltaPosition(pack);
    // Main loop
    for (size_t i = 0; i < maxCycles; ++i) {
        // Set linearly decreasing a from [2..0]
        double a =  A - (double) i * ((double) A / maxCycles);
        pack->a = a;
        makeStepWolfPack(pack);
    } // Main loop
}; //runGWO()
