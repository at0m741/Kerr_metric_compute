#include "header1.h"

int main() 
{
    double r = 0;
    double a = 1.0;
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
        printf("composant g_rr negatif car r = 0 donc singularité.\n");
        printf("A cette valeur de r, ce composant indique l'horizon des evenements.\n\n");
    }
    if (g_tt < 0)
    {
        printf("r < 0, l'observateur se situe a l'interieur de l'horizon, donc g_{tt} < 0.\n\n");
        printf("g^{rr} = %f\n", g_rr);
        printf("g^{rr} = %f\n", g_rr2);
        printf("g_{tt} = %f\n", g_tt);
        printf("g^{tt} = %f\n", g_tt2);
        printf("g_{tp} = %f\n", g_tp);                
        printf("g^{tp} = %f\n", g_tp2);
        printf("g_{pp} = %f\n", g_pp);
        printf("g^{pp} = %f\n", g_pp2);
    }
    
    else
    {
        printf("g^{rr} = %f\n", g_rr);
        printf("g^{rr} = %f\n", g_rr2);
        printf("g_{tt} = %f\n", g_tt);
        printf("g^{tt} = %f\n", g_tt2);
        printf("g_{tp} = %f\n", g_tp);                
        printf("g^{tp} = %f\n", g_tp2);
        printf("g_{pp} = %f\n", g_pp);
        printf("g^{pp} = %f\n", g_pp2);
    }

    printf("\n");
    printf("(si g^{tt} = inf, cela veut dire que pour r, g^{tt} correspond à l'horizon.)\n");
    return 0;
}