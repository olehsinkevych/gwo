#include "utils.h"
#include <stdlib.h>


int getRandomInt(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;

};

double getRandomFloat(double lower, double upper)
{
    double num = lower + (double)rand()/(double)(RAND_MAX/upper);
    return num;

};

// ************* START CUSTOM SORTING 2D ARRAY BASED ON VALUES IN ANOTHER 1D *************

// Function to compare values in the 1D array during sorting
typedef struct {
    double value;
    int index;
} ValueIndexPair;

// Comparison function for qsort to sort ValueIndexPairs by their values
int compareValueIndexPair(const void *a, const void *b) {
    ValueIndexPair *pairA = (ValueIndexPair *)a;
    ValueIndexPair *pairB = (ValueIndexPair *)b;

    if (pairA->value > pairB->value) return -1;
    else if (pairA->value < pairB->value) return 1;
    return 0;
};

void getIndicesSortedOneDimArray(int * indices, const double* arr1D, int size)
{
    ValueIndexPair * str = (ValueIndexPair *)malloc(size*sizeof(ValueIndexPair));
    // Populate the value-index pairs with the values and corresponding indices
    for (int i = 0; i < size; ++i) {
        str[i].value = arr1D[i];
        str[i].index = i;
    }
    qsort(str, size, sizeof(str[0]), compareValueIndexPair);
    for (int i = 0; i < size; ++i)
        indices[i] = str[i].index;
};
// ************* END CUSTOM SORTING 2D ARRAY BASED ON VALUES IN ANOTHER 1D *************
