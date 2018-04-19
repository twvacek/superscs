#ifndef COMMON_H_GUARD
#define COMMON_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include "scs.h"
#include "amatrix.h"

void scs_accum_by_a_trans__(scs_int n, scs_float *Ax, scs_int *Ai, scs_int *Ap,
                    const scs_float *x, scs_float *y);
void scs_accum_by_a__(scs_int n, scs_float *Ax, scs_int *Ai, scs_int *Ap,
               const scs_float *x, scs_float *y);

void scs_print_a_matrix(const ScsAMatrix *A);

#ifdef __cplusplus
}
#endif

#endif
