
#ifndef GWO_WOLVES_PACK_H
#define GWO_WOLVES_PACK_H

typedef struct {
    double a;                          // initial value of GWO parameter a
    int populationSize;                // number of solutions
    int dimension;                     // problem dimension
    double alphaScore;                 // best fitness (alpha leader)
    double betaScore;                  // second-best fitness (beta leader)
    double deltaScore;                 // third-best fitness (delta leader)
    double avgScore;                   // average leaders fitness
    int alphaIndex;                    // idx of alpha position (the best solution)
    int betaIndex;                     // idx of beta position (2nd best)
    int deltaIndex;                    // idx of delta position (3rd best)
    double* lowerBounds;               // vector of lower bounds
    double* upperBounds;               // vector of upper bounds
    int* fitnessIndices;               // sorted fitness indices
    int* fitnessIndicesReversed;       // reverse sorted fitness indices
    double* fitnessValues;             // fitness values related to solutions
    double** solution;                 // 2d array of solutions (popSize x dim)
    double (*f)(const double [], int); // function by pointer to optimize
} wolvesPack;

void initializeWolvesPack(wolvesPack* pack, int populationSize, int dim,
                          double lBound, double uBound,
                          double (*f)(const double [], int));
void printSolutions(wolvesPack pack);
void printFitness(wolvesPack pack);
void printBest(wolvesPack pack);
#endif //GWO_WOLVES_PACK_H
