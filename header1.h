#ifndef HEADER1_H
# define HEADER1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_math.h>
#include <math.h>

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
double schwarz_radius(double G, double M, double c);

#endif