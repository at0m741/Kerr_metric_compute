#include "header1.h"
#include <stdlib.h>

int main(int argc, char **argv) 
{
    if (argc != 2) {
        printf("Usage: %s <value_of_r>\n", argv[0]);
        return 1;
    }

    double r = atof(argv[1]);
    if (r < 0)
    {   
        printf("La coordonnée radiale r ne peut pas etre négative\n");
        return -1;
    }
    
    double a = 1;
    double theta = M_PI / 2.0;
    double Msun = 1.988e30;
    double M = 4.31e6 * Msun;
    double c = 299792458.0;  // m/s
    const double G = 6.67430e-11;  // m³ kg⁻¹ s⁻²
    double A = horizon_A(r, a ,M);
    double delta = kerr_delta(r, M, a);
    double Rs = schwarz_radius(G, M, c);


    if(r == Rs)
    {
        printf("L'observateur se trouve sur l'horizon des evenements.\n");
    }
    if (r == Rs/2)
    {
        printf("Le trou noir comporte une singularité nue.\n");
    }
    

    double g_rr = kerr_metric_g_rr(r, a, theta);
    double g_rr2 = kerr_metric_g_rr2(r, M, a);
    double g_tt = kerr_metric_g_tt(r, M);
    double g_tt2 = kerr_metric_gtt2(r, a, M);
    double g_tp = kerr_metric_g_tp(r, M, a);
    double g_tp2 = kerr_metric_g_tp2(r, M, a);
    double g_pp = kerr_metric_g_pp(r, A);
    double g_pp2 = kerr_metric_g_pp2(r, M, delta);
    double g_thth = kerr_metric_g_thth(r, a, theta);

    printf("\n");

    printf("--Calcul du rayon de Schwarzschild en fonction de M--\n\n");
    printf("Rs = %lf m\n\n", Rs);
    printf("-----Calcul des composants de la metrique de Kerr-----\n\n");

    printf("La signature de la metrique est la suivante (-+++)\n\n");

    if (g_rr < 0)
    {
        printf("A cette valeur de r, ce composant indique l'horizon des evenements.\n\n");
    }
    if (r == 0)
    {
        printf("Si r = 0, l'observateur se trouve au centre du trou noir en présence d'une singularité gravitationnelle.\n");
        printf("g^{rr} = %f\n", g_rr);
        printf("g^{rr} = %f\n", g_rr2);
        printf("g_{tt} = %f s^2/m2\n", g_tt);
        printf("g^{tt} = %f s^2/m^2\n", g_tt2);
        printf("g_{tp} = %f s/m\n", g_tp);                
        printf("g^{tp} = %f s/m\n", g_tp2);
        printf("g_{pp} = %f s^2/m\n", g_pp);
        printf("g^{pp} = %f s^2/m\n", g_pp2);
        printf("g_{thth} = %f\n", g_thth);
    }
    
    else
    {
        printf("g_{rr} = %f\n", g_rr);
        printf("g^{rr} = %f\n", g_rr2);
        printf("g_{tt} = %f s^2/m2\n", g_tt);
        printf("g^{tt} = %f s^2/m^2\n", g_tt2);
        printf("g_{tp} = %f s/m\n", g_tp);                
        printf("g^{tp} = %f s/m\n", g_tp2);
        printf("g_{pp} = %f s^2/m\n", g_pp);
        printf("g^{pp} = %f s^2/m\n", g_pp2);
        printf("g_{thth} = %f\n ", g_thth);
    }

    printf("\n");
    printf("(si g^{tt} = inf, cela veut dire que l'observateur se trouve derrière l'horizon des événements.)\n\n");
    if (r < Rs)
    {
        printf("r < Rs, l'observateur se trouve à l'interieur de l'horizon des evenements.\n\n");
    }
    printf("-----------Kerr-Boyer-Lindquist Matrix----------\n\n");

    double result = kerr_matrix_boyer_lindquist(r, M, theta, a, kerr_sigma(r, a, theta));
    printf("g[3][3] = %lf\n", result);


    printf("-----------Geodesics related computes-----------\n\n");

    double sigma = kerr_sigma(r, a, theta);
    double L = Angular_momentum(r, a, delta);
    double time = time_eq(a,delta, r, M, theta, c);
    double E = kerr_energy(a, r, M, A, theta, delta);
    double Q = carter_Q(a, theta, r, delta);
    double dr = kerr_dr(delta, sigma, r, E, a, Q, L);

    printf("Sigma = %f\n", sigma);
    printf("Delta = %f\n", delta);
    printf("E = %f\n", E);
    printf("dt = %f\n", time);
    printf("Q = %f\n", Q);
    printf("dr = %f\n\n", dr);
    printf("L = %f\n\n", L);

    printf("--------------------computes--------------------\n\n");

    double partial_grr = cristofell_g_rr(r, M, time);
    double partial_gtt = cristofell_g_tt(r, M);

    printf("La dérivée de g^{rr} à r = %lf est : %lf\n", r, partial_grr);
    printf("La dérivée de g^{tt} à r = %lf est : %lf\n", r, partial_gtt);
    

    FILE *gnuplot = popen("gnuplot -persistent", "w");
    fprintf(gnuplot, "set title 'Kerr Metric Components'\n");
    fprintf(gnuplot, "set xlabel 'r'\n");
    fprintf(gnuplot, "set ylabel 'Metric component'\n");
    fprintf(gnuplot, "set xrange [-1:6]\n");
    fprintf(gnuplot, "set yrange [-1e38:1.5e38]\n");
    fprintf(gnuplot, "plot '-' with lines linewidth 1.5 title 'g_{rr}', '-' with lines linewidth 2 title 'g_{tt}', '-' with lines linewidth 2 title 'g_{tp}', '-' with lines linewidth 2 title 'g_{pp}', '-' with lines linewidth 2 title 'g_{thth}', '-' with lines linewidth 2 title 'Rs', '-' with lines linewidth 2 title 'r'\n");    
    for (double r = -1; r <= 10; r += 0.1) {
        fprintf(gnuplot, "%lf %lf\n", r, kerr_metric_g_rr(r, a, theta));
    }
    fprintf(gnuplot, "e\n");
    for (double r = 0; r <= 10; r += 0.1) {
        fprintf(gnuplot, "%lf %lf\n", r, kerr_metric_g_tt(r, M));
    }
    fprintf(gnuplot, "e\n");
    for (double r = 0; r <= 10; r += 0.1) {
        fprintf(gnuplot, "%lf %lf\n", r, kerr_metric_g_tp(r, M, a));
    }
    fprintf(gnuplot, "e\n");
    for (double r = 0; r <= 10; r += 0.1) {
        fprintf(gnuplot, "%lf %lf\n", r, kerr_metric_g_pp(r, A));
    }
    fprintf(gnuplot, "e\n");
    for (double r = 0; r <= 10; r += 0.1) {
        fprintf(gnuplot, "%lf %lf\n", r, kerr_metric_g_thth(r, a, theta));
    }
    fprintf(gnuplot, "e\n");
    for (double r = 0; r <= 100; r += 0.1) {
        fprintf(gnuplot, "%lf\n", Rs);
    }
    fprintf(gnuplot, "e\n");
    for (double r = -1; r <= 10; r += 0.1) {
        fprintf(gnuplot, "%lf %lf\n", r, r);  // Ajoutez r en tant que première colonne
    }
    fprintf(gnuplot, "e\n");

    return 0;

}