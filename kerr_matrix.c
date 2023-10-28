#include <stdio.h>
#include <gsl/gsl_math.h>
#include <math.h>
#include "header1.h"

double kerr_matrix_boyer_lindquist(double r, double M, int theta, int a, double p) {
    double g[4][4] = {
        {kerr_metric_g_tt(r, M), 0, 0, 0},
        {0, kerr_metric_g_rr(r, a, theta), 0, 0},
        {0, 0, kerr_metric_g_thth(r, a, theta), 0},
        {0, 0, 0, kerr_metric_g_pp(r, p)}
    };

    // Affichage de la matrice g
    printf("Matrix g:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%lf\t", g[i][j]);
        }
        printf("\n");
    }

    return g[4][4];
}

double photon_radius(double M, double a) {
    double r_photon = 2 * M * (1 + cos(2/3 * acos(-a / M)));

    return r_photon;
}