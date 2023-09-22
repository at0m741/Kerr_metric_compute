#include "header1.h"
#include <gsl/gsl_math.h>
#include <math.h>

double carter_p(double r, int a, int theta, double delta)
{
    double angle_degrees = 30.0;
    double angle_radians = angle_degrees * M_PI / 180.0;
    double cos_squared = pow(cos(angle_radians), 2);

    double P = (gsl_pow_2(r) + gsl_pow_2(a) * cos_squared * (theta)) / delta;

    return P;
}

double carter_Q(int a, int theta, double r, double delta)
{
    double angle_degrees = 30.0;
    double angle_radians = angle_degrees * M_PI / 180.0;
    double cos_squared = pow(cos(angle_radians), 2);

    double Q = gsl_pow_2(carter_p(r, a, theta, delta)) - gsl_pow_2(a) * cos_squared * (theta);

    return Q;
}

double kerr_sigma(double r, int a, int theta)
{
    double angle_degrees = 30.0;
    double angle_radians = angle_degrees * M_PI / 180.0;
    double cos_squared = pow(cos(angle_radians), 2);

    double sigma = gsl_pow_2(r) + gsl_pow_2(a) * cos_squared * (theta);

    return sigma;
}

double Az_var(double a, double delta)
{
    double dp = a / delta;

    return dp;
}

double Angular_momentum(double r, double a, double delta)
{
    double L = ((gsl_pow_2(r) + gsl_pow_2(a)) / delta) * Az_var(a, delta);

    return L;
}

double phi_dot(int a, double r, int theta, double delta)
{
    double dphi_dot = Angular_momentum(r, a , delta) / kerr_sigma(r, a , theta);

    return dphi_dot;
}

double t_dot(int a, double r, double M, double A, int theta, double delta)
{
    double tdot = 1 / sqrt((-kerr_metric_g_tt(r, M) - kerr_metric_g_pp(r, A) * phi_dot(a, r, theta, delta)));

    return tdot;
}

double kerr_energy(int a, double r, double M, double A, int theta, double delta)
{
    double E = - (kerr_metric_g_tt(r, M) * t_dot(a, r, M, A, theta, delta)) / sqrt(- kerr_metric_g_tt(r, M) - kerr_metric_g_pp(r, A) * gsl_pow_2(phi_dot(a, r, theta, delta)));

    return E; 
}


double time_eq(double a, double delta, double r, double M, int theta, double A)
{
    double angle_degrees = 45.0; 
    double angle_radians = angle_degrees * M_PI / 180.0;
    double sin_squared = pow(sin(angle_radians), 2);

    double dt = (1 / kerr_metric_g_tt(r, M)) * (kerr_energy(a, r, M, A, theta, delta) - (a * Angular_momentum(r, a , delta)) / sin_squared * (theta));

    return dt;
}

double kerr_dr(double delta, double sigma, double r, double E, int a, double Q, double L)
{
    double Vr = (delta / sigma) * gsl_pow_2((gsl_pow_2(r) + gsl_pow_2(a)) * E - a * L) - delta * ((gsl_pow_2(r) + gsl_pow_2(a)) * gsl_pow_2(L) - Q);
    double dr = gsl_pow_2(E) - Vr;

    return dr;
}

double dtheta(double L, int theta, int a, double r)
{
    double angle_degrees = 45.0; 
    double angle_radians = angle_degrees * M_PI / 180.0;
    double sin_squared = pow(sin(angle_radians), 2);

    double dtheta = 1 / kerr_metric_g_thth(r, a, theta) * (L / sin_squared * (theta));

    return dtheta;
}

double dphi(double L, int theta, int a, double r, double E, double sigma, double delta, double Q, double A)
{
    double angle_degrees = 45.0; 
    double angle_radians = angle_degrees * M_PI / 180.0;
    double sin_squared = pow(sin(angle_radians), 2);

    double dphi = 1 / kerr_metric_g_pp(r, A) * ((a * E - (gsl_pow_2(r) + gsl_pow_2(a)) * L) / sin_squared *(theta)) + (((2 * a) / kerr_metric_g_pp(r, A)) * kerr_dr(delta, sigma, r, E, a, Q, L));

    return dphi;
}

