#include <stdio.h>
#include <gsl/gsl_math.h>
#include <math.h> 

#include "header1.h"

double kerr_delta(double r, double M, double a)
{
    double delta = gsl_pow_2(r) - 2 * M * r + gsl_pow_2(a);

    return delta;
}

double horizon_A(double r, double a, double M)
{
    double A = gsl_pow_4(r) + gsl_pow_2(r) * gsl_pow_2(a) + 2 * M * r * gsl_pow_2(a);

    return A;
}


double kerr_metric_g_rr(double r, double a, double theta) {
    double Sigma = r * r + a * a * gsl_pow_2(cos(theta));
    double Delta = r * r - 2.0 * r * a + a * a;

    return Delta / Sigma;
}

double kerr_metric_g_rr2(double r, double M, double a)
{
    double g_rr2 = kerr_delta(r, M, a) / gsl_pow_2(r);

    return g_rr2;
}

double kerr_metric_g_tt(double r, double M)
{
    double gtt =  -(r - 2 * M) / r;

    return gtt;
}

double kerr_metric_gtt2(double r, int a, double M)
{
    double A = horizon_A(r, a, M);
    double delta = kerr_delta(r, M, a);
    double gtt2 = - A / gsl_pow_2(r) * delta;

    if(gtt2 <= 0)
        return -1;

    return gtt2;
}

double kerr_metric_g_tp(double r, double M, int a)
{
    double g_tp =  - (2 * M * a) / r;
    
    return g_tp;
}

double kerr_metric_g_tp2(double r, double M, int a)
{
    double g_tp2 = (2 * M * a) / r * kerr_delta(r, M, a);

    return g_tp2;
}

double kerr_metric_g_pp(double r, double A)
{
    double g_pp = A / gsl_pow_2(r);

    return g_pp;
}

double kerr_metric_g_pp2(double r, double M, double delta)
{
    double g_pp2 = (r-2*M) / r * delta;

    return g_pp2;
}

double schwarz_radius(double G, double M, double c)
{
    double Rs = (2 * G * M) / gsl_pow_2(c);

    return Rs; 
}