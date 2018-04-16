#include "scs.h"
#include "normalize.h"
#include "directions.h"
#include "linsys/amatrix.h"
#include <time.h>

#ifndef EXTRAVERBOSE
/* if verbose print summary output every this num iterations */
#define SCS_PRINT_INTERVAL 100
/* check for convergence every this num iterations */
#define SCS_CONVERGED_INTERVAL 1
#else
#define SCS_PRINT_INTERVAL 1
#define SCS_CONVERGED_INTERVAL 1
#endif

/* tolerance at which we declare problem indeterminate */
#define SCS_INDETERMINATE_TOL 1e-9

timer scs_global_timer;

/* printing header */
static const char *SCS_HEADER[] = {
    " Iter ", " pri res ", " dua res ", " rel gap ",
    " pri obj ", " dua obj ", " kap/tau ", "   FPR   ", " time (s)"
};
static const scs_int SCS_HSPACE = 9;
static const scs_int SCS_HEADER_LEN = 9;
static const scs_int SCS_HEADER_LINE_LEN = 87;

static scs_int scs_isnan(scs_float x) {
    return (isnan(x)); /* `isnan` works both for `float` and `double` types */
}

static DirectionCache * scs_init_direction_cache(scs_int memory, scs_int l, scs_int print_mode, ScsDirectionType dir_type) {
    DirectionCache * RESTRICT cache = scs_calloc(1, sizeof (*cache));
    scs_int length_S = 0, length_U = 0, length_S_minus_U = 0, length_t = 0, length_ws = 0;


    if (cache == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: allocating YSCache failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }

    cache->ls_wspace_length = 0;
    cache->current_mem = 0;

    switch (dir_type) {
        case restarted_broyden:
        case restarted_broyden_v2:
            /* we allocate one extra memory position because it's needed */
            length_S = (1 + memory) * l;
            length_U = (1 + memory) * l;
            break;
        case anderson_acceleration:
            length_S = memory * l;
            length_U = memory * l;
            length_S_minus_U = memory * l;
            /* -----------------------------------------------------------------
             * Although t is a vector of dimension 'memory', we allocate space
             * of length 'l' because we first need to store the residual 'R'
             * therein (see directions.c: scs_compute_dir_anderson).
             * Note: we give some additional space because the BLAS documentation
             * says that we should give **at least** this much memory.
             * ----------------------------------------------------------------- */
            length_t = l;
#ifdef SVD_ACTIVATED
            cache->ls_wspace_length = 1000 + scs_svd_workspace_size(l, memory);
            /* -----------------------------------------------------------------
             * In Anderson's acceleration, we solve a least squares problem
             * using lapack's SVD-based 'sgelss' (see svdls). This requires a
             * workspace whose size is given by 'cache->ls_wspace_length' (above).
             * To that we add another 'memory' memory positions to store the
             * singular values of the LHS matrix and another 'l*memory'
             * memory positions to make a copy of the Y-cache; this is
             * because 'sgelss' modified the LHS (i.e., the Y-cache).
             * ----------------------------------------------------------------- */
            length_ws = (cache->ls_wspace_length) + memory * (1 + l);
#else
            cache->ls_wspace_length = 1000 + scs_qr_workspace_size(l, memory);
            /* -----------------------------------------------------------------
             * In Anderson's acceleration, we solve a least squares problem
             * using lapack's SVD-based 'sgelss' (see svdls). This requires a
             * workspace whose size is given by 'cache->ls_wspace_length' (above).
             * To that we add another 'l*memory'
             * memory positions to make a copy of the Y-cache; this is
             * because 'sgelss' modified the LHS (i.e., the Y-cache).
             * ----------------------------------------------------------------- */
            length_ws = (cache->ls_wspace_length) + memory * l;
#endif
            break;
        default:
            break;
    }

    cache->S = scs_malloc(length_S * sizeof (scs_float));
    cache->U = scs_malloc(length_U * sizeof (scs_float));
    cache->S_minus_Y = scs_malloc(length_S_minus_U * sizeof (scs_float));
    cache->t = scs_malloc(length_t * sizeof (scs_float));
    cache->ls_wspace = scs_malloc(length_ws * sizeof (scs_float));

    /* the cache must know its memory length */
    cache->mem = memory;

    /* initial active memory is 0 */
    scs_reset_direction_cache(cache);
    return cache;
}

static void scs_free_direction_cache(DirectionCache * RESTRICT cache) {
    if (cache == SCS_NULL)
        return;
    scs_free(cache->S);
    scs_free(cache->U);
    scs_free(cache->S_minus_Y);
    scs_free(cache->t);
    scs_free(cache->ls_wspace);
    scs_free(cache);
}

static void scs_free_work(ScsWork * RESTRICT w) {
    if (w == SCS_NULL) return;
    scs_free(w->u);
    scs_free(w->v);
    scs_free(w->u_t);
    scs_free(w->u_prev);
    scs_free(w->h);
    scs_free(w->g);
    scs_free(w->b);
    scs_free(w->c);
    scs_free(w->pr);
    scs_free(w->dr);
    if (w->scal != SCS_NULL) {
        scs_free(w->scal->D);
        scs_free(w->scal->E);
        scs_free(w->scal);
    }
    scs_free(w->u_b);

    if (w->stgs->do_super_scs == 1) {
        scs_free(w->R);
        scs_free(w->R_prev);
        scs_free(w->dir);
        scs_free(w->dut);
        scs_free(w->Sk);
        scs_free(w->Yk);
        scs_free(w->wu);
        scs_free(w->wu_t);
        scs_free(w->wu_b);
        scs_free(w->Rwu);
        scs_free_direction_cache(w->direction_cache);
        scs_free(w->s_b);
        scs_free(w->H);
    }
    scs_free(w);
}

/* LCOV_EXCL_START */
static void scs_print_init_header(
        const ScsData * RESTRICT d,
        const ScsCone * RESTRICT k) {
    scs_int i;
    ScsSettings * RESTRICT stgs = d->stgs;
    char *RESTRICT coneStr = scs_get_cone_header(k);
    char *RESTRICT linSysMethod = getLinSysMethod(d->A, d->stgs);
    FILE * RESTRICT stream = stgs->output_stream;
    scs_int print_mode = stgs->do_override_streams;
    for (i = 0; i < SCS_HEADER_LINE_LEN; ++i) {
        scs_special_print(print_mode, stream, "-");
    }
    scs_special_print(print_mode, stream, "\n\tSCS v%s - Splitting Conic Solver\n\t(c) Brendan "
            "O'Donoghue, Stanford University, 2012-2016\n",
            scs_version());
    for (i = 0; i < SCS_HEADER_LINE_LEN; ++i) {
        scs_special_print(print_mode, stream, "-");
    }
    scs_special_print(print_mode, stream, "\n");
    if (linSysMethod) {
        scs_special_print(print_mode, stream, "Lin-sys: %s\n", linSysMethod);
        scs_free(linSysMethod);
    }
    if (stgs->normalize) {
        scs_special_print(print_mode, stream, "eps = %.2e, alpha = %.2f, max_iters = %i, normalize = %i, "
                "scale = %2.2f\n",
                stgs->eps, stgs->alpha, (int) stgs->max_iters,
                (int) stgs->normalize, stgs->scale);
    } else {
        scs_special_print(print_mode, stream, "eps = %.2e, alpha = %.2f, max_iters = %i, normalize = %i\n",
                stgs->eps, stgs->alpha, (int) stgs->max_iters,
                (int) stgs->normalize);
    }
    scs_special_print(print_mode, stream, "do_super_scs = %i, direction = %i, "
            "memory = %i\n", (int) stgs->do_super_scs, (int) stgs->direction,
            (int) stgs->memory);
    scs_special_print(print_mode, stream, "Variables n = %i, constraints m = %i\n", (int) d->n, (int) d->m);
    scs_special_print(print_mode, stream, "%s", coneStr);
    scs_free(coneStr);
#ifdef MATLAB_MEX_FILE
    mexEvalString("drawnow;");
#endif
}

/* LCOV_EXCL_STOP */

static void scs_populate_on_failure(
        scs_int m,
        scs_int n,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info,
        scs_int statusVal,
        const char *RESTRICT msg) {
    if (info) {
        info->relGap = NAN;
        info->resPri = NAN;
        info->resDual = NAN;
        info->pobj = NAN;
        info->dobj = NAN;
        info->iter = -1;
        info->statusVal = statusVal;
        info->solveTime = NAN;
        strcpy(info->status, msg);
    }
    if (sol) {
        if (n > 0) {
            if (sol->x == SCS_NULL)
                sol->x = scs_malloc(sizeof (scs_float) * n);
            scs_scale_array(sol->x, NAN, n);
        }
        if (m > 0) {
            if (sol->y == SCS_NULL)
                sol->y = scs_malloc(sizeof (scs_float) * m);
            scs_scale_array(sol->y, NAN, m);
            if (sol->s == SCS_NULL)
                sol->s = scs_malloc(sizeof (scs_float) * m);
            scs_scale_array(sol->s, NAN, m);
        }
    }
}

static scs_int scs_failure(
        ScsWork * RESTRICT w,
        scs_int m,
        scs_int n,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info,
        scs_int stint,
        const char *RESTRICT msg,
        const char *RESTRICT ststr,
        scs_int print_mode) {
    scs_int status = stint;
    scs_populate_on_failure(m, n, sol, info, status, ststr);
    scs_special_print(print_mode, stderr, "Failure:%s\n", msg);
    endInterruptListener();
    return status;
}

static void scs_warm_start_vars(ScsWork * RESTRICT w, const ScsSolution * RESTRICT sol) {
    scs_int i;
    scs_int n = w->n;
    scs_int m = w->m;
    scs_float * RESTRICT Ax = SCS_NULL;
    scs_float * RESTRICT ATy = SCS_NULL;

    if (!w->stgs->do_super_scs) {
        memset(w->v, 0, n * sizeof (scs_float));
        memcpy(w->u, sol->x, n * sizeof (scs_float));
        memcpy(&(w->u[n]), sol->y, m * sizeof (scs_float));
        memcpy(&(w->v[n]), sol->s, m * sizeof (scs_float));
        w->v[n + m] = 0.0;
        w->u[n + m] = 1.0;
    } else {
        memcpy(w->u_t, sol->x, n * sizeof (scs_float));
        memcpy(&(w->u_t[n]), sol->y, m * sizeof (scs_float));
        w->u_t[n + m] = 1.0;
    }
#ifndef NOVALIDATE
    if (!w->stgs->do_super_scs) {
        for (i = 0; i < n + m + 1; ++i) {
            if (scs_isnan(w->u[i])) {
                w->u[i] = 0;
            }
            if (scs_isnan(w->v[i])) {
                w->v[i] = 0;
            }
        }
    } else {
        for (i = 0; i < n + m + 1; ++i) {
            if (scs_isnan(w->u_t[i])) {
                w->u_t[i] = 0;
            }
        }
    }
#endif
    if (w->stgs->normalize) {
        scs_normalize_warm_start(w);
    }
    if (w->stgs->do_super_scs) {
        Ax = scs_calloc(m, sizeof (scs_float));
        ATy = scs_calloc(n, sizeof (scs_float));

        accumByA(w->A, w->p, w->u_t, Ax); /* Ax_t = A*x_t */
        accumByAtrans(w->A, w->p, &(w->u_t[n]), ATy); /* ATy_t = AT*y_t */
        for (i = 0; i < n; ++i) {
            /* rho_x*x_t  + ATy_t + c*tau_t */
            w->u[i] = w->u_t[i] + ATy[i] + w->c[i] * w->u_t[n + m];
        }
        for (i = 0; i < m; ++i) {
            /* -Ax_t  + y_t + b*tau_t */
            w->u[i + n] = -Ax[i] + w->u_t[i + n] + w->b[i] * w->u_t[n + m];
        }
        /* -cTx_t - BTy_t + tau_t */
        w->u[n + m] = -scs_inner_product(w->c, w->u_t, w->n) - scs_inner_product(w->b, &(w->u_t[n]), w->m) + w->u_t[n + m];
    }
    if (Ax != SCS_NULL) {
        scs_free(Ax);
    }
    if (ATy != SCS_NULL) {
        scs_free(ATy);
    }
}

static scs_float scs_calc_primal_resid(
        ScsWork * RESTRICT w,
        const scs_float * RESTRICT x,
        const scs_float * RESTRICT s,
        const scs_float tau,
        scs_float * RESTRICT nmAxs) {
    scs_int i;
    scs_float pres = 0, scale, *RESTRICT pr = w->pr;
    *nmAxs = 0;
    memset(pr, 0, w->m * sizeof (scs_float));
    accumByA(w->A, w->p, x, pr);
    scs_add_scaled_array(pr, s, w->m, 1.0); /* pr = Ax + s */
    for (i = 0; i < w->m; ++i) {
        scale =
                w->stgs->normalize ? w->scal->D[i] / (w->sc_b * w->stgs->scale) : 1;
        scale = scale * scale;
        *nmAxs += (pr[i] * pr[i]) * scale;
        pres += (pr[i] - w->b[i] * tau) * (pr[i] - w->b[i] * tau) * scale;
    }
    *nmAxs = SQRTF(*nmAxs);
    return SQRTF(pres); /* norm(Ax + s - b * tau), for superSCS: norm(Ax_b + s_b - b * tau_b) */
}

static scs_float scs_calc_dual_resid(
        ScsWork * RESTRICT w,
        const scs_float * RESTRICT y,
        const scs_float tau,
        scs_float * RESTRICT nmATy) {
    scs_int i;
    scs_float dres = 0, scale, *dr = w->dr;
    *nmATy = 0;
    memset(dr, 0, w->n * sizeof (scs_float));
    accumByAtrans(w->A, w->p, y, dr); /* dr = A'y */
    for (i = 0; i < w->n; ++i) {
        scale =
                w->stgs->normalize ? (w->scal->E[i] / (w->sc_c * w->stgs->scale)) : 1;
        scale = scale * scale;
        *nmATy += (dr[i] * dr[i]) * scale;
        dres += (dr[i] + w->c[i] * tau) * (dr[i] + w->c[i] * tau) * scale;
    }
    *nmATy = SQRTF(*nmATy);
    return SQRTF(dres); /* norm(A'y + c * tau), for superSCS: norm(A'y_b + c * tau_b)*/
}

