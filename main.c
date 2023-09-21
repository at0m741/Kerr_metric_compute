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

    double a = 0.9;
    double theta = M_PI / 2.0;
    double Msun = 1.988e30;
    double M = 4.31e6 * Msun;
    double c = 299792458.0;  // m/s
    const double G = 6.67430e-11;  // m³ kg⁻¹ s⁻²
    double A = horizon_A(r, a ,M);
    double delta = kerr_delta(r, M, a);

    double Rs = schwarz_radius(G, M, c);
    double g_rr = kerr_metric_g_rr(r, a, theta);
    double g_rr2 = kerr_metric_g_rr2(r, M, a);
    double g_tt = kerr_metric_g_tt(r, M);
    double g_tt2 = kerr_metric_gtt2(r, a, M);
    double g_tp = kerr_metric_g_tp(r, M, a);
    double g_tp2 = kerr_metric_g_tp2(r, M, a);
    double g_pp = kerr_metric_g_pp(r, A);
    double g_pp2 = kerr_metric_g_pp2(r, M, delta);
    

    printf("\n");

    printf("--Calcul du rayon de Schwarzschild en fonction de M--\n\n");
    printf("Rs = %lf m\n\n", Rs);

    printf("-----Calcul des composants de la metrique de Kerr-----\n\n");

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
    }
    
    else
    {
        printf("g^{rr} = %f\n", g_rr);
        printf("g^{rr} = %f\n", g_rr2);
        printf("g_{tt} = %f s^2/m2\n", g_tt);
        printf("g^{tt} = %f s^2/m^2\n", g_tt2);
        printf("g_{tp} = %f s/m\n", g_tp);                
        printf("g^{tp} = %f s/m\n", g_tp2);
        printf("g_{pp} = %f s^2/m\n", g_pp);
        printf("g^{pp} = %f s^2/m\n", g_pp2);
    }

    printf("\n");
    printf("(si g^{tt} = inf, cela veut dire que pour r, g^{tt} correspond à l'horizon.)\n");
    return 0;
}
