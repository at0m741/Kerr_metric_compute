#ifndef HEADER1_H
# define HEADER1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_math.h>
#include <math.h>

//Kerr Metric components

double kerr_delta(double r, double M, double a);
double horizon_A(double r, double a, double M);
double kerr_metric_g_rr(double r, double a, double theta);
double kerr_metric_g_rr2(double r, double M, double a);
double kerr_metric_g_tt(double r, double M);
double kerr_metric_gtt2(double r, int a, double M);
double kerr_metric_g_tp(double r, double M, int a);
double kerr_metric_g_tp2(double r, double M, int a);
double kerr_metric_g_pp(double r, double A);
double kerr_metric_g_pp2(double r, double M, double delta);
double kerr_metric_g_thth(double r, int a, double theta);
double schwarz_radius(double G, double M, double c);

//Kerr Metric components in Boyer-Lindquist coordinates

double kerr_matrix_boyer_lindquist(double r, double M, int theta, int a, double p);
//Geodesics related equations

double kerr_energy(int a, double r, double M, double A, int theta, double delta); 
double carter_Q(int a, int theta, double r, double delta);
double kerr_sigma(double r, int a, int theta);
double Az_var(double a, double delta);
double Angular_momentum(double r, double a, double delta);
double time_eq(double a, double delta, double r, double M, int theta, double c);  // verifier le calcul (possible singularité de coordonnées on cohérente)
double kerr_dr(double delta, double sigma, double r, double E, int a, double Q, double L);
double dtheta(double L, int theta, int a, double r);
double dphi(double L, int theta, int a, double r, double E, double sigma, double delta, double Q, double A);

//partital derivatives

double function(double x);
double partial_derivative(double x, double h);
double cristofell_g_rr(double r, int a, double theta);
double cristofell_g_tt(double r, double M);

//Matrix
typedef struct {
    double **matrix;
    int rows;
    int cols;
} Matrix;

#endif