/* calculates un-normalized quantities */
static void scs_calc_residuals(
        ScsWork * RESTRICT w,
        struct scs_residuals * RESTRICT r,
        scs_int iter) {
    scs_float * RESTRICT x;
    scs_float * RESTRICT y;
    scs_float * RESTRICT s;
    scs_float nmpr_tau;
    scs_float nmdr_tau;
    scs_float nmAxs_tau;
    scs_float nmATy_tau;
    scs_float cTx, bTy;
    scs_int n = w->n, m = w->m;

    /* checks if the residuals are unchanged by checking iteration */
    if (r->last_iter == iter) {
        return;
    }
    r->last_iter = iter;

    s = &(w->v[w->n]);
    x = w->u;
    y = &(w->u[w->n]);

    r->tau = ABS(w->u[n + m]);
    r->kap = ABS(w->v[n + m]) /
            (w->stgs->normalize ? (w->stgs->scale * w->sc_c * w->sc_b) : 1);

    nmpr_tau = scs_calc_primal_resid(w, x, s, r->tau, &nmAxs_tau);
    nmdr_tau = scs_calc_dual_resid(w, y, r->tau, &nmATy_tau);

    r->bTy_by_tau =
            scs_inner_product(y, w->b, m) /
            (w->stgs->normalize ? (w->stgs->scale * w->sc_c * w->sc_b) : 1);
    r->cTx_by_tau =
            scs_inner_product(x, w->c, n) /
            (w->stgs->normalize ? (w->stgs->scale * w->sc_c * w->sc_b) : 1);

    r->res_infeas =
            r->bTy_by_tau < 0 ? w->nm_b * nmATy_tau / -r->bTy_by_tau : NAN;
    r->res_unbdd =
            r->cTx_by_tau < 0 ? w->nm_c * nmAxs_tau / -r->cTx_by_tau : NAN;

    bTy = r->bTy_by_tau / r->tau;
    cTx = r->cTx_by_tau / r->tau;

    r->res_pri = nmpr_tau / (1 + w->nm_b) / r->tau;
    r->res_dual = nmdr_tau / (1 + w->nm_c) / r->tau;
    r->rel_gap = ABS(cTx + bTy) / (1 + ABS(cTx) + ABS(bTy));
}

static void scs_calc_residuals_superscs(
        ScsWork * RESTRICT w,
        struct scs_residuals * RESTRICT residuals,
        scs_int iter) {
    scs_float * RESTRICT xb;
    scs_float * RESTRICT yb;
    scs_float * RESTRICT sb;
    scs_float cTx;
    scs_float bTy;
    scs_float * RESTRICT pr = w->pr;
    scs_float * RESTRICT dr = w->dr;
    scs_int n = w->n;
    scs_int m = w->m;
    scs_int i;
    scs_float norm_D_A_x_plus_s; /* norm of D*(Ax+s), intermediate variable */
    scs_float norm_E_Atran_yb; /* norm of E*A'*y,   intermediate variable */
    scs_float tmp__c_times_x; /* c'x */
    scs_float tmp__b_times_yb; /* b'y */
    const scs_float temp1 = w->sc_b * w->stgs->scale; /* auxiliary variable #1 */
    const scs_float temp2 = w->sc_c * temp1; /* auxiliary variable #2 */
    const scs_float temp3 = w->sc_c * w->stgs->scale; /* auxiliary variable #3 */


    /* checks if the residuals are unchanged by checking iteration */
    if (residuals->last_iter == iter) {
        return;
    }
    residuals->last_iter = iter;

    sb = w->s_b;
    xb = w->u_b;
    yb = &(w->u_b[n]);

    residuals->kap = w->kap_b;
    residuals->tau = w->u_b[n + m]; /* it's actually tau_b */
    memset(pr, 0, w->m * sizeof (scs_float)); /* pr = 0 */
    memset(dr, 0, w->n * sizeof (scs_float)); /* dr = 0 */

    accumByA(w->A, w->p, xb, pr); /* pr = A xb */
    scs_add_scaled_array(pr, sb, w->m, 1.0); /* pr = A xb + sb */
    /* --- compute ||D(Ax + s)|| --- */
    norm_D_A_x_plus_s = 0;
    if (w->stgs->normalize) {
        for (i = 0; i < m; ++i) {
            scs_float tmp = w->scal->D[i] * pr[i];
            norm_D_A_x_plus_s += tmp * tmp;
        }
    } else {
        norm_D_A_x_plus_s = scs_norm_squared(pr, m);
    }
    norm_D_A_x_plus_s = SQRTF(norm_D_A_x_plus_s);
    scs_add_scaled_array(pr, w->b, m, -residuals->tau); /* pr = A xb + sb - b taub */

    accumByAtrans(w->A, w->p, yb, dr); /* dr = A' yb */


    /* --- compute ||E A' yb|| --- */
    norm_E_Atran_yb = 0.0;
    if (w->stgs->normalize) {
        for (i = 0; i < n; ++i) {
            scs_float tmp = w->scal->E[i] * dr[i];
            norm_E_Atran_yb += tmp * tmp;
        }
    } else {
        norm_E_Atran_yb = scs_norm_squared(dr, n);
    }
    norm_E_Atran_yb = SQRTF(norm_E_Atran_yb);
    scs_add_scaled_array(dr, w->c, w->n, residuals->tau); /* dr = A' yb + c taub */

    /*
     * bTy_by_tau = b'yb / (scale*sc_c*sc_b)
     * cTx_by_tau = c'xb / (scale*sc_c*sc_b)
     */
    tmp__b_times_yb = scs_inner_product(yb, w->b, m);
    residuals->bTy_by_tau = tmp__b_times_yb / (w->stgs->normalize ? (temp2) : 1);
    tmp__c_times_x = scs_inner_product(xb, w->c, n);
    residuals->cTx_by_tau = tmp__c_times_x / (w->stgs->normalize ? (temp2) : 1);

    /*
     * bTy = b'yb / (scale*sc_c*sc_b) / taub
     * cTx = c'xb / (scale*sc_c*sc_b) / taub
     */
    bTy = residuals->bTy_by_tau / residuals->tau;
    cTx = residuals->cTx_by_tau / residuals->tau;

    /* PRIMAL RESIDUAL */
    if (w->stgs->normalize) {
        residuals->res_pri = 0;
        for (i = 0; i < m; ++i) {
            scs_float tmp = w->scal->D[i] * pr[i];
            residuals->res_pri += (tmp * tmp);
        }
        residuals->res_pri = SQRTF(residuals->res_pri) / residuals->tau;
        residuals->res_pri /= ((1 + w->nm_b) * temp1);
    } else {
        residuals->res_pri = scs_norm(pr, m) / residuals->tau;
        residuals->res_pri /= (1 + w->nm_b);
    }

    /* DUAL RESIDUAL */
    if (w->stgs->normalize) {
        residuals->res_dual = 0;
        for (i = 0; i < n; ++i) {
            scs_float tmp = w->scal->E[i] * dr[i];
            residuals->res_dual += (tmp * tmp);
        }
        residuals->res_dual = SQRTF(residuals->res_dual) / residuals->tau;
        residuals->res_dual /= ((1 + w->nm_c) * temp3);
    } else {
        residuals->res_dual = scs_norm(dr, n) / residuals->tau;
        residuals->res_dual /= (1 + w->nm_c);
    }

    /* UNBOUNDEDNESS */
    if (tmp__c_times_x < 0) {
        scs_float norm_Ec = 0;
        if (w->stgs->normalize) {
            for (i = 0; i < n; ++i) {
                scs_float tmp = w->scal->E[i] * w->c[i];
                norm_Ec += (tmp * tmp);
            }
        } else {
            norm_Ec += scs_norm_squared(w->c, n);
        }
        residuals->res_unbdd = -SQRTF(norm_Ec) * norm_D_A_x_plus_s / tmp__c_times_x;
        residuals->res_unbdd /= (w->stgs->normalize ? w->stgs->scale : 1);
    } else {
        residuals->res_unbdd = NAN; /* not unbounded */
    }


    /* INFEASIBILITY */
    if (tmp__b_times_yb < 0) {
        scs_float norm_Db_squared = 0;
        if (w->stgs->normalize) {
            for (i = 0; i < m; ++i) {
                scs_float tmp = w->scal->D[i] * w->b[i];
                norm_Db_squared += (tmp * tmp);
            }
        } else {
            norm_Db_squared += scs_norm_squared(w->b, m);
        }
        residuals->res_infeas = -SQRTF(norm_Db_squared) * norm_E_Atran_yb / tmp__b_times_yb;
        residuals->res_infeas /= (w->stgs->normalize ? w->stgs->scale : 1);
    } else {
        residuals->res_infeas = NAN; /* not infeasible */
    }
    residuals->rel_gap = ABS(cTx + bTy) / (1 + ABS(cTx) + ABS(bTy));
}

static void scs_cold_start_vars(ScsWork * RESTRICT w) {
    scs_int l = w->l;
    memset(w->u, 0, l * sizeof (scs_float));
    w->u[l - 1] = SQRTF((scs_float) l);
    if (!w->stgs->do_super_scs) {
        memset(w->v, 0, l * sizeof (scs_float));
        w->v[l - 1] = SQRTF((scs_float) l);
    }
}

/* status < 0 indicates failure */
static scs_int scs_project_lin_sys(
        ScsWork * RESTRICT w,
        scs_int iter) {
    /* ut = u + v */
    scs_int n = w->n, m = w->m, l = n + m + 1, status;
    memcpy(w->u_t, w->u, l * sizeof (scs_float));
    scs_add_scaled_array(w->u_t, w->v, l, 1.0);

    scs_scale_array(w->u_t, w->stgs->rho_x, n);

    scs_add_scaled_array(w->u_t, w->h, l - 1, -w->u_t[l - 1]);
    scs_add_scaled_array(w->u_t, w->h, l - 1,
            -scs_inner_product(w->u_t, w->g, l - 1) / (w->gTh + 1));
    scs_scale_array(&(w->u_t[n]), -1, m);

    status = scs_solve_lin_sys(w->A, w->stgs, w->p, w->u_t, w->u, iter);

    w->u_t[l - 1] += scs_inner_product(w->u_t, w->h, l - 1);

    return status;
}

/* status < 0 indicates failure */
static scs_int superscs_project_lin_sys(
        scs_float * RESTRICT u_t,
        scs_float * RESTRICT u,
        ScsWork * RESTRICT w,
        scs_int iter) {
    scs_int status;
    const scs_int l = w->l;

    /* x_t = rho_x * x_t */
    memcpy(u_t + w->n, u + w->n, (w->m + 1) * sizeof (scs_float));
    scs_set_as_scaled_array(u_t, u, w->stgs->rho_x, w->n);

    /* (x_t, y_t) -= tau_t * h                   */
    scs_add_scaled_array(u_t, w->h, l - 1, -u_t[l - 1]);

    /* u_t -= scalar * h                         */
    scs_add_scaled_array(u_t, w->h, l - 1,
            -scs_inner_product(u_t, w->g, l - 1) / (w->gTh + 1));

    /* y_t *= (-1)                               */
    scs_scale_array(u_t + w->n, -1, w->m);

    /* call `scs_solve_lin_sys` to update (x_t, y_t)   */
    status = scs_solve_lin_sys(w->A, w->stgs, w->p, u_t, u, iter);

    /* tau_t += h'*(x_t, y_t)                    */
    u_t[l - 1] += scs_inner_product(u_t, w->h, l - 1);

    return status;
}

/* LCOV_EXCL_START */
void scs_print_sol(
        ScsWork * RESTRICT w,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info) {
    scs_int i;
    FILE * RESTRICT stream = w->stgs->output_stream;
    scs_int print_mode = w->stgs->do_override_streams;
    scs_special_print(print_mode, stream, "%s\n", info->status);
    if (sol->x != SCS_NULL) {
        for (i = 0; i < w->n; ++i) {
            scs_special_print(print_mode, stream, "x[%i] = %4f\n", (int) i, sol->x[i]);
        }
    }
    if (sol->y != SCS_NULL) {
        for (i = 0; i < w->m; ++i) {
            scs_special_print(print_mode, stream, "y[%i] = %4f\n", (int) i, sol->y[i]);
        }
    }
}

/* LCOV_EXCL_STOP */

static void scs_update_dual_vars(ScsWork * RESTRICT w) {
    scs_int i, n = w->n, l = n + w->m + 1;
    /* this does not relax 'x' variable */
    for (i = n; i < l; ++i) {
        w->v[i] += (w->u[i] - w->stgs->alpha * w->u_t[i] -
                (1.0 - w->stgs->alpha) * w->u_prev[i]);
    }
}

/* Calculates the fixed point residual R */
static void scs_calc_FPR(
        scs_float * RESTRICT R,
        scs_float * RESTRICT u_t,
        scs_float * RESTRICT u_b,
        scs_int l) {
    scs_axpy(R, u_t, u_b, 1.0, -1.0, l);
}

/* status < 0 indicates failure */
static scs_int scs_project_cones(
        ScsWork * RESTRICT w,
        const ScsCone * RESTRICT k,
        scs_int iter) {
    scs_int i, n = w->n, l = n + w->m + 1, status;
    /* this does not relax 'x' variable */
    for (i = 0; i < n; ++i) {
        w->u[i] = w->u_t[i] - w->v[i];
    }
    for (i = n; i < l; ++i) {
        w->u[i] = w->stgs->alpha * w->u_t[i] +
                (1 - w->stgs->alpha) * w->u_prev[i] - w->v[i];
    }
    /* u = [x;y;tau] */
    status = scs_project_dual_cone(&(w->u[n]), k, w->coneWork, &(w->u_prev[n]), iter);
    if (w->u[l - 1] < 0.0)
        w->u[l - 1] = 0.0;

    return status;
}

/* status < 0 indicates failure */
static scs_int superscs_project_cones(
        scs_float * RESTRICT u_b,
        scs_float * RESTRICT u_t,
        scs_float * RESTRICT u,
        ScsWork * RESTRICT w,
        const ScsCone * RESTRICT k,
        scs_int iter) {
    scs_int n = w->n;
    scs_int l = n + w->m + 1;
    scs_int status;
    /* this does not relax 'x' variable */
    scs_axpy(u_b, u_t, u, 2.0, -1.0, l);

    /* u = [x;y;tau] */
    status = scs_project_dual_cone(&(u_b[n]), k, w->coneWork, &(w->u_prev[n]), iter);
    if (u_b[l - 1] < 0.0) {
        u_b[l - 1] = 0.0;
    }
    return status;
}

/* LCOV_EXCL_START */
static scs_int scs_indeterminate(
        ScsWork * RESTRICT w,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info) {
    strncpy(info->status, "Indeterminate", 13);
    scs_scale_array(sol->x, NAN, w->n);
    scs_scale_array(sol->y, NAN, w->m);
    scs_scale_array(sol->s, NAN, w->m);
    return SCS_INDETERMINATE;
}

/* LCOV_EXCL_STOP */

