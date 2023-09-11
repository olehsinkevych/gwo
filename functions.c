#include <math.h>
#include "functions.h"

double sphere(const double x[], int dim)
{
    double result = 0.0;
    for (int i=0; i<dim; ++i)
    {
        result += pow(x[i]-50, 2);
    }
    return result;
};

double step(const double x[], int dim)
{
    double result = 0.0;
    for (int i=0; i<dim; ++i)
    {
        result += pow(x[i]+0.5, 2);
    }
    return result;
};

double Rastrigin(const double x[], int dim)
{
    double result = 0.0;
    for (int i=0; i<dim; ++i)
    {
        result += (pow(x[i]-2, 2) - 10*cos(2*M_PI*(x[i]-2)) + 10);
    }
    return result;
};

double Schwefel(const double x[], int dim)
{
    double result = dim * 418.9829;
    double r = 0.0;
    for (int i=0; i<dim; ++i)
    {
        r += (x[i]*sin(sqrt(fabs(x[i]))));
    }
    return result - r;
};

double Griewank(const double x[], int dim)
{
    double r1 = 0.0;
    double r2 = 1.0;
    for (int i=0; i<dim; ++i)
    {
        r1 += pow(x[i]-10, 2);
        r2 *= cos((x[i]-10)/ sqrt(i+1));
    }
    return (1.0/4000)*r1 - r2 + 1;
};

double Rosenbrock(const double x[], int dim)
{
    double r = 0.0;
    for (int i=0; i<dim-1; ++i)
    {
        r += 100*pow((x[i+1]) - pow(x[i], 2), 2) + pow(x[i] - 1, 2);

    }
    return r;
};

double Ackley(const double x[], int dim)
{
    double r1 = 0.0;
    double r2 = 0.0;
    for (int i=0; i<dim; ++i)
    {
        r1 += pow(x[i]-10, 2);
        r2 += cos(2*M_PI*(x[i]-10));

    }
    return -20*exp(-0.2*(sqrt(r1/dim))) - exp(r2/dim) + 20 + exp(1);
};

double Kim1(const double x[], int dim)
{
    double result = sin(x[0]) + cos(x[1]) + 0.016*pow(x[0] - 5, 2) + 0.008*pow(x[1]-5, 2);
    return result;
};

double GramacyLee(const double x[], int dim)
{
    double result = sin(10*M_PI*x[0])/(2*x[0]) + pow(x[0]-1, 4);
    return result;
};

double Eggholder(const double x[], int dim)
{
    double result = -(x[1] + 47)*sin(sqrt(fabs(x[1]+0.5*x[0]+47))) -
            x[0]*sin(sqrt(fabs(x[0]-(x[1]+47))));
    return result;
};

double Easom(const double x[], int dim)
{
    double result = -cos(x[0])*cos(x[1])*exp(-pow(x[0]-M_PI, 2)-pow(x[1]-M_PI, 2));
    return result;
};

double Booth(const double x[], int dim)
{
    double result = pow(x[0]+2*x[1] - 7, 2) + pow(2*x[0]+x[1] - 5, 2);
    return result;
};

double Michalewicz(const double x[], int dim)
{
    double result = 0.0;
    for (int i=0; i<dim; ++i)
    {
        result -= sin(x[i])*pow(sin((i+1)*pow(x[i], 2)/M_PI), 10);
    }
    return result;
}