#ifndef SCS_NORMALIZE_H_GUARD
#define SCS_NORMALIZE_H_GUARD

#include "scs.h"


#define MIN_SCALE (1e-3)
#define MAX_SCALE (1e3)

void scs_normalize_bc(ScsWork *w) {
    scs_int i;
    scs_float nm, *D = w->scal->D, *E = w->scal->E, *b = w->b, *c = w->c;
    /* scale b */
    for (i = 0; i < w->m; ++i) {
        b[i] /= D[i];
    }
    nm = scs_norm(b, w->m);
    w->sc_b = w->scal->meanNormColA / MAX(nm, MIN_SCALE);
    /* scale c */
    for (i = 0; i < w->n; ++i) {
        c[i] /= E[i];
    }
    nm = scs_norm(c, w->n);
    w->sc_c = w->scal->meanNormRowA / MAX(nm, MIN_SCALE);
    scs_scale_array(b, w->sc_b * w->stgs->scale, w->m);
    scs_scale_array(c, w->sc_c * w->stgs->scale, w->n);
}

void scs_calculate_scaled_residuals(ScsWork *w, struct scs_residuals *r) {
    scs_float *D = w->scal->D;
    scs_float *E = w->scal->E;
    scs_float *u = w->u;
    scs_float *u_t = w->u_t;
    scs_float *u_prev = w->u_prev;
    scs_float tmp;
    scs_int i, n = w->n, m = w->m;

    r->res_pri = 0;
    for (i = 0; i < n; ++i) {
        tmp = (u[i] - u_t[i]) / (E[i] * w->sc_b);
        r->res_pri += tmp * tmp;
    }
    for (i = 0; i < m; ++i) {
        tmp = (u[i + n] - u_t[i + n]) / (D[i] * w->sc_c);
        r->res_pri += tmp * tmp;
    }
    tmp = u[n + m] - u_t[n + m];
    r->res_pri += tmp * tmp;
    r->res_pri = sqrt(r->res_pri);

    r->res_dual = 0;
    for (i = 0; i < n; ++i) {
        tmp = (u[i] - u_prev[i]) * E[i] / w->sc_b;
        r->res_dual += tmp * tmp;
    }
    for (i = 0; i < m; ++i) {
        tmp = (u[i + n] - u_prev[i + n]) * D[i] / w->sc_c;
        r->res_dual += tmp * tmp;
    }
    tmp = u[n + m] - u_t[n + m];
    r->res_dual += tmp * tmp;
    r->res_dual = sqrt(r->res_dual);
}

void scs_normalize_warm_start(ScsWork *w) {
    scs_int i;
    scs_float *D;
    scs_float *E;
    scs_float *x;
    scs_float *y;

    D = w->scal->D;
    E = w->scal->E;
    if (!w->stgs->do_super_scs) {
        scs_float *s;
        x = w->u;
        y = &(w->u[w->n]);
        s = &(w->u[w->n]);
        for (i = 0; i < w->m; ++i) {
            s[i] /= (D[i] / (w->sc_b * w->stgs->scale));
        }
    } else {
        x = w->u_t;
        y = &(w->u_t[w->n]);
    }
    for (i = 0; i < w->n; ++i) {
        x[i] *= (E[i] * w->sc_b);
    }
    for (i = 0; i < w->m; ++i) {
        y[i] *= (D[i] * w->sc_c);
    }
}

void scs_unnormalize_sol(ScsWork *w, ScsSolution *sol) {
    scs_int i;
    scs_float *D = w->scal->D;
    scs_float *E = w->scal->E;
    for (i = 0; i < w->n; ++i) {
        sol->x[i] /= (E[i] * w->sc_b);
    }
    for (i = 0; i < w->m; ++i) {
        sol->y[i] /= (D[i] * w->sc_c);
    }
    for (i = 0; i < w->m; ++i) {
        sol->s[i] *= D[i] / (w->sc_b * w->stgs->scale);
    }
}

#endif