static scs_int scs_solved(
        ScsWork * RESTRICT w,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info,
        scs_float tau) {
    scs_scale_array(sol->x, 1.0 / tau, w->n);
    scs_scale_array(sol->y, 1.0 / tau, w->m);
    scs_scale_array(sol->s, 1.0 / tau, w->m);
    if (info->statusVal == 0) {
        strncpy(info->status, "Solved/Inaccurate", 17);
        return SCS_SOLVED_INACCURATE;
    }
    strncpy(info->status, "Solved", 6);
    return SCS_SOLVED;
}

static scs_int scs_infeasible(
        ScsWork * RESTRICT w,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info,
        scs_float bTy) {
    scs_scale_array(sol->y, -1 / bTy, w->m);
    scs_scale_array(sol->x, NAN, w->n);
    scs_scale_array(sol->s, NAN, w->m);
    if (info->statusVal == 0) {
        strncpy(info->status, "Infeasible/Inaccurate", 21);
        return SCS_INFEASIBLE_INACCURATE;
    }
    strncpy(info->status, "Infeasible", 10);
    return SCS_INFEASIBLE;
}

static scs_int scs_unbounded(
        ScsWork * RESTRICT w,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info,
        scs_float cTx) {
    scs_scale_array(sol->x, -1 / cTx, w->n);
    scs_scale_array(sol->s, -1 / cTx, w->m);
    scs_scale_array(sol->y, NAN, w->m);
    if (info->statusVal == 0) {
        strncpy(info->status, "Unbounded/Inaccurate", 20);
        return SCS_UNBOUNDED_INACCURATE;
    }
    strncpy(info->status, "Unbounded", 9);
    return SCS_UNBOUNDED;
}

static void scs_set_y(ScsWork * RESTRICT w, ScsSolution * RESTRICT sol) {
    if (!sol->y) {
        sol->y = scs_malloc(sizeof (scs_float) * w->m);
    }
    if (!w->stgs->do_super_scs) {
        memcpy(sol->y, &(w->u[w->n]), w->m * sizeof (scs_float));
    } else {
        memcpy(sol->y, &(w->u_b[w->n]), w->m * sizeof (scs_float));
    }
}

static void scs_set_s(ScsWork * RESTRICT w, ScsSolution * RESTRICT sol) {
    if (!sol->s) {
        sol->s = scs_malloc(sizeof (scs_float) * w->m);
    }
    if (!w->stgs->do_super_scs) {
        memcpy(sol->s, &(w->v[w->n]), w->m * sizeof (scs_float));
    } else {
        memcpy(sol->s, w->s_b, w->m * sizeof (scs_float));
    }
}

static void scs_set_x(ScsWork * RESTRICT w, ScsSolution * RESTRICT sol) {
    if (!sol->x)
        sol->x = scs_malloc(sizeof (scs_float) * w->n);
    if (!w->stgs->do_super_scs) {
        memcpy(sol->x, w->u, w->n * sizeof (scs_float));
    } else {
        memcpy(sol->x, w->u_b, w->n * sizeof (scs_float));
    }
}

scs_int scs_is_solved_status(scs_int status) {
    return status == SCS_SOLVED || status == SCS_SOLVED_INACCURATE;
}

scs_int scs_is_infeasible_status(scs_int status) {
    return status == SCS_INFEASIBLE || status == SCS_INFEASIBLE_INACCURATE;
}

scs_int scs_is_unbounded_status(scs_int status) {
    return status == SCS_UNBOUNDED || status == SCS_UNBOUNDED_INACCURATE;
}

static void scs_get_info(
        ScsWork * RESTRICT w,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info,
        struct scs_residuals * RESTRICT r,
        scs_int iter) {
    info->iter = iter;
    info->resInfeas = r->res_infeas;
    info->resUnbdd = r->res_unbdd;
    if (scs_is_solved_status(info->statusVal)) {
        info->relGap = r->rel_gap;
        info->resPri = r->res_pri;
        info->resDual = r->res_dual;
        info->pobj = r->cTx_by_tau / r->tau;
        info->dobj = -r->bTy_by_tau / r->tau;
    } else if (scs_is_unbounded_status(info->statusVal)) {
        info->relGap = NAN;
        info->resPri = NAN;
        info->resDual = NAN;
        info->pobj = -INFINITY;
        info->dobj = -INFINITY;
    } else if (scs_is_infeasible_status(info->statusVal)) {
        info->relGap = NAN;
        info->resPri = NAN;
        info->resDual = NAN;
        info->pobj = INFINITY;
        info->dobj = INFINITY;
    }
}

/* sets solutions, re-scales by inner prods if infeasible or unbounded */
static void scs_get_solution(
        ScsWork * RESTRICT work,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info,
        struct scs_residuals * RESTRICT r,
        scs_int iter) {
    scs_int l = work->l;
    if (!work->stgs->do_super_scs) {
        scs_calc_residuals(work, r, iter);
    } else {
        scs_calc_residuals_superscs(work, r, iter);
        r->kap = ABS(work->kap_b) /
                (work->stgs->normalize ? (work->stgs->scale * work->sc_c * work->sc_b) : 1.0);
    }
    scs_set_x(work, sol);
    scs_set_y(work, sol);
    scs_set_s(work, sol);
    if (info->statusVal == SCS_UNFINISHED) {
        /* not yet converged, take best guess */
        if (r->tau > SCS_INDETERMINATE_TOL && r->tau > r->kap) {
            info->statusVal = scs_solved(work, sol, info, r->tau);
        } else if (scs_norm(work->u, l) <
                SCS_INDETERMINATE_TOL * SQRTF((scs_float) l)) {
            info->statusVal = scs_indeterminate(work, sol, info);
        } else if (r->bTy_by_tau < r->cTx_by_tau) {
            info->statusVal = scs_infeasible(work, sol, info, r->bTy_by_tau);
        } else {
            info->statusVal = scs_unbounded(work, sol, info, r->cTx_by_tau);
        }
    } else if (scs_is_solved_status(info->statusVal)) {
        info->statusVal = scs_solved(work, sol, info, r->tau);
    } else if (scs_is_infeasible_status(info->statusVal)) {
        info->statusVal = scs_infeasible(work, sol, info, r->bTy_by_tau);
    } else {
        info->statusVal = scs_unbounded(work, sol, info, r->cTx_by_tau);
    }
    if (work->stgs->normalize) {
        scs_unnormalize_sol(work, sol);
    }
    scs_get_info(work, sol, info, r, iter);
}

/* LCOV_EXCL_START */
static void scs_print_summary(
        ScsWork * RESTRICT w,
        scs_int i,
        struct scs_residuals * RESTRICT r,
        timer * RESTRICT solveTimer) {
    FILE * RESTRICT stream = w->stgs->output_stream;
    scs_int print_mode = w->stgs->do_override_streams;
    scs_special_print(print_mode, stream, "%*i|", (int) strlen(SCS_HEADER[0]), (int) i);
    scs_special_print(print_mode, stream, "%*.2e ", (int) SCS_HSPACE, r->res_pri);
    scs_special_print(print_mode, stream, "%*.2e ", (int) SCS_HSPACE, r->res_dual);
    scs_special_print(print_mode, stream, "%*.2e ", (int) SCS_HSPACE, r->rel_gap);
    scs_special_print(print_mode, stream, "%*.2e ", (int) SCS_HSPACE, r->cTx_by_tau / r->tau);
    scs_special_print(print_mode, stream, "%*.2e ", (int) SCS_HSPACE, -r->bTy_by_tau / r->tau);
    scs_special_print(print_mode, stream, "%*.2e ", (int) SCS_HSPACE, r->kap / r->tau);
    if (w->stgs->do_super_scs) {
        scs_special_print(print_mode, stream, "%*.2e ", (int) SCS_HSPACE, w->nrmR_con);
    }
    scs_special_print(print_mode, stream, "%*.2e ", (int) SCS_HSPACE, tocq(solveTimer) / 1e3);
    scs_special_print(print_mode, stream, "\n");

#if EXTRAVERBOSE > 0
    scs_printf("Norm u = %4f, ", scs_norm(w->u, w->n + w->m + 1));
    scs_printf("Norm u_t = %4f, ", scs_norm(w->u_t, w->n + w->m + 1));
    if (!w->stgs->do_super_scs) {
        scs_printf("Norm v = %4f, ", scs_norm(w->v, w->n + w->m + 1));
    }
    scs_printf("tau = %4f, ", w->u[w->n + w->m]);
    if (!w->stgs->do_super_scs) {
        scs_printf("kappa = %4f, ", w->v[w->n + w->m]);
    }
    scs_printf("|u - u_prev| = %1.2e, ",
            scs_norm_difference(w->u, w->u_prev, w->n + w->m + 1));
    scs_printf("|u - u_t| = %1.2e, ",
            scs_norm_difference(w->u, w->u_t, w->n + w->m + 1));
    scs_printf("resInfeas = %1.2e, ", r->res_infeas);
    scs_printf("resUnbdd = %1.2e\n", r->res_unbdd);
#endif

#ifdef MATLAB_MEX_FILE
    mexEvalString("drawnow;");
#endif
}

static void scs_print_header(ScsWork * RESTRICT w, const ScsCone * RESTRICT k) {
    scs_int i;
    FILE * RESTRICT stream = w->stgs->output_stream;
    scs_int print_mode = w->stgs->do_override_streams;
    if (w->stgs->warm_start)
        scs_special_print(print_mode, stream, "SCS using variable warm-starting\n");
    for (i = 0; i < SCS_HEADER_LINE_LEN; ++i) {
        scs_special_print(print_mode, stream, "-");
    }
    scs_special_print(print_mode, stream, "\n");
    for (i = 0; i < SCS_HEADER_LEN - 2; ++i) {
        scs_special_print(print_mode, stream, "%s|", SCS_HEADER[i]);
    }
    if (w->stgs->do_super_scs) {
        scs_special_print(print_mode, stream, "%s|", SCS_HEADER[SCS_HEADER_LEN - 2]);
    }
    scs_special_print(print_mode, stream, "%s\n", SCS_HEADER[SCS_HEADER_LEN - 1]);
    for (i = 0; i < SCS_HEADER_LINE_LEN; ++i) {
        scs_special_print(print_mode, stream, "-");
    }
    scs_special_print(print_mode, stream, "\n");
#ifdef MATLAB_MEX_FILE
    mexEvalString("drawnow;");
#endif
}

/* LCOV_EXCL_STOP */

scs_float scs_get_dual_cone_dist(
        const scs_float * RESTRICT y,
        const ScsCone * RESTRICT k,
        ConeWork * RESTRICT c,
        scs_int m) {
    scs_float dist;
    scs_float * RESTRICT t = scs_malloc(sizeof (scs_float) * m);
    memcpy(t, y, m * sizeof (scs_float));
    scs_project_dual_cone(t, k, c, SCS_NULL, -1);
    dist = scs_norm_infinity_difference(t, y, m);
#if EXTRAVERBOSE > 0
    scs_print_array(y, m, "y");
    scs_print_array(t, m, "projY");
    scs_printf("dist = %4f\n", dist);
#endif
    scs_free(t);
    return dist;
}

/* via moreau */
scs_float scs_get_primal_cone_dist(
        const scs_float * RESTRICT s,
        const ScsCone * RESTRICT k,
        ConeWork * RESTRICT c,
        scs_int m) {
    scs_float dist;
    scs_float * RESTRICT t = scs_malloc(sizeof (scs_float) * m);
    memcpy(t, s, m * sizeof (scs_float));
    scs_scale_array(t, -1.0, m);
    scs_project_dual_cone(t, k, c, SCS_NULL, -1);
    dist = scs_norm_infinity(t, m); /* ||s - Pi_c(s)|| = ||Pi_c*(-s)|| */
#if EXTRAVERBOSE > 0
    scs_print_array(s, m, "s");
    scs_print_array(t, m, "(s - ProjS)");
    scs_printf("dist = %4f\n", dist);
#endif
    scs_free(t);
    return dist;
}

void scs_millis_to_time(scs_float time,
        scs_int * hours,
        scs_int * minutes,
        scs_int * secs,
        scs_float * sec_rest) {
    scs_float integral;
    scs_float time_seconds = time / 1e3;
    *sec_rest = (scs_float) modf((double) time_seconds, &integral);
    *secs = (scs_int) time_seconds;
    *minutes = *secs / 60;
    *secs %= 60;
    if (*minutes >= 60) {
        *hours = *minutes / 60;
        *minutes %= 60;
    } else {
        *hours = 0;
    }
}

/* LCOV_EXCL_START */
static void scs_print_footer(
        const ScsData * RESTRICT d,
        const ScsCone * RESTRICT k,
        ScsSolution * RESTRICT sol,
        ScsWork * RESTRICT w,
        ScsInfo * RESTRICT info) {
    scs_int i;
    scs_int hours, minutes, seconds;
    scs_float millis;

    char *linSysStr = getLinSysSummary(w->p, info);
    char *coneStr = scs_get_cone_summary(info, w->coneWork);
    FILE * stream = w->stgs->output_stream;
    scs_int print_mode = w->stgs->do_override_streams;
    for (i = 0; i < SCS_HEADER_LINE_LEN; ++i) {
        scs_special_print(print_mode, stream, "-");
    }
    scs_special_print(print_mode, stream, "\nStatus: %s\n", info->status);
    if (info->iter == w->stgs->max_iters) {
        scs_special_print(print_mode, stream, "Hit max_iters, solution may be inaccurate\n");
    }

    scs_millis_to_time(info->solveTime, &hours, &minutes, &seconds, &millis);
    scs_special_print(print_mode, stream, "Timing: Solve time: %02d:%02d:%02d.%d\n",
            hours, minutes, seconds, (scs_int) round(1e4 * millis) / 10);

    if (linSysStr) {
        scs_special_print(print_mode, stream, "%s", linSysStr);
        scs_free(linSysStr);
    }

    if (coneStr) {
        scs_special_print(print_mode, stream, "%s", coneStr);
        scs_free(coneStr);
    }

    for (i = 0; i < SCS_HEADER_LINE_LEN; ++i) {
        scs_special_print(print_mode, stream, "-");
    }
    scs_special_print(print_mode, stream, "\n");

    if (scs_is_infeasible_status(info->statusVal)) {
        scs_special_print(print_mode, stream, "Certificate of primal infeasibility:\n");
        scs_special_print(print_mode, stream, "dist(y, K*) = %.4e\n",
                scs_get_dual_cone_dist(sol->y, k, w->coneWork, d->m));
        scs_special_print(print_mode, stream, "|A'y|_2 * |b|_2 = %.4e\n", info->resInfeas);
        scs_special_print(print_mode, stream, "b'y = %.4f\n", scs_inner_product(d->b, sol->y, d->m));
    } else if (scs_is_unbounded_status(info->statusVal)) {
        scs_special_print(print_mode, stream, "Certificate of dual infeasibility:\n");
        scs_special_print(print_mode, stream, "dist(s, K) = %.4e\n",
                scs_get_primal_cone_dist(sol->s, k, w->coneWork, d->m));
        scs_special_print(print_mode, stream, "|Ax + s|_2 * |c|_2 = %.4e\n", info->resUnbdd);
        scs_special_print(print_mode, stream, "c'x = %.4f\n", scs_inner_product(d->c, sol->x, d->n));
    } else {
        scs_special_print(print_mode, stream, "Error metrics:\n");
        scs_special_print(print_mode, stream, "dist(s, K) = %.4e, dist(y, K*) = %.4e, s'y/|s||y| = %.4e\n",
                scs_get_primal_cone_dist(sol->s, k, w->coneWork, d->m),
                scs_get_dual_cone_dist(sol->y, k, w->coneWork, d->m),
                scs_inner_product(sol->s, sol->y, d->m) / scs_norm(sol->s, d->m) /
                scs_norm(sol->y, d->m));
        scs_special_print(print_mode, stream, "|Ax + s - b|_2 / (1 + |b|_2) = %.4e\n", info->resPri);
        scs_special_print(print_mode, stream, "|A'y + c|_2 / (1 + |c|_2) = %.4e\n", info->resDual);
        scs_special_print(print_mode, stream, "|c'x + b'y| / (1 + |c'x| + |b'y|) = %.4e\n", info->relGap);
        for (i = 0; i < SCS_HEADER_LINE_LEN; ++i) {
            scs_special_print(print_mode, stream, "-");
        }
        scs_special_print(print_mode, stream, "\n");
        scs_special_print(print_mode, stream, "c'x = %.4f, -b'y = %.4f\n", info->pobj, info->dobj);
    }
    for (i = 0; i < SCS_HEADER_LINE_LEN; ++i) {
        scs_special_print(print_mode, stream, "=");
    }
    scs_special_print(print_mode, stream, "\n");
#ifdef MATLAB_MEX_FILE
    mexEvalString("drawnow;");
#endif
}

