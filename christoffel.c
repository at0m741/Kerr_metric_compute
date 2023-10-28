#include <stdio.h>
#include <gsl/gsl_math.h>
#include <math.h>
#include "header1.h"

double function(double x) 
{
    return x * x;
}

double partial_derivative(double x, double h) 
{
    double df = (function(x + h) - function(x)) / h;

    return df;
}

double christoffel_g_rr(double r, int a, double M)
{
    double g_rr_cris = 1/r + (M -r) / kerr_delta(r, M, a);
    printf("g_rr_cris = %lf\n", g_rr_cris);

    return g_rr_cris;
}

double christoffel_g_tt(double M, double r, int a)
{
    double g_tt_cris = (M * a * kerr_delta(r, M, a)) / gsl_pow_4(r);
    printf("g_tt_cris = %lf\n", g_tt_cris);

    return g_tt_cris;
}
