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

double cristofell_g_rr(double r, int a, double M)
{
    double g_rr_cris = 1/2 * kerr_metric_g_rr2(r, M, a) * (partial_derivative(kerr_metric_g_rr2(r, M, a), r));

    if(g_rr_cris <= 0)
        return -1;

    return g_rr_cris;
}

double cristofell_g_tt(double r, double M)
{
    double g_tt_cris = 1/2 * kerr_metric_g_tt(r, M) * (partial_derivative(kerr_metric_g_tt(r, M), r));

    if (g_tt_cris <= 0)
        return -1;

    return g_tt_cris;
}