/* LCOV_EXCL_STOP */

static scs_int scs_has_converged(
        ScsWork * RESTRICT w,
        struct scs_residuals * RESTRICT r,
        scs_int iter) {
    scs_float eps = w->stgs->eps;
    if (r->res_pri < eps && r->res_dual < eps && r->rel_gap < eps) {
        return SCS_SOLVED;
    }
    if (r->res_unbdd < eps) {
        return SCS_UNBOUNDED;
    }
    if (r->res_infeas < eps) {
        return SCS_INFEASIBLE;
    }
    return 0;
}

static scs_int scs_data_cone_validate(
        const ScsData * RESTRICT d,
        const ScsCone * RESTRICT k) {
    ScsSettings *stgs = d->stgs;
    scs_int print_mode = stgs->do_override_streams;
    if (d->m <= 0 || d->n <= 0) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "m and n must both be greater than 0; m = %li, n = %li\n",
                (long) d->m, (long) d->n);
        return -1;
        /* LCOV_EXCL_STOP */
    }
    if (d->m < d->n) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "WARN: m less than n, problem likely degenerate\n");
        /* LCOV_EXCL_STOP */
    }
    if (validateLinSys(d->A) < 0) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "invalid linear system input data\n");
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    if (scs_validate_cones(d, k) < 0) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "cone validation error\n");
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    if (stgs->max_iters <= 0) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "max_iters must be positive (max_iters=%ld)\n", (long) stgs->max_iters);
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    if (stgs->eps <= 0) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "eps tolerance must be positive (eps=%g)\n", stgs->eps);
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    if (stgs->alpha <= 0 || stgs->alpha >= 2) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "alpha must be in (0,2) (alpha=%g)\n", stgs->alpha);
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    if (stgs->rho_x <= 0) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "rho_x must be positive (1e-3 works well) (rho_x=%g).\n", stgs->rho_x);
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    if (stgs->scale <= 0) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "Parameter `scale` must be positive (1 works well).\n");
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    if (stgs->do_super_scs != 0 && stgs->do_super_scs != 1) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "do_super_scs (=%d) can be either 0 or 1.\n", (int) stgs->do_super_scs);
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    /* validate settings related to SuperSCS */
    if (stgs->do_super_scs == 1) {
        if (stgs->thetabar < 0 || stgs->thetabar > 1) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Parameters `thetabar` must be a scalar between 0 and 1 (thetabar=%g)\n", stgs->thetabar);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if ((stgs->direction == restarted_broyden
                || stgs->direction == restarted_broyden_v2)
                && stgs->memory <= 1) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Quasi-Newton memory length (mem=%ld) is too low; choose an integer at least equal to 2.\n", (long) stgs->memory);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->beta >= 1 || stgs->beta <= 0) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Stepsize reduction factor (beta=%g) out of bounds.\n", stgs->beta);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->ls < 0) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Illegal maximum number of line search iterations (ls=%ld).\n", (long) stgs->ls);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->ls >= 40) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "WARNING! The value ls=%ld is too high. The maximum allowed "
                    "number of line search iteration is 40. We recommend a value about 10.\n", (long) stgs->ls);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->ls > 10) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "WARNING! The value ls=%ld is too high. We highly recommend"
                    "the maximum number of line search iterations to be at most 10.\n", (long) stgs->ls);
            /* LCOV_EXCL_STOP */
        }
        if (stgs->sigma < 0) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Parameter sigma of the line search (sigma=%g) cannot be negative.\n", stgs->sigma);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->c_bl < 0 || stgs->c_bl >= 1) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Parameter (c_0=%g) for blind updates out of bounds.\n", stgs->c_bl);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->c1 < 0 || stgs->c1 >= 1) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Parameter (c1=%g) for step K1 out of bounds.\n", stgs->c1);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->sse < 0 || stgs->sse >= 1) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Parameter (sse=%g) for step K1 out of bounds.\n", stgs->sse);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->k0 != 0 && stgs->k0 != 1) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Parameter (k0=%d) can be eiter 0 (k0: off) or 1 (k0: on).\n", (int) stgs->k0);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->k1 != 0 && stgs->k1 != 1) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Parameter (k1=%d) can be eiter 0 (k1: off) or 1 (k1: on).\n", (int) stgs->k1);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->k2 != 0 && stgs->k2 != 1) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Parameter (k2=%d) can be eiter 0 (k2: off) or 1 (k2: on).\n", (int) stgs->k2);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
        if (stgs->direction != restarted_broyden
                && stgs->direction != restarted_broyden_v2
                && stgs->direction != fixed_point_residual
                && stgs->direction != anderson_acceleration
                && stgs->direction != full_broyden) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "Invalid direction (%ld).\n",
                    (long) stgs->direction);
            return SCS_FAILED;
            /* LCOV_EXCL_STOP */
        }
    }
    return 0;
}

