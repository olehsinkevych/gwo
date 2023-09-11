#include "wolves_pack.h"

#ifndef GWO_H
#define GWO_H

void updateAlphaBetaDeltaPosition(wolvesPack * pack);
void vectorA(double vector_a[], double a);
void vectorC(double vector_c[]);
void vectorD(double [], const double [], const double [], double);
double vectorX(double [], const double [], const double [], const double []);
void verifyBounds(double *, double, double);
void calculateLeaders(wolvesPack*, double [], double, int, int);
void makeStepWolfPack(wolvesPack *);
void runGWO(wolvesPack *, int);
#endif //GWO_H