static ScsWork * scs_init_work(
        const ScsData * RESTRICT d,
        const ScsCone * RESTRICT k) {
    ScsWork *w = scs_calloc(1, sizeof (*w));
    const scs_int l = d->n + d->m + 1;
    scs_int print_mode = d->stgs->do_override_streams;
    if (d->stgs->verbose) {
        scs_print_init_header(d, k);
    }
    if (!w) {
        scs_special_print(print_mode, stderr, "ERROR: allocating work failure\n");
        return SCS_NULL;
    }

    /* get settings and dims from data struct */
    w->stgs = d->stgs;
    w->m = d->m;
    w->n = d->n;
    w->l = l; /* total dimension */

    /* -------------------------------------
     * Workspace allocation:
     *
     * After every call to scs_malloc or scs_calloc
     * we check whether the allocation has been
     * successful.
     * ------------------------------------- */
    w->u = scs_calloc(l, sizeof (scs_float));
    if (w->u == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `u` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->u_b = scs_calloc(l, sizeof (scs_float));
    if (w->u_b == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `u_b` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    if (w->stgs->do_super_scs == 0) {
        w->v = scs_calloc(l, sizeof (scs_float));
        if (w->v == SCS_NULL) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: `v` memory allocation failure\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }
    }
    w->u_t = scs_malloc(l * sizeof (scs_float));
    if (w->u_t == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `u_t` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->u_prev = scs_malloc(l * sizeof (scs_float));
    if (w->u_prev == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `u_prev` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->h = scs_malloc((l - 1) * sizeof (scs_float));
    if (w->h == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `h` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->g = scs_malloc((l - 1) * sizeof (scs_float));
    if (w->g == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `g` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->pr = scs_malloc(d->m * sizeof (scs_float));
    if (w->pr == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `pr` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->dr = scs_malloc(d->n * sizeof (scs_float));
    if (w->dr == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `dr` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->b = scs_malloc(d->m * sizeof (scs_float));
    if (w->b == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `b` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->c = scs_malloc(d->n * sizeof (scs_float));
    if (w->c == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: `c` memory allocation failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }



    if (w->stgs->do_super_scs == 1) {
        /* -------------------------------------
         * Additional memory needs to be allocated
         * in SuperSCS
         * ------------------------------------- */
        w->R = scs_calloc(l, sizeof (scs_float));
        if (w->R == SCS_NULL) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: `R` memory allocation failure\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }
        w->R_prev = scs_calloc(l, sizeof (scs_float));
        if (w->R_prev == SCS_NULL) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: `R_prev` memory allocation failure\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }
        w->dir = scs_malloc(l * sizeof (scs_float));
        if (w->dir == SCS_NULL) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: `dir` memory allocation failure\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }
        w->dut = scs_malloc(l * sizeof (scs_float));
        if (w->dut == SCS_NULL) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: `dut` memory allocation failure\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }
        w->s_b = scs_malloc(d->m * sizeof (scs_float));
        if (w->s_b == SCS_NULL) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: `s_b` memory allocation failure\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }

        w->stepsize = 1.0;

        /* -------------------------------------
         * Restarted Broyden requires the allocation
         * of an (S,U)-cache.
         * ------------------------------------- */
        if ((w->stgs->direction == restarted_broyden
                || w->stgs->direction == restarted_broyden_v2
                || w->stgs->direction == anderson_acceleration)
                && w->stgs->memory > 0) {
            w->direction_cache = scs_init_direction_cache(w->stgs->memory, l, print_mode, w->stgs->direction);
            if (w->direction_cache == SCS_NULL) {
                /* LCOV_EXCL_START */
                scs_special_print(print_mode, stderr,
                        "ERROR: `direction_cache` memory allocation failure\n");
                return SCS_NULL;
                /* LCOV_EXCL_STOP */
            }
        } else {
            w->direction_cache = SCS_NULL;
        }

        /* -------------------------------------
         * Allocate memory for the full Broyden
         * method
         * ------------------------------------- */
        if (w->stgs->direction == full_broyden) {
            scs_int i;
            w->H = scs_malloc(l * l * sizeof (scs_float));
            if (w->H == SCS_NULL) {
                /* LCOV_EXCL_START */
                scs_special_print(print_mode, stderr, "ERROR: `H` memory allocation failure\n");
                return SCS_NULL;
                /* LCOV_EXCL_STOP */
            }
            /* H = I */
            for (i = 0; i < l; ++i) {
                w->H[i * (l + 1)] = 1.0;
            }
        } else {
            w->H = SCS_NULL;
        }

        w->Sk = scs_malloc(l * sizeof (scs_float));
        if (w->Sk == SCS_NULL) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: `Sk` memory allocation failure\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }
        w->Yk = scs_malloc(l * sizeof (scs_float));
        if (w->Yk == SCS_NULL) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: `Yk` memory allocation failure\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }

        if (w->stgs->ls > 0) {
            w->wu = scs_malloc(l * sizeof (scs_float));
            if (w->wu == SCS_NULL) {
                /* LCOV_EXCL_START */
                scs_special_print(print_mode, stderr, "ERROR: `wu` memory allocation failure\n");
                return SCS_NULL;
                /* LCOV_EXCL_STOP */
            }
            w->Rwu = scs_malloc(l * sizeof (scs_float));
            if (w->Rwu == SCS_NULL) {
                /* LCOV_EXCL_START */
                scs_special_print(print_mode, stderr, "ERROR: `Rwu` memory allocation failure\n");
                return SCS_NULL;
                /* LCOV_EXCL_STOP */
            }
            w->wu_t = scs_malloc(l * sizeof (scs_float));
            if (w->wu_t == SCS_NULL) {
                /* LCOV_EXCL_START */
                scs_special_print(print_mode, stderr, "ERROR: `wu_t` memory allocation failure\n");
                return SCS_NULL;
                /* LCOV_EXCL_STOP */
            }
            w->wu_b = scs_malloc(l * sizeof (scs_float));
            if (w->wu_b == SCS_NULL) {
                /* LCOV_EXCL_START */
                scs_special_print(print_mode, stderr, "ERROR: `wu_b` memory allocation failure\n");
                return SCS_NULL;
                /* LCOV_EXCL_STOP */
            }
        }
    } else {
        /* -------------------------------------
         * In SCS, the pointers which correspond to
         * SuperSCS are set to SCS_NULL and are
         * inactive.
         * ------------------------------------- */
        w->R = SCS_NULL;
        w->R_prev = SCS_NULL;
        w->dir = SCS_NULL;
        w->dut = SCS_NULL;
        w->s_b = SCS_NULL;
        w->direction_cache = SCS_NULL;
        w->Yk = SCS_NULL;
        w->Sk = SCS_NULL;
        w->wu = SCS_NULL;
        w->Rwu = SCS_NULL;
        w->wu_t = SCS_NULL;
        w->wu_b = SCS_NULL;
    }

    w->A = d->A;
    if (w->stgs->normalize) {
#ifdef COPYAMATRIX
        if (!copyAMatrix(&(w->A), d->A)) {
            /* LCOV_EXCL_START */
            scs_special_print(print_mode, stderr, "ERROR: copy A matrix failed\n");
            return SCS_NULL;
            /* LCOV_EXCL_STOP */
        }
#endif
        w->scal = scs_malloc(sizeof (ScsScaling));
        normalizeA(w->A, w->stgs, k, w->scal);
#if EXTRAVERBOSE > 0
        scs_print_array(w->scal->D, d->m, "D");
        scs_printf("norm D = %4f\n", scs_norm(w->scal->D, d->m));
        scs_print_array(w->scal->E, d->n, "E");
        scs_printf("norm E = %4f\n", scs_norm(w->scal->E, d->n));
#endif
    } else {
        w->scal = SCS_NULL;
    }
    if (!(w->coneWork = scs_init_conework(k))) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: initCone failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    w->p = initPriv(w->A, w->stgs);
    if (!w->p) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "ERROR: initPriv failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    return w;
}

static scs_int scs_update_work(
        const ScsData * RESTRICT d,
        ScsWork * RESTRICT w,
        const ScsSolution * RESTRICT sol) {
    /* before normalization */
    scs_int n = d->n;
    scs_int m = d->m;

    w->nm_b = scs_norm(d->b, m);
    w->nm_c = scs_norm(d->c, n);
    memcpy(w->b, d->b, d->m * sizeof (scs_float));
    memcpy(w->c, d->c, d->n * sizeof (scs_float));

#if EXTRAVERBOSE > 0
    scs_print_array(w->b, m, "b");
    scs_printf("pre-normalized norm b = %4f\n", scs_norm(w->b, m));
    scs_print_array(w->c, n, "c");
    scs_printf("pre-normalized norm c = %4f\n", scs_norm(w->c, n));
#endif
    if (w->stgs->normalize) {
        scs_normalize_bc(w);
#if EXTRAVERBOSE > 0
        scs_print_array(w->b, m, "bn");
        scs_printf("sc_b = %4f\n", w->sc_b);
        scs_printf("post-normalized norm b = %4f\n", scs_norm(w->b, m));
        scs_print_array(w->c, n, "cn");
        scs_printf("sc_c = %4f\n", w->sc_c);
        scs_printf("post-normalized norm c = %4f\n", scs_norm(w->c, n));
#endif
    }
    if (w->stgs->warm_start) {
        scs_warm_start_vars(w, sol);
    } else {
        scs_cold_start_vars(w);
    }
    memcpy(w->h, w->c, n * sizeof (scs_float));
    memcpy(&(w->h[n]), w->b, m * sizeof (scs_float));
    memcpy(w->g, w->h, (n + m) * sizeof (scs_float));
    scs_solve_lin_sys(w->A, w->stgs, w->p, w->g, SCS_NULL, -1);
    scs_scale_array(&(w->g[n]), -1, m);
    w->gTh = scs_inner_product(w->h, w->g, n + m);
    return 0;
}

scs_int scs_solve(
        ScsWork * RESTRICT w,
        const ScsData * RESTRICT d,
        const ScsCone * RESTRICT k,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info) {
    scs_int i;
    timer solveTimer;
    struct scs_residuals r;
    scs_int print_mode = w->stgs->do_override_streams;
    const scs_float max_runtime_millis = w->stgs->max_time_milliseconds;

    if (d == SCS_NULL
            || k == SCS_NULL
            || sol == SCS_NULL
            || info == SCS_NULL
            || w == SCS_NULL
            || d->b == SCS_NULL
            || d->c == SCS_NULL) {
        scs_special_print(print_mode, stderr, "ERROR: SCS_NULL input\n");
        return SCS_FAILED;
    }
    /* initialize ctrl-c support */
    startInterruptListener();
    scs_tic(&solveTimer);
    info->statusVal = SCS_UNFINISHED; /* not yet converged */
    r.last_iter = -1;
    scs_update_work(d, w, sol);

    if (w->stgs->verbose)
        scs_print_header(w, k);
    /* scs: */
    for (i = 0; i < w->stgs->max_iters && tocq(&solveTimer) < max_runtime_millis; ++i) {
        memcpy(w->u_prev, w->u, w->l * sizeof (scs_float));

        if (scs_project_lin_sys(w, i) < 0) {
            return scs_failure(w, w->m, w->n, sol, info, SCS_FAILED,
                    "error in projectLinSys", "Failure", print_mode);
        }
        if (scs_project_cones(w, k, i) < 0) {
            return scs_failure(w, w->m, w->n, sol, info, SCS_FAILED,
                    "error in projectCones", "Failure", print_mode);
        }

        scs_update_dual_vars(w);

        if (isInterrupted()) {
            return scs_failure(w, w->m, w->n, sol, info, SCS_SIGINT, "Interrupted",
                    "Interrupted", print_mode);
        }
        if (i % SCS_CONVERGED_INTERVAL == 0) {
            scs_calc_residuals(w, &r, i);
            if ((info->statusVal = scs_has_converged(w, &r, i)) != 0) {
                break;
            }
        }

        if (w->stgs->verbose && i % SCS_PRINT_INTERVAL == 0) {
            scs_calc_residuals(w, &r, i);
            scs_print_summary(w, i, &r, &solveTimer);
        }
    }
    if (w->stgs->verbose) {
        scs_calc_residuals(w, &r, i);
        scs_print_summary(w, i, &r, &solveTimer);
    }
    /* populate solution vectors (unnormalized) and info */
    scs_get_solution(w, sol, info, &r, i);
    info->solveTime = tocq(&solveTimer);

    if (w->stgs->verbose)
        scs_print_footer(d, k, sol, w, info); /* LCOV_EXCL_LINE */
    endInterruptListener();
    return info->statusVal;
}

static void scs_compute_sb_kapb(
        const scs_float * RESTRICT u,
        const scs_float * RESTRICT u_b,
        const scs_float * RESTRICT u_t,
        ScsWork * RESTRICT w) {
    scs_axpy(w->s_b, u_b + w->n, u_t + w->n, 1.0, -2.0, w->m);
    scs_add_array(w->s_b, u + w->n, w->m);
    w->kap_b = u_b[w->l - 1] - 2.0 * u_t[w->l - 1] + u[w->l - 1];
}

static scs_int scs_init_progress_data(ScsInfo * RESTRICT info, ScsWork * RESTRICT work) {
    /* --------------------------------------------------------------
     * As the might be successive calls to superSCS (superscs_solve)
     * with different values of `do_record_progress`, we nee to make
     * sure that we neither allocate memory for the same array twice,
     * nor do we set any arrays to SCS_NULL unnecessarily. Note that,
     * provided that `info` has  been initialized with scs_init_info (this
     * is highly recommended), all pointers are initially set to SCS_NULL.
     * -------------------------------------------------------------- */
    if (work->stgs->do_record_progress) {
        const scs_int max_history_alloc = work->stgs->max_iters;

        /* ----------------------------------------
         * If a pointer is SCS_NULL, it means that
         * no memory has been allocated for that
         * previously.
         * ---------------------------------------- */
        if (info->progress_relgap == SCS_NULL) {
            info->progress_relgap = malloc(sizeof (scs_float) * max_history_alloc);
            if (info->progress_relgap == SCS_NULL) return -1;
        }
        if (info->progress_respri == SCS_NULL) {
            info->progress_respri = malloc(sizeof (scs_float) * max_history_alloc);
            if (info->progress_respri == SCS_NULL) return -2;
        }
        if (info->progress_resdual == SCS_NULL) {
            info->progress_resdual = malloc(sizeof (scs_float) * max_history_alloc);
            if (info->progress_resdual == SCS_NULL) return -3;
        }
        if (info->progress_pcost == SCS_NULL) {
            info->progress_pcost = malloc(sizeof (scs_float) * max_history_alloc);
            if (info->progress_pcost == SCS_NULL) return -4;
        }
        if (info->progress_dcost == SCS_NULL) {
            info->progress_dcost = malloc(sizeof (scs_float) * max_history_alloc);
            if (info->progress_dcost == SCS_NULL) return -5;
        }
        if (info->progress_iter == SCS_NULL) {
            info->progress_iter = malloc(sizeof (scs_int) * max_history_alloc);
            if (info->progress_iter == SCS_NULL) return -6;
        }
        if (info->progress_norm_fpr == SCS_NULL) {
            info->progress_norm_fpr = malloc(sizeof (scs_float) * max_history_alloc);
            if (info->progress_norm_fpr == SCS_NULL) return -7;
        }
        if (info->progress_time == SCS_NULL) {
            info->progress_time = malloc(sizeof (scs_float) * max_history_alloc);
            if (info->progress_time == SCS_NULL) return -8;
        }
        if (info->progress_mode == SCS_NULL) {
            info->progress_mode = malloc(sizeof (scs_int) * max_history_alloc);
            if (info->progress_mode == SCS_NULL) return -9;
        }
        if (info->progress_ls == SCS_NULL) {
            info->progress_ls = malloc(sizeof (scs_int) * max_history_alloc);
            if (info->progress_ls == SCS_NULL) return -10;
        }

        /* ---------------------------------------------------------
         * If `do_record_progress` is true, and there has
         * been a previous allocation, but now the maximum
         * number of iterations has increased
         *
         * Note: if the current `max_iters` is smaller than
         * the previous value, it means that more than adequate
         * memory space has been allocated for the progress arrays.
         * However, we will not use `realloc` to size it down.
         * --------------------------------------------------------- */
        if (work->stgs->previous_max_iters != -1
                && max_history_alloc > work->stgs->previous_max_iters) {
            /* ------------------------------------
             * We don't check for NULL values here
             * because `realloc` on NULL pointers
             * behaves like `malloc`
             * ------------------------------------
             */
            info->progress_relgap = realloc(info->progress_relgap, sizeof (scs_float) * max_history_alloc);
            if (info->progress_relgap == SCS_NULL) return -100;

            info->progress_respri = realloc(info->progress_respri, sizeof (scs_float) * max_history_alloc);
            if (info->progress_respri == SCS_NULL) return -101;

            info->progress_resdual = realloc(info->progress_resdual, sizeof (scs_float) * max_history_alloc);
            if (info->progress_resdual == SCS_NULL) return -102;

            info->progress_pcost = realloc(info->progress_pcost, sizeof (scs_float) * max_history_alloc);
            if (info->progress_pcost == SCS_NULL) return -103;

            info->progress_dcost = realloc(info->progress_dcost, sizeof (scs_float) * max_history_alloc);
            if (info->progress_dcost == SCS_NULL) return -104;

            info->progress_iter = realloc(info->progress_iter, sizeof (scs_int) * max_history_alloc);
            if (info->progress_iter == SCS_NULL) return -105;

            info->progress_norm_fpr = realloc(info->progress_norm_fpr, sizeof (scs_float) * max_history_alloc);
            if (info->progress_norm_fpr == SCS_NULL) return -106;

            info->progress_time = realloc(info->progress_time, sizeof (scs_float) * max_history_alloc);
            if (info->progress_time == SCS_NULL) return -107;

            info->progress_mode = realloc(info->progress_mode, sizeof (scs_int) * max_history_alloc);
            if (info->progress_mode == SCS_NULL) return -108;

            info->progress_ls = realloc(info->progress_ls, sizeof (scs_int) * max_history_alloc);
            if (info->progress_ls == SCS_NULL) return -109;
        }
    }
    return 0;
}

static scs_int scs_step_k2(
        scs_float * RESTRICT dir,
        scs_float * RESTRICT Rwu,
        scs_float * RESTRICT u,
        scs_float nrmRw_con,
        ScsWork * RESTRICT work,
        scs_float rhox,
        scs_int n,
        scs_int m,
        scs_int l,
        scs_float alpha,
        scs_int * how) {

    scs_int do_break_loop = 0;
    scs_float slack;
    scs_float rhs;
    slack = nrmRw_con * nrmRw_con - work->stepsize * (
            scs_inner_product(dir + n, Rwu + n, m + 1)
            + rhox * scs_inner_product(dir, Rwu, n));
    rhs = work->stgs->sigma * work->nrmR_con * nrmRw_con;
    if (slack >= rhs) {
        scs_float stepsize2;
        stepsize2 = (alpha * (slack / (nrmRw_con * nrmRw_con)));
        scs_add_scaled_array(u, Rwu, l, -stepsize2);
        *how = 2;
        do_break_loop = 1;
    }
    return do_break_loop;
}

static scs_int scs_exit_loop_without_k1(
        ScsWork * RESTRICT work,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info,
        const ScsCone * RESTRICT cone,
        scs_float * RESTRICT u,
        scs_float * RESTRICT u_t,
        scs_float * RESTRICT u_b,
        scs_float * RESTRICT R,
        scs_float rhox,
        scs_int m,
        scs_int n,
        scs_int l,
        scs_int i,
        scs_int print_mode) {
    if (superscs_project_lin_sys(u_t, u, work, i) < 0) {
        return scs_failure(work, m, n, sol, info, SCS_FAILED,
                "error in projectLinSysv2", "Failure", print_mode);
    }
    if (superscs_project_cones(u_b, u_t, u, work, cone, i) < 0) { /* u_bar = proj_C(2u_t - u) */
        return scs_failure(work, m, n, sol, info, SCS_FAILED,
                "error in projectConesv2", "Failure", print_mode);
    }
    scs_compute_sb_kapb(u, u_b, u_t, work);
    scs_calc_FPR(R, u_t, u_b, l);
    work->nrmR_con = SQRTF(
            rhox * scs_norm_squared(R, n)
            + scs_norm_squared(R + n, m + 1)
            );
    return 0;
}

scs_int superscs_solve(
        ScsWork * RESTRICT work,
        const ScsData * RESTRICT data,
        const ScsCone * RESTRICT cone,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info) {
    scs_int i; /* i indexes the (outer) iterations */
    scs_int how = 0; /* -1:unsuccessful backtracking, 0:K0, 1:K1, 2:K2 */
    scs_float eta;
    scs_float nrm_R_0;
    scs_float r_safe;
    scs_float nrmRw_con; /* norm of FP res at line-search */
    scs_float nrmR_con_old; /* keeps previous FP res */
    scs_float q = work->stgs->sse;
    const scs_float max_runtime_millis = work->stgs->max_time_milliseconds;
    const scs_float rhox = work->stgs->rho_x;
    const scs_float sqrt_rhox = SQRTF(rhox);
    const scs_float q0 = work->stgs->sse;
    const scs_int n = work->n;
    const scs_int m = work->m;
    const scs_int l = work->l;
    timer solveTimer;
    struct scs_residuals r;
    scs_int print_mode = work->stgs->do_override_streams;
    /* ------------------------------------
     * Store some pointers in function-scope
     * variables for performance.
     * ------------------------------------ */
    ScsSettings * RESTRICT stgs = work->stgs;
    scs_float alpha = stgs->alpha;
    scs_float * RESTRICT dir = work->dir;
    scs_float * RESTRICT R = work->R;
    scs_float * RESTRICT R_prev = work->R_prev;
    scs_float * RESTRICT Rwu = work->Rwu;
    scs_float * RESTRICT u = work->u;
    scs_float * RESTRICT u_t = work->u_t;
    scs_float * RESTRICT u_b = work->u_b;
    scs_float * RESTRICT u_prev = work->u_prev;
    scs_float * RESTRICT wu = work->wu;
    scs_float * RESTRICT wu_t = work->wu_t;
    scs_float * RESTRICT wu_b = work->wu_b;
    scs_float * RESTRICT Sk = work->Sk;
    scs_float * RESTRICT Yk = work->Yk;
    scs_float * RESTRICT dut = work->dut;

    i = scs_init_progress_data(info, work);
    if (i < 0) {
        /* LCOV_EXCL_START */
        scs_special_print(print_mode, stderr, "Memory allocation error (progress arrays), code: %d\n", (int) i);
        return SCS_FAILED;
        /* LCOV_EXCL_STOP */
    }
    stgs->previous_max_iters = stgs->max_iters;

    if (data == SCS_NULL
            || cone == SCS_NULL
            || sol == SCS_NULL
            || info == SCS_NULL
            || work == SCS_NULL
            || data->b == SCS_NULL
            || data->c == SCS_NULL) {
        scs_special_print(print_mode, stderr, "ERROR: SCS_NULL input\n");
        return SCS_FAILED;
    }

    /* initialize ctrl-c support */
    startInterruptListener();
    scs_tic(&solveTimer);
    info->statusVal = SCS_UNFINISHED; /* not yet converged */
    r.last_iter = -1;
    scs_update_work(data, work, sol);

    if (stgs->verbose > 0)
        scs_print_header(work, cone);

    /* Initialize: */
    i = 0; /* Needed for the next two functions */
    if (superscs_project_lin_sys(u_t, u, work, i) < 0) { /* u_t = (I+Q)^{-1} u*/
        return scs_failure(work, m, n, sol, info, SCS_FAILED,
                "error in projectLinSysv2", "Failure", print_mode);
    }
    if (superscs_project_cones(u_b, u_t, u, work, cone, i) < 0) { /* u_bar = proj_C(2u_t - u) */
        return scs_failure(work, m, n, sol, info, SCS_FAILED,
                "error in projectConesv2", "Failure", print_mode);
    }
    scs_compute_sb_kapb(u, u_b, u_t, work); /* compute s_b and kappa_b */
    scs_calc_FPR(R, u_t, u_b, l); /* compute Ru */
    eta = SQRTF(
            rhox * scs_norm_squared(R, n)
            + scs_norm_squared(R + n, m + 1)
            ); /* initialize eta = |Ru^0| (norm of R using rho_x) */
    r_safe = eta;
    work->nrmR_con = eta;
    nrm_R_0 = MIN(1.0, eta);

    /* MAIN SUPER SCS LOOP */
    for (i = 0; i < stgs->max_iters && tocq(&solveTimer) < max_runtime_millis; ++i) {
        scs_int j = 0; /* j indexes the line search iterations */

        if (isInterrupted()) {
            return scs_failure(work, m, n, sol, info, SCS_SIGINT, "Interrupted",
                    "Interrupted", print_mode);
        }

        /* Convergence checks */
        if (i % SCS_CONVERGED_INTERVAL == 0) {
            scs_calc_residuals_superscs(work, &r, i);
            if (stgs->do_record_progress) {
                scs_int idx_progress = i / SCS_CONVERGED_INTERVAL;
                info->progress_iter[idx_progress] = i;
                info->progress_relgap[idx_progress] = r.rel_gap;
                info->progress_respri[idx_progress] = r.res_pri;
                info->progress_resdual[idx_progress] = r.res_dual;
                info->progress_pcost[idx_progress] = r.cTx_by_tau / r.tau;
                info->progress_dcost[idx_progress] = -r.bTy_by_tau / r.tau;
                info->progress_norm_fpr[idx_progress] = work->nrmR_con;
                info->progress_time[idx_progress] = tocq(&solveTimer);
            }
            if ((info->statusVal = scs_has_converged(work, &r, i))) {
                break;
            }
        }

        /* Prints results every PRINT_INTERVAL iterations */
        if (stgs->verbose && i % SCS_PRINT_INTERVAL == 0) {
            scs_calc_residuals_superscs(work, &r, i);
            scs_print_summary(work, i, &r, &solveTimer);
        }

        if (stgs->ls > 0 || stgs->k0 == 1) {
            q *= q0; /* q = q0^i */
            if (i == 0) {
                /* -------------------------------------------
                 * At i=0, the direction is defined using the
                 * FPR: dir^0 = -R
                 * -------------------------------------------- */
                scs_set_as_scaled_array(dir, R, -sqrt_rhox, n);
                scs_set_as_scaled_array(dir + n, R + n, -1, m + 1);

            } else {
                if (how == 0 || stgs->ls == 0) {
                    scs_axpy(Sk, u, u_prev, 1.0, -1.0, l); /* Sk = u - u_prev */
                    scs_axpy(Yk, R, R_prev, sqrt_rhox, -1.0, n); /* Yk = sqrt_rhox * R - R_prev */
                    scs_axpy(Yk + n, R + n, R_prev + n, 1.0, -1.0, m + 1);
                    scs_scale_array(Sk, sqrt_rhox, n); /* Sk *= sqrt_rhox */
                } else {
                    scs_axpy(Sk, wu, u_prev, sqrt_rhox, -sqrt_rhox, n);
                    scs_axpy(Sk + n, wu + n, u_prev + n, 1.0, -1.0, m + 1);
                    scs_axpy(Yk, Rwu, R_prev, sqrt_rhox, -1.0, n);
                    scs_axpy(Yk + n, Rwu + n, R_prev + n, 1.0, -1.0, m + 1);
                }

                scs_scale_array(R, sqrt_rhox, n); /* R *= sqrt_rhox */
                /* compute direction */
                if (scs_compute_direction(work, i) < 0) {
                    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                     * Function `scs_compute_direction` is invoked at iterations i>=1.
                     * At i=1, the first pair (S,Y) has been computed (see work).
                     *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                    return scs_failure(work, m, n, sol, info, SCS_FAILED,
                            "error in scs_compute_direction", "Failure", print_mode);
                }
                scs_scale_array(R, 1 / sqrt_rhox, n); /* R = R/sqrt_rhox */
            }
            /* -------------------------------------------
             * Scale the x-part of dir using sqrt_rhox
             * -------------------------------------------- */
            scs_scale_array(dir, 1 / sqrt_rhox, n);
        }

        memcpy(u_prev, u, l * sizeof (scs_float)); /* u_prev = u */
        memcpy(R_prev, R, l * sizeof (scs_float)); /* R_prev = R */
        scs_scale_array(R_prev, sqrt_rhox, n);
        how = -1; /* no backtracking (yet) */
        nrmR_con_old = work->nrmR_con;

        if (i >= stgs->warm_start) {
            if (stgs->k0 == 1 && work->nrmR_con <= stgs->c_bl * eta) {
                scs_add_array(u, dir, l); /* u += dir */
                how = 0;
                eta = work->nrmR_con;
                work->stepsize = 1.0;
            } else if (stgs->ls > 0) {
                if (superscs_project_lin_sys(dut, dir, work, i) < 0) {
                    return scs_failure(work, m, n, sol, info, SCS_FAILED, "error in projectLinSysv2", "Failure", print_mode);
                }
                work->stepsize = 2.0;

                /* Line search */
                for (j = 0; j < stgs->ls; ++j) {
                    work->stepsize *= stgs->beta;
                    scs_axpy(wu, u, dir, 1.0, work->stepsize, l); /* wu = u + step * dir */
                    scs_axpy(wu_t, u_t, dut, 1.0, work->stepsize, l); /* wut = u_t + step * dut */

                    if (superscs_project_cones(wu_b, wu_t, wu, work, cone, i) < 0) {
                        return scs_failure(work, m, n, sol, info, SCS_FAILED, "error in projectConesv2", "Failure", print_mode);
                    }
                    scs_calc_FPR(Rwu, wu_t, wu_b, l); /* calculate FPR on scaled vectors */

                    nrmRw_con = SQRTF(scs_norm_squared(Rwu + n, m + 1) + rhox * scs_norm_squared(Rwu, n));

                    /* K1 */
                    if (stgs->k1
                            && nrmRw_con <= stgs->c1 * nrmR_con_old
                            && work->nrmR_con <= r_safe) {

                        memcpy(u, wu, l * sizeof (scs_float)); /* u   = wu   */
                        memcpy(u_t, wu_t, l * sizeof (scs_float)); /* u_t = wu_t */
                        memcpy(u_b, wu_b, l * sizeof (scs_float)); /* u_b = wu_b */
                        memcpy(R, Rwu, l * sizeof (scs_float)); /* R   = Rw   */
                        scs_compute_sb_kapb(wu, wu_b, wu_t, work);
                        work->nrmR_con = nrmRw_con;
                        r_safe = work->nrmR_con + nrm_R_0 * q; /* The power already computed at the beginning of the main loop */
                        how = 1;
                        break;
                    }

                    /* K2 */
                    if (stgs->k2 && scs_step_k2(dir, Rwu, u, nrmRw_con, work, rhox, n, m, l, alpha, &how))
                        break;
                } /* end of line-search */
                j++; /* to get the number of LS iterations */
            } /* end of `else if` block (when !K1 OR no blind update) */
        } /* IF-block: iterated after warm start */

        if (how == -1) { /* means that R didn't change */
            /* x -= alpha*Rx */
            scs_add_scaled_array(u, R, l, -alpha);
        } /* how == -1 */
        if (how != 1) { /* exited with other than K1 */
            scs_int status = scs_exit_loop_without_k1(work, sol, info, cone, u, u_t, u_b, R, rhox, m, n, l, i, print_mode);
            if (status < 0)
                return status;
        } /* how != 1 */

        /* -------------------------------------------
         * Record some more progress information
         * -------------------------------------------*/
        if (stgs->do_record_progress && i % SCS_CONVERGED_INTERVAL == 0) {
            scs_int idx_progress = i / SCS_CONVERGED_INTERVAL;
            info->progress_mode[idx_progress] = how;
            info->progress_ls[idx_progress] = j;
        }

    } /* main for loop */

    scs_calc_residuals_superscs(work, &r, i);

    /* prints summary of last iteration */
    if (stgs->verbose) {
        scs_print_summary(work, i, &r, &solveTimer);
    }

    /* populate solution vectors (unnormalized) and info */
    /* update u, denormalize, etc */
    scs_get_solution(work, sol, info, &r, i);
    info->iter = i;
    info->solveTime = tocq(&solveTimer);
    info->history_length = i / SCS_CONVERGED_INTERVAL;

    if (stgs->verbose)
        scs_print_footer(data, cone, sol, work, info); /* LCOV_EXCL_LINE */
    endInterruptListener();

    return info->statusVal;
}

void scs_finish(ScsWork * RESTRICT w) {
    if (w) {
        scs_finish_cone(w->coneWork);
        if (w->stgs && w->stgs->normalize) {
#ifndef COPYAMATRIX
            unNormalizeA(w->A, w->stgs, w->scal);
#else
            freeAMatrix(w->A);
#endif
        }

        if (w->p)
            freePriv(w->p);
        scs_free_work(w);
    }
#if EXTRAVERBOSE > 0
    scs_printf("exit finish\n");
#endif
}

ScsWork * scs_init(
        const ScsData * RESTRICT d,
        const ScsCone * RESTRICT k,
        ScsInfo * RESTRICT info) {
#if EXTRAVERBOSE > 1
    scs_tic(&scs_global_timer);
#endif
    ScsWork * RESTRICT w;
    timer initTimer;
    startInterruptListener();
    if (d == SCS_NULL
            || k == SCS_NULL
            || info == SCS_NULL) {
        /* LCOV_EXCL_START */
        scs_special_print(d->stgs->do_override_streams, stderr, "ERROR: Missing Data, Cone or Info input\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
#if EXTRAVERBOSE > 0
    scs_print_data(d);
    scs_print_cone_data(k);
#endif
#ifndef NOVALIDATE
    if (scs_data_cone_validate(d, k) < 0) {
        scs_special_print(d->stgs->do_override_streams, stderr, "ERROR: Validation returned failure\n");
        return SCS_NULL;
    }
#endif
    scs_tic(&initTimer);
    w = scs_init_work(d, k);
    /* strtoc("init", &initTimer); */
    info->setupTime = tocq(&initTimer);
    if (d->stgs->verbose) {
        scs_special_print(w->stgs->do_override_streams,
                w->stgs->output_stream, "Setup time: %1.2es\n", info->setupTime / 1e3);
    }
    endInterruptListener();
    return w;
}

static void scs_compute_allocated_memory(
        const ScsWork * RESTRICT work,
        const ScsCone * RESTRICT k,
        const ScsData * RESTRICT data,
        ScsInfo * RESTRICT info) {
    blasint nMax = 0;
    long allocated_memory;
    scs_int i;
    scs_int float_size = sizeof (scs_float);
    scs_int int_size = sizeof (scs_int);
    scs_int l = data->m + data->n + 1;
    scs_int mem = work->stgs->memory;

    for (i = 0; i < k->ssize; ++i) {
        if (k->s[i] > nMax) {
            nMax = (blasint) k->s[i];
        }
    }

    allocated_memory =
            float_size * (2 * data->A->p[data->A->n]
            + 6 * data->m
            + 9 * data->n
            + k->qsize
            + k->psize
            + k->ssize
            + 2 * nMax * nMax
            + nMax
            + work->coneWork->lwork
            + 10 * l)
            + int_size * (2 * data->A->p[data->A->n]
            + data->n
            + work->coneWork->liwork
            + data->m + 2);

    if (work->stgs->ls > 0) {
        allocated_memory += float_size * 4 * l;
    }
    if ((work->stgs->direction == restarted_broyden
            || work->stgs->direction == restarted_broyden_v2)
            && mem > 0) {
        allocated_memory += float_size * 2 * l * (mem + 1);
    }
    if (work->stgs->direction == anderson_acceleration) {
        allocated_memory += float_size * (4 * l * mem + l
                + mem + scs_svd_workspace_size(l, mem));
    }

    if (work->stgs->normalize) {
        allocated_memory += float_size * (data->m + data->n);
    }
    info->allocated_memory = allocated_memory;
}

/* this just calls scs_init, scs_solve, and scs_finish */
scs_int scs(
        const ScsData * RESTRICT d,
        const ScsCone * RESTRICT k,
        ScsSolution * RESTRICT sol,
        ScsInfo * RESTRICT info) {
    scs_int status;
    /* --------------------------------------------------
     * Create a Work object. It may happen that scs_init
     * returns SCS_NULL (e.g., if some parameter is out
     * of range, or memory could not be allocated).
     * -------------------------------------------------- */
    ScsWork *w = scs_init(d, k, info);
    scs_int print_mode = d->stgs->do_override_streams;
    FILE * stream = d->stgs->output_stream;
    if (d->stgs->verbose >= 2) {
        char dir_string[15];
        switch (d->stgs->direction) {
            case anderson_acceleration:
                strncpy(dir_string, "anderson", 15);
                break;
            case restarted_broyden:
                strncpy(dir_string, "broyden", 15);
                break;
            case restarted_broyden_v2:
                strncpy(dir_string, "broyden_v2", 15);
                break;
            case fixed_point_residual:
                strncpy(dir_string, "fpr", 15);
                break;
            case full_broyden:
                strncpy(dir_string, "full broyden", 15);
                break;
            default:
                strncpy(dir_string, "unknown", 15);
        }

        /* LCOV_EXCL_START */
        scs_special_print(
                print_mode,
                stream,
                "Settings:\n"
                "alpha        : %g\n"
                "beta         : %g\n"
                "c1           : %g\n"
                "c_bl         : %g\n"
                "cg_rate      : %g\n"
                "dir          : %s\n"
                "do_super_scs : %d\n"
                "eps          : %g\n"
                "(k0, k1, k2) : (%d, %d, %d)\n"
                "ls           : %d\n"
                "max_iters    : %d\n"
                "memory       : %d\n"
                "normalize    : %d\n"
                "rho_x        : %g\n"
                "scale        : %g\n"
                "sigma        : %g\n"
                "sse          : %g\n"
                "thetabar     : %g\n"
                "warm_start   : %d\n",
                d->stgs->alpha,
                d->stgs->beta,
                d->stgs->c1,
                d->stgs->c_bl,
                d->stgs->cg_rate,
                dir_string,
                (int) d->stgs->do_super_scs,
                d->stgs->eps,
                (int) d->stgs->k0,
                (int) d->stgs->k1,
                (int) d->stgs->k2,
                (int) d->stgs->ls,
                (int) d->stgs->max_iters,
                (int) d->stgs->memory,
                (int) d->stgs->normalize,
                d->stgs->rho_x,
                d->stgs->scale,
                d->stgs->sigma,
                d->stgs->sse,
                d->stgs->thetabar,
                d->stgs->warm_start);
        /* LCOV_EXCL_STOP */
    }


#if EXTRAVERBOSE > 0
    scs_printf("size of scs_int = %lu, size of scs_float = %lu\n",
            sizeof (scs_int), sizeof (scs_float));
#endif
    if (w != SCS_NULL) {
        if (w->stgs->do_super_scs) {
            /* solve with SuperSCS*/
            if (w->stgs->verbose > 0) {
                scs_special_print(print_mode, stream, "Running SuperSCS...\n");
                scs_compute_allocated_memory(w, k, d, info);
                if (info->allocated_memory > 1e9) {
                    scs_special_print(print_mode, stream, "Memory: %4.2fGB\n", (double) info->allocated_memory / 1e9);
                } else if (info->allocated_memory > 1e6) {
                    scs_special_print(print_mode, stream, "Memory: %3.2fMB\n", (double) info->allocated_memory / 1e6);
                } else if (info->allocated_memory > 1e3) {
                    scs_special_print(print_mode, stream, "Memory: %3.2fkB\n", (double) info->allocated_memory / 1e3);
                } else {
                    scs_special_print(print_mode, stream, "Memory: %ld bytes\n", (double) info->allocated_memory);
                }
            }
            superscs_solve(w, d, k, sol, info);
        } else {
            /* solve with SCS */
            if (w->stgs->verbose > 0)
                scs_special_print(print_mode, stream, "Running Standard SCS...\n");
            scs_solve(w, d, k, sol, info);
        }
        status = info->statusVal;
    } else {
        status = scs_failure(SCS_NULL, d ? d->m : -1, d ? d->n : -1, sol, info,
                SCS_FAILED, "could not initialize work", "Failure", print_mode);
    }
    scs_finish(w);
    return status;
}

ScsSolution * scs_init_sol() {
    ScsSolution * RESTRICT sol = scs_calloc(1, sizeof (* sol));
    if (sol == SCS_NULL) {
        /* LCOV_EXCL_START */
        printf("ERROR: allocating sol failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    sol->s = SCS_NULL;
    sol->x = SCS_NULL;
    sol->y = SCS_NULL;
    return sol;
}

ScsInfo * scs_init_info() {
    ScsInfo * RESTRICT info = scs_calloc(1, sizeof (*info));
    if (info == SCS_NULL) {
        /* LCOV_EXCL_START */
        printf("ERROR: allocating info failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }
    info->pobj = NAN;
    info->dobj = NAN;
    info->iter = -1;
    info->relGap = NAN;
    info->resDual = NAN;
    info->resInfeas = NAN;
    info->resPri = NAN;
    info->resUnbdd = NAN;
    info->setupTime = NAN;
    info->solveTime = NAN;
    info->statusVal = SCS_INDETERMINATE;
    info->progress_iter = SCS_NULL;
    info->progress_dcost = SCS_NULL;
    info->progress_pcost = SCS_NULL;
    info->progress_relgap = SCS_NULL;
    info->progress_resdual = SCS_NULL;
    info->progress_respri = SCS_NULL;
    info->progress_norm_fpr = SCS_NULL;
    info->progress_time = SCS_NULL;
    info->progress_mode = SCS_NULL;
    info->progress_ls = SCS_NULL;
    return info;
}

ScsData * scs_init_data() {
    ScsData * RESTRICT data = malloc(sizeof (*data));

    if (data == SCS_NULL) {
        /* LCOV_EXCL_START */
        printf("ERROR: allocating data failure\n");
        return SCS_NULL;
        /* LCOV_EXCL_STOP */
    }

    data->A = SCS_NULL;
    data->b = SCS_NULL;
    data->c = SCS_NULL;
    data->m = 0;
    data->n = 0;

    data->stgs = scs_malloc(sizeof (ScsSettings));
    scs_set_default_settings(data);

    return data;
}

static void scs_reset_cone(ScsCone * cone) {
    cone->ssize = 0;
    cone->ed = 0;
    cone->ep = 0;
    cone->f = 0;
    cone->l = 0;
    cone->psize = 0;
    cone->ssize = 0;
    cone->qsize = 0;
    cone->q = SCS_NULL;
    cone->p = SCS_NULL;
    cone->s = SCS_NULL;
}

static const char SCS_EOL = '\n';
#define SCS_YAML_CHAR_LEN 64
static const char SCS_YAML_problem[] = "problem";
static const char SCS_YAML_m[] = "m";
static const char SCS_YAML_n[] = "n";
static const char SCS_YAML_nnz[] = "nnz";
static const char SCS_YAML_Matrix_A[] = "A";
static const char SCS_YAML_Matrix_A_a[] = "a";
static const char SCS_YAML_Matrix_A_I[] = "I";
static const char SCS_YAML_Matrix_A_J[] = "J";
static const char SCS_YAML_Vector_b[] = "b";
static const char SCS_YAML_Vector_c[] = "c";
static const char SCS_YAML_Cone_K[] = "K";
static const char SCS_YAML_ConeField_ep[] = "ep";
static const char SCS_YAML_ConeField_ed[] = "ed";
static const char SCS_YAML_ConeField_f[] = "f";
static const char SCS_YAML_ConeField_l[] = "l";
static const char SCS_YAML_ConeField_p[] = "p";
static const char SCS_YAML_ConeField_q[] = "q";
static const char SCS_YAML_ConeField_s[] = "s";
static const char SCS_YAML_ConeField_psize[] = "psize";
static const char SCS_YAML_ConeField_qsize[] = "qsize";
static const char SCS_YAML_ConeField_ssize[] = "ssize";

static char scs_yaml_variable_name[SCS_YAML_CHAR_LEN];

static void scs_yaml_clear_char_array(void) {
    memset(scs_yaml_variable_name, 0, SCS_YAML_CHAR_LEN * sizeof (char));
}

static void scs_yaml_skip_to_end_of_line(FILE * fp) {
    int c;
    while ((c = fgetc(fp)) != EOF && c != SCS_EOL);
}

static char * scs_yaml_get_variable_name(FILE * fp) {
    scs_yaml_clear_char_array();
    int c;
    size_t k = 0;
    char colon = ':';
    char hash = '#';
    char begin_yaml[] = "---";
    char end_yaml[] = "...";

    /* read the first three characters (unless a hash is found - then stop) */
    while (k < 3 && (c = fgetc(fp)) != EOF && c != colon && c != hash)
        if (c != ' ' && c != '\n') scs_yaml_variable_name[k++] = (char) c;

    /* check whether the first three chars are --- or ... */
    if (strcmp(begin_yaml, scs_yaml_variable_name) == 0
            || strcmp(end_yaml, scs_yaml_variable_name) == 0) {
        scs_yaml_skip_to_end_of_line(fp); /* skip to the end of the line */
        return SCS_NULL;
    }

    if (c == hash) {
        scs_yaml_skip_to_end_of_line(fp); /* skip to the end of the line */
        return SCS_NULL;
    }
    if (c == colon) return scs_yaml_variable_name;

    /* read the rest */
    while ((c = fgetc(fp)) != EOF && c != colon)
        if (c != ' ') scs_yaml_variable_name[k++] = (char) c;

    return scs_yaml_variable_name; /* variable name */
}

static void scs_yaml_skip_to_problem(FILE * fp) {
    char * var_name;
    while (!feof(fp)) {
        var_name = scs_yaml_get_variable_name(fp);
        if (var_name != SCS_NULL) {
            scs_yaml_skip_to_end_of_line(fp);
            if (strcmp(var_name, SCS_YAML_problem) == 0) break;
        }
    }
}

static size_t scs_yaml_read_size_t(FILE * fp) {
    size_t value_in_yaml;
    int status;
    status = fscanf(fp, "%zu", &value_in_yaml);
    if (status <= 0) value_in_yaml = 0;
    return value_in_yaml;
}

static scs_float scs_yaml_read_numeric(FILE * fp) {
    scs_float value_in_yaml;
    int status;
    status = fscanf(fp, "%lf", &value_in_yaml);
    if (status <= 0) value_in_yaml = 0;
    return value_in_yaml;
}

static void scs_yaml_discover_matrix_sizes(FILE * fp, ScsData * data, scs_int * nnz) {
    size_t k = 0;
    char * var_name;
    while (k++ < 6 && !feof(fp)) {
        var_name = scs_yaml_get_variable_name(fp);
        if (var_name == SCS_NULL) {
            k--;
            continue;
        }
        if (strcmp(var_name, SCS_YAML_m) == 0) {
            data->m = scs_yaml_read_size_t(fp);
        } else if (strcmp(var_name, SCS_YAML_n) == 0) {
            data->n = scs_yaml_read_size_t(fp);
        } else if (strcmp(var_name, SCS_YAML_nnz) == 0) {
            *nnz = scs_yaml_read_size_t(fp);
        }
        scs_yaml_skip_to_end_of_line(fp);
    }
}

static void scs_yaml_discover_cone_sizes(FILE * fp, ScsCone * cone) {
    size_t k = 0;
    char * var_name = SCS_NULL;
    while (k++ < 10 && !feof(fp)) {
        var_name = scs_yaml_get_variable_name(fp);
        if (var_name == SCS_NULL) {
            k--;
            continue;
        }
        if (strcmp(var_name, SCS_YAML_ConeField_psize) == 0) {
            cone->psize = scs_yaml_read_size_t(fp);
        } else if (strcmp(var_name, SCS_YAML_ConeField_qsize) == 0) {
            cone->qsize = scs_yaml_read_size_t(fp);
        } else if (strcmp(var_name, SCS_YAML_ConeField_ssize) == 0) {
            cone->ssize = scs_yaml_read_size_t(fp);
        }
        scs_yaml_skip_to_end_of_line(fp);
    }
}

static int scs_yaml_discover_sizes(
        FILE * fp,
        ScsData * data,
        ScsCone * cone,
        scs_int * nnz) {

    int checkpoints = 0;
    /* fast-forward to the problem */
    scs_yaml_skip_to_problem(fp);

    /* parse the problem */
    while (!feof(fp)) {
        scs_yaml_get_variable_name(fp);
        scs_yaml_skip_to_end_of_line(fp);
        if (scs_yaml_variable_name == SCS_NULL) continue;
        if (strcmp(scs_yaml_variable_name, SCS_YAML_Matrix_A) == 0) {
            checkpoints++;
            scs_yaml_discover_matrix_sizes(fp, data, nnz);
        } else if (strcmp(scs_yaml_variable_name, SCS_YAML_Cone_K) == 0) {
            checkpoints++;
            scs_yaml_discover_cone_sizes(fp, cone);
        }
    }
    return checkpoints == 2 ? 0 : 1;
}

static int scs_yaml_initialise_data_and_cone(ScsData * data, ScsCone * cone, scs_int nnz) {
    if (data == SCS_NULL || cone == SCS_NULL) return 700;
    if (data->m <= 0) return 701;
    if (data->n <= 0) return 702;
    if (cone->psize < 0) return 703;
    if (cone->qsize < 0) return 704;
    if (cone->ssize < 0) return 705;

    /* initialise matrix `A` */
    data->A = scs_malloc(sizeof (AMatrix));
    if (data->A == SCS_NULL) goto yaml_init_error_0;
    data->A->m = data->m;
    data->A->n = data->n;
    data->A->i = scs_malloc(nnz * sizeof (scs_int));
    if (data->A->i == SCS_NULL) goto yaml_init_error_1;
    data->A->p = scs_malloc((data->n + 1) * sizeof (scs_int));
    if (data->A->p == SCS_NULL) goto yaml_init_error_2;
    data->A->x = scs_malloc(nnz * sizeof (scs_float));
    if (data->A->x == SCS_NULL) goto yaml_init_error_3;

    /* initialise `b` and `c` */
    data->b = scs_malloc(data->m * sizeof (scs_float));
    if (data->b == SCS_NULL) goto yaml_init_error_4;
    data->c = scs_malloc(data->n * sizeof (scs_float));
    if (data->c == SCS_NULL) goto yaml_init_error_5;

    /* initialise `cone` */
    cone->p = scs_malloc(cone->psize * sizeof (scs_float));
    if (cone->psize > 0 && cone->p == SCS_NULL) goto yaml_init_error_6;
    cone->q = scs_malloc(cone->qsize * sizeof (scs_int));
    if (cone->qsize > 0 && cone->q == SCS_NULL) goto yaml_init_error_7;
    cone->s = scs_malloc(cone->ssize * sizeof (scs_int));
    if (cone->ssize && cone->s == SCS_NULL) goto yaml_init_error_8;

    return 0;

    /* LCOV_EXCL_START */
yaml_init_error_8:
    scs_free(cone->q);
yaml_init_error_7:
    scs_free(cone->p);
yaml_init_error_6:
    scs_free(data->c);
yaml_init_error_5:
    scs_free(data->b);
yaml_init_error_4:
    scs_free(data->A->x);
yaml_init_error_3:
    scs_free(data->A->p);
yaml_init_error_2:
    scs_free(data->A->i);
yaml_init_error_1:
    scs_free(data->A);
yaml_init_error_0:
    return 1;
    /* LCOV_EXCL_STOP */
}

static int scs_yaml_parse_int_array(FILE * fp, scs_int * array, size_t len) {
    int temp;
    size_t i;
    if (fscanf(fp, " [ %d", &temp) == 0) return 1;
    array[0] = temp;
    for (i = 0; i < len - 1; ++i) {
        if (fscanf(fp, " , %d", &temp) == 0) return 1;
        array[i + 1] = temp;
    }
    return 0;
}

static int scs_yaml_parse_float_array(FILE * fp, scs_float * array, size_t len) {
    size_t i;
    if (fscanf(fp, " [ %lf ", array) == 0) return 1;
    for (i = 0; i < len - 1; ++i)
        if (fscanf(fp, " , %lf ", array + i + 1) == 0) return 1;
    return 0;
}

static int scs_yaml_parse_matrix_A(FILE * fp, ScsData * data, scs_int nonzeroes) {
    /* parse matrix A */
    size_t k = 0;
    int checkpoints = 0;
    char * var_name;
    while (k++ < 6 && !feof(fp)) {
        var_name = scs_yaml_get_variable_name(fp);
        if (var_name == SCS_NULL) {
            k--;
            continue;
        }
        if (strcmp(var_name, SCS_YAML_Matrix_A_I) == 0) {
            checkpoints++;
            if (scs_yaml_parse_int_array(fp, data->A->p, data->n + 1)) return 1;
        } else if (strcmp(var_name, SCS_YAML_Matrix_A_J) == 0) {
            checkpoints++;
            if (scs_yaml_parse_int_array(fp, data->A->i, nonzeroes)) return 1;
        } else if (strcmp(var_name, SCS_YAML_Matrix_A_a) == 0) {
            checkpoints++;
            if (scs_yaml_parse_float_array(fp, data->A->x, nonzeroes)) return 1;
        }
        scs_yaml_skip_to_end_of_line(fp);
    }
    return checkpoints == 3 ? 0 : 2;
}

static int scs_yaml_parse_cone_K(FILE * fp, ScsCone * cone) {
    size_t k = 0;
    char * var_name = SCS_NULL;
    while (k++ < 10 && !feof(fp)) {
        var_name = scs_yaml_get_variable_name(fp);
        if (var_name == SCS_NULL) {
            k--;
            continue;
        }
        if (strcmp(var_name, SCS_YAML_ConeField_f) == 0) {
            cone->f = scs_yaml_read_size_t(fp);
        } else if (strcmp(var_name, SCS_YAML_ConeField_l) == 0) {
            cone->l = scs_yaml_read_size_t(fp);
        } else if (strcmp(var_name, SCS_YAML_ConeField_ep) == 0) {
            cone->ep = scs_yaml_read_size_t(fp);
        } else if (strcmp(var_name, SCS_YAML_ConeField_ed) == 0) {
            cone->ed = scs_yaml_read_size_t(fp);
        } else if (strcmp(var_name, SCS_YAML_ConeField_q) == 0) {
            if (cone->qsize == 1) {
                cone->q[0] = (scs_int) scs_yaml_read_size_t(fp);
            } else if (cone->qsize > 1) {
                if (scs_yaml_parse_int_array(fp, cone->q, cone->qsize)) return 1;
            }
        } else if (strcmp(var_name, SCS_YAML_ConeField_p) == 0) {
            if (cone->psize == 1) {
                cone->p[0] = scs_yaml_read_numeric(fp);
            } else if (cone->psize > 1) {
                if (scs_yaml_parse_float_array(fp, cone->p, cone->psize)) return 1;
            }
        } else if (strcmp(var_name, SCS_YAML_ConeField_s) == 0) {
            if (cone->ssize == 1) {
                cone->s[0] = (scs_int) scs_yaml_read_size_t(fp);
            } else if (cone->ssize > 1) {
                if (scs_yaml_parse_int_array(fp, cone->s, cone->ssize)) return 1;
            }
        }
        scs_yaml_skip_to_end_of_line(fp);
    }
    return 0;
}

static int scs_yaml_parse_data_and_cone(
        FILE * fp,
        ScsData * data,
        ScsCone * cone,
        scs_int nonzeroes) {
    /* fast-forward to the problem */
    scs_yaml_skip_to_problem(fp);

    /* parse the problem */
    while (!feof(fp)) {
        scs_yaml_get_variable_name(fp);
        if (strcmp(scs_yaml_variable_name, SCS_YAML_Matrix_A) == 0) {
            scs_yaml_skip_to_end_of_line(fp);
            if (scs_yaml_parse_matrix_A(fp, data, nonzeroes)) return 1;
        } else if (strcmp(scs_yaml_variable_name, SCS_YAML_Cone_K) == 0) {
            scs_yaml_skip_to_end_of_line(fp);
            if (scs_yaml_parse_cone_K(fp, cone)) return 1;
        } else if (strcmp(scs_yaml_variable_name, SCS_YAML_Vector_b) == 0) {
            if (scs_yaml_parse_float_array(fp, data->b, data->m)) return 1;
            scs_yaml_skip_to_end_of_line(fp);
        } else if (strcmp(scs_yaml_variable_name, SCS_YAML_Vector_c) == 0) {
            if (scs_yaml_parse_float_array(fp, data->c, data->n)) return 1;
            scs_yaml_skip_to_end_of_line(fp);
        } else {
            scs_yaml_skip_to_end_of_line(fp);
        }
    }
    return 0;

}

scs_int scs_from_YAML(
        const char * filepath,
        ScsData ** data,
        ScsCone ** cone) {

    FILE *fp = SCS_NULL;
    scs_int status;
    scs_int nonzeroes;

    nonzeroes = 0;
    status = 0;

    *data = scs_init_data();
    if (data == SCS_NULL) {
        status = 501;
        goto exit_error_1;
    }

    *cone = malloc(sizeof (ScsCone));
    scs_reset_cone(*cone);
    if (cone == SCS_NULL) {
        status = 502;
        goto exit_error_2;
    }

    fp = fopen(filepath, "r");

    if (fp == NULL) {
        status = 1000;
        goto exit_error_2;
    }


    /* first we need to know the sizes */
    if (scs_yaml_discover_sizes(fp, *data, *cone, &nonzeroes)) {
        status = 101;
        goto exit_error_2;
    }

    /* we know the dimensions - initialise `data` and `cone` */
    if ((status = scs_yaml_initialise_data_and_cone(*data, *cone, nonzeroes)))
        goto exit_error_2;

    /* rewind file */
    rewind(fp);

    /* parse `data` and `cone` */
    if (scs_yaml_parse_data_and_cone(fp, *data, *cone, nonzeroes)) {
        status = 103;
        goto exit_error_2;
    }

    if (fp != SCS_NULL) {
        if (0 != fclose(fp)) {
            status = 224;
        }
    }
    return status;

    /* LCOV_EXCL_START */
exit_error_2:
    scs_free_data(*data, *cone);
exit_error_1:
    if (fp != SCS_NULL)
        fclose(fp);
    return status;
    /* LCOV_EXCL_STOP */
}

static int scs_double_num_digits = 17;
static char scs_yaml_space[] = "    ";
static char scs_yaml_double_space[] = "        ";

static void scs_serialize_array_to_YAML(
        FILE * RESTRICT fp,
        void * array,
        scs_int len,
        scs_int is_array_int
        ) {
    size_t i;
    fprintf(fp, "[");
    if (len > 0) {
        if (is_array_int) {
            scs_int * int_array = (scs_int *) array;
            for (i = 0; i < len - 1; ++i) {
                fprintf(fp, "%d,", (int) int_array[i]);
            }
            fprintf(fp, "%d", (int) int_array[len - 1]);
        } else {
            scs_float * float_array = (scs_float *) array;
            for (i = 0; i < len - 1; ++i) {
                fprintf(fp, "%.*g,", scs_double_num_digits, (double) float_array[i]);
            }
            fprintf(fp, "%.*g", scs_double_num_digits, (double) float_array[len - 1]);
        }
    }
    fprintf(fp, "]\n");
}

static void scs_serialize_sparse_matrix_to_YAML(
        FILE * RESTRICT fp,
        const AMatrix * RESTRICT matrix) {
    scs_int num_nonzeroes = matrix->p[matrix->n];
    fprintf(fp, "%sA:\n", scs_yaml_space);
    fprintf(fp, "%sm: %d\n", scs_yaml_double_space, (int) matrix->m);
    fprintf(fp, "%sn: %d\n", scs_yaml_double_space, (int) matrix->n);
    fprintf(fp, "%snnz: %d\n", scs_yaml_double_space, (int) num_nonzeroes);
    fprintf(fp, "%sa: ", scs_yaml_double_space);
    scs_serialize_array_to_YAML(fp, matrix->x, num_nonzeroes, 0);
    fprintf(fp, "%sI: ", scs_yaml_double_space);
    scs_serialize_array_to_YAML(fp, matrix->p, matrix->n + 1, 1);
    fprintf(fp, "%sJ: ", scs_yaml_double_space);
    scs_serialize_array_to_YAML(fp, matrix->i, num_nonzeroes, 1);
}

static void scs_serialize_vectors_to_YAML(
        FILE * RESTRICT fp,
        const ScsData * RESTRICT data) {
    fprintf(fp, "%sb: ", scs_yaml_space);
    scs_serialize_array_to_YAML(fp, data->b, data->m, 0);
    fprintf(fp, "%sc: ", scs_yaml_space);
    scs_serialize_array_to_YAML(fp, data->c, data->n, 0);
}

static void scs_serialize_cone_to_YAML(
        FILE * RESTRICT fp,
        const ScsCone * RESTRICT cone) {
    fprintf(fp, "%sK:\n", scs_yaml_space);
    fprintf(fp, "%spsize: %d\n", scs_yaml_double_space, (int) cone->psize);
    fprintf(fp, "%sqsize: %d\n", scs_yaml_double_space, (int) cone->qsize);
    fprintf(fp, "%sssize: %d\n", scs_yaml_double_space, (int) cone->ssize);
    fprintf(fp, "%sf: %d\n", scs_yaml_double_space, (int) cone->f);
    fprintf(fp, "%sl: %d\n", scs_yaml_double_space, (int) cone->l);
    fprintf(fp, "%sep: %d\n", scs_yaml_double_space, (int) cone->ep);
    fprintf(fp, "%sed: %d\n", scs_yaml_double_space, (int) cone->ed);
    if (cone->qsize == 1) {
        fprintf(fp, "%sq: %d\n", scs_yaml_double_space, (int) cone->q[0]);
    } else {
        fprintf(fp, "%sq: ", scs_yaml_double_space);
        scs_serialize_array_to_YAML(fp, cone->q, cone->qsize, 1);
    }
    if (cone->psize == 1) {
        fprintf(fp, "%sp: %.*g\n", scs_yaml_double_space, scs_double_num_digits,
                (double) cone->p[0]);
    } else {
        fprintf(fp, "%sp: ", scs_yaml_double_space);
        scs_serialize_array_to_YAML(fp, cone->p, cone->psize, 0);
    }
    if (cone->ssize == 1) {
        fprintf(fp, "%ss: %d\n", scs_yaml_double_space, (int) cone->s[0]);
    } else {
        fprintf(fp, "%ss: ", scs_yaml_double_space);
        scs_serialize_array_to_YAML(fp, cone->s, cone->ssize, 1);
    }
}

scs_int scs_to_YAML(
        const char * RESTRICT filepath,
        ScsConicProblemMetadata * metadata,
        const ScsData * RESTRICT data,
        const ScsCone * RESTRICT cone) {
    scs_int status = 0;
    FILE *fp = SCS_NULL;
    scs_int should_free_metadata = 0;

    if (data == SCS_NULL) return 501;
    if (cone == SCS_NULL) return 502;
    if (filepath == SCS_NULL) return 503;

    if (metadata == SCS_NULL) {
        metadata = scs_init_conic_problem_metadata("anonymous-conic-problem");
        if (metadata == SCS_NULL) return 600;
        should_free_metadata = 1;
    }

    fp = fopen(filepath, "w");

    if (fp == NULL) {
        status = 101;
        goto to_yaml_exit_0;
    }
    fprintf(fp, "--- # SuperSCS Problem\nmeta:\n");
    fprintf(fp, "%sid: '%s'\n", scs_yaml_space, metadata->id);
    fprintf(fp, "%screator: '%s'\n", scs_yaml_space, metadata->creator);
    fprintf(fp, "%syamlVersion: '%s'\n", scs_yaml_space, metadata->yamlVersion);
    fprintf(fp, "%slicense: '%s'\n", scs_yaml_space, metadata->license);
    fprintf(fp, "%sdate: '%s'\n", scs_yaml_space, metadata->date);
    fprintf(fp, "problem:\n");
    fprintf(fp, "%sname: '%s'\n", scs_yaml_space, metadata->problemName);
    scs_serialize_sparse_matrix_to_YAML(fp, data->A);
    scs_serialize_vectors_to_YAML(fp, data);
    scs_serialize_cone_to_YAML(fp, cone);
    fprintf(fp, "...");

to_yaml_exit_0:
    if (fp != SCS_NULL) {
        if (fclose(fp) != 0) {
            status = 250;
        }
    }
    if (should_free_metadata) {
        scs_free(metadata);
    }
    return status;
}

ScsConicProblemMetadata * scs_init_conic_problem_metadata(const char * problemName) {
    ScsConicProblemMetadata * metadata = SCS_NULL;
    metadata = scs_malloc(sizeof (*metadata));
    if (metadata == SCS_NULL) return SCS_NULL;
    strncpy(metadata->license,
            "https://github.com/kul-forbes/scs/blob/master/LICENSE.txt",
            SCS_METADATA_TEXT_SIZE);
    strncpy(metadata->problemName, problemName, SCS_METADATA_TEXT_SIZE);
    snprintf(metadata->id, SCS_METADATA_TEXT_SIZE, "http://superscs.org/problem/%s", problemName);
    snprintf(metadata->creator, SCS_METADATA_TEXT_SIZE, "%s", scs_version());
    time_t t = time(NULL);
    struct tm date_time_now = *localtime(&t);
    snprintf(metadata->date, SCS_METADATA_TEXT_SIZE,
            "%d-%d-%d %d:%d:%d [%s]",
            date_time_now.tm_year + 1900,
            date_time_now.tm_mon + 1,
            date_time_now.tm_mday,
            date_time_now.tm_hour,
            date_time_now.tm_min,
            date_time_now.tm_sec,
            date_time_now.tm_zone);
    snprintf(metadata->yamlVersion, SCS_METADATA_TEXT_SIZE, "1.2");
    return metadata;
}
