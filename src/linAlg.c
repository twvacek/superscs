#include "linAlg.h"
#include <math.h>
#include <stdio.h>


#ifdef LAPACK_LIB_FOUND

#define SCS_NO_SUFFIX 
#define SCS_IAMAX stitch__(i, BLAS(amax), SCS_NO_SUFFIX)

extern blasint SCS_IAMAX(
        const blasint *n,
        const scs_float *x,
        const blasint *inc_x);

extern scs_float BLAS(nrm2)(
        const blasint *n,
        const scs_float *x,
        const blasint *incx);

/* y += ax */
extern void BLAS(axpy)(
        const blasint* n,
        const scs_float* alpha,
        const scs_float* x,
        const blasint* inc_x,
        scs_float* y,
        const blasint* inc_y);

extern void BLAS(scal)(
        const blasint* n,
        const scs_float* alpha,
        scs_float* x,
        const blasint* inc_x);

extern scs_float BLAS(dot)(
        const blasint* n,
        const scs_float* x,
        const blasint* inc_x,
        const scs_float* y,
        const blasint* inc_y);

extern void BLAS(gemm)(
        const char* trans_a,
        const char* trans_b,
        const blasint* m,
        const blasint* n,
        const blasint* k,
        const scs_float* alpha,
        const scs_float* A,
        const blasint* lda,
        const scs_float* B,
        const blasint* ldb,
        const scs_float* beta,
        scs_float* C,
        const blasint* ldc);

extern void LPCK(gels)(
        const char* trans,
        const blasint* m,
        const blasint* n,
        const blasint* nrhs,
        const scs_float* a,
        const blasint* lda,
        scs_float* b,
        const blasint* ldb,
        scs_float* work,
        blasint* lwork,
        blasint* info);

extern void LPCK(gelss)(
        const blasint* m,
        const blasint* n,
        const blasint* nrhs,
        const scs_float* A,
        const blasint* lda,
        scs_float* b,
        const blasint* ldb,
        scs_float* S,
        const scs_float* rcond,
        blasint* rank,
        scs_float* work,
        blasint* lwork,
        blasint* info);

#define __scs_iamax SCS_IAMAX
#define __scs_nrm2  BLAS(nrm2)
#define __scs_axpy  BLAS(axpy)
#define __scs_scal  BLAS(scal)
#define __scs_dot  BLAS(dot)
#define __scs_gemm BLAS(gemm)
#define __scs_gels LPCK(gels)
#define __scs_dgelss LPCK(gelss)
#endif

/* static void printVec(char** name, int len, scs_float* x) {
    int i;
    for (i = 0; i < len; ++i) {
         printf("%s[%d]=%g\n", name, i, x[i]);
    }
    printf("\n");
}*/

/* LCOV_EXCL_START */
#define __DGEMM_NN_MC  384
#define __DGEMM_NN_KC  384
#define __DGEMM_NN_NC  4096

#define __DGEMM_NN_MR  4
#define __DGEMM_NN_NR  4

/* 
 *   Local buffers for storing panels from A, B and C
 */
static double __DGEMM_NN__A[__DGEMM_NN_MC*__DGEMM_NN_KC];
static double __DGEMM_NN__B[__DGEMM_NN_KC*__DGEMM_NN_NC];
static double __DGEMM_NN__C[__DGEMM_NN_MR*__DGEMM_NN_NR];

/*
 *  Packing complete panels from A (i.e. without padding)
 */
static void
_dgemm_nn_pack_MRxk(int k, const double *A, int incRowA, int incColA,
        double *buffer) {
    int i, j;

    for (j = 0; j < k; ++j) {
        for (i = 0; i < __DGEMM_NN_MR; ++i) {
            buffer[i] = A[i * incRowA];
        }
        buffer += __DGEMM_NN_MR;
        A += incColA;
    }
}

/*
 *  Packing panels from A with padding if required
 */
static void
_dgemm_nn_pack_A(int mc, int kc, const double *A, int incRowA, int incColA,
        double *buffer) {
    int mp = mc / __DGEMM_NN_MR;
    int _mr = mc % __DGEMM_NN_MR;

    int i, j;

    for (i = 0; i < mp; ++i) {
        _dgemm_nn_pack_MRxk(kc, A, incRowA, incColA, buffer);
        buffer += kc*__DGEMM_NN_MR;
        A += __DGEMM_NN_MR*incRowA;
    }
    if (_mr > 0) {
        for (j = 0; j < kc; ++j) {
            for (i = 0; i < _mr; ++i) {
                buffer[i] = A[i * incRowA];
            }
            for (i = _mr; i < __DGEMM_NN_MR; ++i) {
                buffer[i] = 0.0;
            }
            buffer += __DGEMM_NN_MR;
            A += incColA;
        }
    }
}

/*
 *  Packing complete panels from B (i.e. without padding)
 */
static void
_dgemm_nn_pack_kxNR(int k, const double *B, int incRowB, int incColB,
        double *buffer) {
    int i, j;

    for (i = 0; i < k; ++i) {
        for (j = 0; j < __DGEMM_NN_NR; ++j) {
            buffer[j] = B[j * incColB];
        }
        buffer += __DGEMM_NN_NR;
        B += incRowB;
    }
}

/*
 *  Packing panels from B with padding if required
 */
static void
_dgemm_nn_pack_B(int kc, int nc, const double *B, int incRowB, int incColB,
        double *buffer) {
    int np = nc / __DGEMM_NN_NR;
    int _nr = nc % __DGEMM_NN_NR;

    int i, j;

    for (j = 0; j < np; ++j) {
        _dgemm_nn_pack_kxNR(kc, B, incRowB, incColB, buffer);
        buffer += kc*__DGEMM_NN_NR;
        B += __DGEMM_NN_NR*incColB;
    }
    if (_nr > 0) {
        for (i = 0; i < kc; ++i) {
            for (j = 0; j < _nr; ++j) {
                buffer[j] = B[j * incColB];
            }
            for (j = _nr; j < __DGEMM_NN_NR; ++j) {
                buffer[j] = 0.0;
            }
            buffer += __DGEMM_NN_NR;
            B += incRowB;
        }
    }
}

/*
 *  Micro kernel for multiplying panels from A and B.
 */
static void
_dgemm_nn_dgemm_micro_kernel(int kc,
        double alpha, const double *A, const double *B,
        double beta,
        double *C, int incRowC, int incColC) {
    double AB[__DGEMM_NN_MR * __DGEMM_NN_NR];

    int i, j, l;

    /*  Compute AB = A*B */
    for (l = 0; l < __DGEMM_NN_MR * __DGEMM_NN_NR; ++l) {
        AB[l] = 0;
    }
    for (l = 0; l < kc; ++l) {
        for (j = 0; j < __DGEMM_NN_NR; ++j) {
            for (i = 0; i < __DGEMM_NN_MR; ++i) {
                AB[i + j * __DGEMM_NN_MR] += A[i] * B[j];
            }
        }
        A += __DGEMM_NN_MR;
        B += __DGEMM_NN_NR;
    }

    /*
     *  Update C <- beta*C
     */
    if (beta == 0.0) {
        for (j = 0; j < __DGEMM_NN_NR; ++j) {
            for (i = 0; i < __DGEMM_NN_MR; ++i) {
                C[i * incRowC + j * incColC] = 0.0;
            }
        }
    } else if (beta != 1.0) {
        for (j = 0; j < __DGEMM_NN_NR; ++j) {
            for (i = 0; i < __DGEMM_NN_MR; ++i) {
                C[i * incRowC + j * incColC] *= beta;
            }
        }
    }

    /*
     *  Update C <- C + alpha*AB (note: the case alpha==0.0 was already treated in
     *                                  the above layer dgemm_nn)
     */
    if (alpha == 1.0) {
        for (j = 0; j < __DGEMM_NN_NR; ++j) {
            for (i = 0; i < __DGEMM_NN_MR; ++i) {
                C[i * incRowC + j * incColC] += AB[i + j * __DGEMM_NN_MR];
            }
        }
    } else {
        for (j = 0; j < __DGEMM_NN_NR; ++j) {
            for (i = 0; i < __DGEMM_NN_MR; ++i) {
                C[i * incRowC + j * incColC] += alpha * AB[i + j * __DGEMM_NN_MR];
            }
        }
    }
}

/*
 *  Compute Y += alpha*X
 */
static void
_dgemm_nn_dgeaxpy(int m,
        int n,
        double alpha,
        const double *X,
        int incRowX,
        int incColX,
        double *Y,
        int incRowY,
        int incColY) {
    int i, j;


    if (alpha != 1.0) {
        for (j = 0; j < n; ++j) {
            for (i = 0; i < m; ++i) {
                Y[i * incRowY + j * incColY] += alpha * X[i * incRowX + j * incColX];
            }
        }
    } else {
        for (j = 0; j < n; ++j) {
            for (i = 0; i < m; ++i) {
                Y[i * incRowY + j * incColY] += X[i * incRowX + j * incColX];
            }
        }
    }
}

/*
 *  Compute X *= alpha
 */
static void
_dgemm_nn_dgescal(int m,
        int n,
        double alpha,
        double *X,
        int incRowX,
        int incColX) {
    int i, j;

    if (alpha != 0.0) {
        for (j = 0; j < n; ++j) {
            for (i = 0; i < m; ++i) {
                X[i * incRowX + j * incColX] *= alpha;
            }
        }
    } else {
        for (j = 0; j < n; ++j) {
            for (i = 0; i < m; ++i) {
                X[i * incRowX + j * incColX] = 0.0;
            }
        }
    }
}

/*
 * Macro Kernel for the multiplication of blocks of A and B.  We assume that
 *  these blocks were previously packed to buffers _A and _B.
 */
static void
_dgemm_nn_dgemm_macro_kernel(int mc,
        int nc,
        int kc,
        double alpha,
        double beta,
        double *C,
        int incRowC,
        int incColC) {
    int mp = (mc + __DGEMM_NN_MR - 1) / __DGEMM_NN_MR;
    int np = (nc + __DGEMM_NN_NR - 1) / __DGEMM_NN_NR;

    int _mr = mc % __DGEMM_NN_MR;
    int _nr = nc % __DGEMM_NN_NR;

    int mr, nr;
    int i, j;

    for (j = 0; j < np; ++j) {
        nr = (j != np - 1 || _nr == 0) ? __DGEMM_NN_NR : _nr;

        for (i = 0; i < mp; ++i) {
            mr = (i != mp - 1 || _mr == 0) ? __DGEMM_NN_MR : _mr;

            if (mr == __DGEMM_NN_MR && nr == __DGEMM_NN_NR) {
                _dgemm_nn_dgemm_micro_kernel(kc, alpha, &__DGEMM_NN__A[i * kc * __DGEMM_NN_MR], &__DGEMM_NN__B[j * kc * __DGEMM_NN_NR],
                        beta,
                        &C[i * __DGEMM_NN_MR * incRowC + j * __DGEMM_NN_NR * incColC],
                        incRowC, incColC);
            } else {
                _dgemm_nn_dgemm_micro_kernel(kc, alpha, &__DGEMM_NN__A[i * kc * __DGEMM_NN_MR], &__DGEMM_NN__B[j * kc * __DGEMM_NN_NR],
                        0.0,
                        __DGEMM_NN__C, 1, __DGEMM_NN_MR);
                _dgemm_nn_dgescal(mr, nr, beta,
                        &C[i * __DGEMM_NN_MR * incRowC + j * __DGEMM_NN_NR * incColC], incRowC, incColC);
                _dgemm_nn_dgeaxpy(mr, nr, 1.0, __DGEMM_NN__C, 1, __DGEMM_NN_MR,
                        &C[i * __DGEMM_NN_MR * incRowC + j * __DGEMM_NN_NR * incColC], incRowC, incColC);
            }
        }
    }
}

/*  Compute C <- beta*C + alpha*A*B */

void
scs_dgemm_nn(int m,
        int n,
        int k,
        double alpha,
        const double *A,
        int incRowA,
        int incColA,
        const double *B,
        int incRowB,
        int incColB,
        double beta,
        double *C,
        int incRowC,
        int incColC) {
    int mb = (m + __DGEMM_NN_MC - 1) / __DGEMM_NN_MC;
    int nb = (n + __DGEMM_NN_NC - 1) / __DGEMM_NN_NC;
    int kb = (k + __DGEMM_NN_KC - 1) / __DGEMM_NN_KC;

    int _mc = m % __DGEMM_NN_MC;
    int _nc = n % __DGEMM_NN_NC;
    int _kc = k % __DGEMM_NN_KC;

    int mc, nc, kc;
    int i, j, l;

    double _beta;

    if (alpha == 0.0 || k == 0) {
        _dgemm_nn_dgescal(m, n, beta, C, incRowC, incColC);
        return;
    }

    for (j = 0; j < nb; ++j) {
        nc = (j != nb - 1 || _nc == 0) ? __DGEMM_NN_NC : _nc;

        for (l = 0; l < kb; ++l) {
            kc = (l != kb - 1 || _kc == 0) ? __DGEMM_NN_KC : _kc;
            _beta = (l == 0) ? beta : 1.0;

            _dgemm_nn_pack_B(kc, nc,
                    &B[l * __DGEMM_NN_KC * incRowB + j * __DGEMM_NN_NC * incColB], incRowB, incColB,
                    __DGEMM_NN__B);

            for (i = 0; i < mb; ++i) {
                mc = (i != mb - 1 || _mc == 0) ? __DGEMM_NN_MC : _mc;

                _dgemm_nn_pack_A(mc, kc,
                        &A[i * __DGEMM_NN_MC * incRowA + l * __DGEMM_NN_KC * incColA], incRowA, incColA,
                        __DGEMM_NN__A);

                _dgemm_nn_dgemm_macro_kernel(mc, nc, kc, alpha, _beta,
                        &C[i * __DGEMM_NN_MC * incRowC + j * __DGEMM_NN_NC * incColC],
                        incRowC, incColC);
            }
        }
    }
}

/* LCOV_EXCL_STOP */


void matrixMultiplicationColumnPacked(
        int m,
        int n,
        int k,
        scs_float alpha,
        const scs_float * RESTRICT A,
        scs_float beta,
        const scs_float * RESTRICT B,
        scs_float *C) {
#ifdef LAPACK_LIB_FOUND
    /* Use BLAS to multiply the two matrices */
    const char no_transpose = 'N';
    const blasint m_ = m;
    const blasint n_ = n;
    const blasint k_ = k;
    __scs_gemm(&no_transpose, &no_transpose,
            &m_, &n_, &k_, &alpha, A, &m_, B, &k_, &beta, C, &m_);
#else
    dgemm_nn(m, n, k, alpha, A, 1, m, B, 1, k, beta, C, 1, m);
#endif

}

void matrixMultiplicationTransColumnPacked(
        int m,
        int n,
        int k,
        scs_float alpha,
        const scs_float *A,
        scs_float beta,
        const scs_float *B,
        scs_float *C) {

#ifdef LAPACK_LIB_FOUND
    const char no_transpose = 'N';
    const char transpose = 'T';
    const blasint m_ = m;
    const blasint n_ = n;
    const blasint k_ = k;
    __scs_gemm(&transpose, &no_transpose,
            &m_, &n_, &k_, &alpha, A, &k_, B, &k_, &beta, C, &m_);
#else
    scs_dgemm_nn(m, n, k, alpha, A, k, 1, B, 1, k, beta, C, 1, m);
#endif


}

/* x = b*a */
void setAsScaledArray(
        scs_float * RESTRICT x,
        const scs_float * RESTRICT a,
        const scs_float b,
        scs_int len) {
#ifdef LAPACK_LIB_FOUND
    memcpy(x, a, len * sizeof (*x));
    scaleArray(x, b, len);
#else
    register scs_int j;
    const scs_int block_size = 4;
    const scs_int block_len = len >> 2;
    const scs_int remaining = len % block_size;
    j = 0;
    while (j < block_len * block_size) {
        x[j] = b * a[j];
        ++j;
        x[j] = b * a[j];
        ++j;
        x[j] = b * a[j];
        ++j;
        x[j] = b * a[j];
        ++j;
    }
    j = block_size * block_len;
    switch (remaining) {
        case 3: x[j + 2] = b * a[j + 2];
        case 2: x[j + 1] = b * a[j + 1];
        case 1: x[j] = b * a[j];
        case 0:;
    }
#endif
}

/* a *= b */
void scaleArray(scs_float * RESTRICT a, const scs_float b, scs_int len) {
#ifdef LAPACK_LIB_FOUND
    const blasint one = 1;
    __scs_scal(&len, &b, a, &one);
#else
    register scs_int j;
    const scs_int block_size = 4;
    const scs_int block_len = len >> 2;
    const scs_int remaining = len % block_size;
    j = 0;
    while (j < block_len * block_size) {
        a[j] *= b;
        ++j;
        a[j] *= b;
        ++j;
        a[j] *= b;
        ++j;
        a[j] *= b;
        ++j;
    }
    j = block_size * block_len;
    switch (remaining) {
        case 3: a[j + 2] *= b;
        case 2: a[j + 1] *= b;
        case 1: a[j] *= b;
        case 0:;
    }
#endif    
}

/* x'*y */
scs_float innerProd(
        const scs_float * RESTRICT x,
        const scs_float * RESTRICT y,
        scs_int len) {
#ifdef LAPACK_LIB_FOUND
    blasint one = 1;
    scs_float dot_product = __scs_dot(&len, x, &one, y, &one);
    return dot_product;
#else
    register scs_int j;
    register scs_float ip = 0.;
    register scs_float s0 = 0.;
    register scs_float s1 = 0.;
    register scs_float s2 = 0.;
    register scs_float s3 = 0.;
    static const scs_int block_size = 4;
    const scs_int block_len = len >> 2;
    const scs_int remaining = len % block_size;

    j = 0;
    while (j < block_len * block_size) {
        s0 += x[j] * y[j];
        ++j;
        s1 += x[j] * y[j];
        ++j;
        s2 += x[j] * y[j];
        ++j;
        s3 += x[j] * y[j];
        ++j;
    }
    ip = s0 + s1 + s2 + s3;
    j = block_size * block_len;
    switch (remaining) {
        case 3: ip += x[j + 2] * y[j + 2];
        case 2: ip += x[j + 1] * y[j + 1];
        case 1: ip += x[j] * y[j];
        case 0:;
    }
    return ip;
#endif
}

/* ||v||_2^2 */
scs_float calcNormSq(const scs_float * RESTRICT v, scs_int len) {
    return innerProd(v, v, len);
}

/* ||v||_2 */
scs_float calcNorm(const scs_float * RESTRICT v, scs_int len) {
#ifdef LAPACK_LIB_FOUND
    blasint one = 1;
    return __scs_nrm2(&len, v, &one);
#else
    return SQRTF(calcNormSq(v, len));
#endif
}

scs_float calcNormInf(
        const scs_float * RESTRICT a,
        scs_int l) {
#ifdef LAPACK_LIB_FOUND
    blasint one = 1;
    blasint idx_max = __scs_iamax(&l, a, &one);
    return a[idx_max];
#else
    scs_float tmp, max = 0.0;
    scs_int i;
    for (i = 0; i < l; ++i) {
        tmp = ABS(a[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
#endif
}

/* saxpy a += sc*b */
void addScaledArray(
        scs_float * RESTRICT a,
        const scs_float * RESTRICT b,
        scs_int len,
        const scs_float sc) {
#ifdef LAPACK_LIB_FOUND    
    blasint one = 1;
    __scs_axpy(&len, &sc, b, &one, a, &one);
#else
    register scs_int j;
    const scs_int block_size = 4;
    const scs_int block_len = len >> 2; /* divide by 4*/
    const scs_int remaining = len % block_size;
    j = 0;
    while (j < block_len * block_size) {
        a[j] += sc * b[j];
        ++j;
        a[j] += sc * b[j];
        ++j;
        a[j] += sc * b[j];
        ++j;
        a[j] += sc * b[j];
        ++j;
    }
    j = block_size * block_len;
    switch (remaining) {
        case 3: a[j + 2] += sc * b[j + 2];
        case 2: a[j + 1] += sc * b[j + 1];
        case 1: a[j] += sc * b[j];
        case 0:;
    }
#endif
}

void axpy2(
        scs_float * RESTRICT x,
        const scs_float * RESTRICT u,
        const scs_float * RESTRICT v,
        scs_float alpha,
        scs_float beta,
        scs_int n) {
#ifdef LAPACK_LIB_FOUND
    scs_float tol = 1e-16;
    if (x != u) {
        if (ABS(alpha - 1) > tol) {
            /* x = a * u */
            setAsScaledArray(x, u, alpha, n);
        } else {
            memcpy(x, u, n * sizeof (*x));
        }
    } else {
        scaleArray(x, alpha, n);
    }
    /* x += b * v */
    addScaledArray(x, v, n, beta);
#else
    register scs_int j;
    const scs_int block_size = 4;
    const scs_int block_len = n >> 2; /* divide by 4*/
    const scs_int remaining = n % block_size;
    j = 0;
    while (j < block_len * block_size) {
        x[j] = alpha * u[j] + beta * v[j];
        ++j;
        x[j] = alpha * u[j] + beta * v[j];
        ++j;
        x[j] = alpha * u[j] + beta * v[j];
        ++j;
        x[j] = alpha * u[j] + beta * v[j];
        ++j;
    }
    j = block_size * block_len;
    switch (remaining) {
        case 3: x[j + 2] = alpha * u[j + 2] + beta * v[j + 2];
        case 2: x[j + 1] = alpha * u[j + 1] + beta * v[j + 1];
        case 1: x[j] = alpha * u[j] + beta * v[j];
        case 0:;
    }
#endif
}

void addArray(
        scs_float * RESTRICT a,
        const scs_float * RESTRICT b,
        scs_int len) {
#ifdef LAPACK_LIB_FOUND
    addScaledArray(a, b, len, 1.0);
#else
    register scs_int j = 0;
    const scs_int block_size = 4;
    const scs_int block_len = len >> 2;
    const scs_int remaining = len % block_size;
    while (j < block_len * block_size) {
        a[j] += b[j];
        ++j;
        a[j] += b[j];
        ++j;
        a[j] += b[j];
        ++j;
        a[j] += b[j];
        ++j;
    }
    j = block_size * block_len;
    switch (remaining) {
        case 3: a[j + 2] += b[j + 2];
        case 2: a[j + 1] += b[j + 1];
        case 1: a[j] += b[j];
        case 0:;
    }
#endif
}

void subtractArray(
        scs_float * RESTRICT a,
        const scs_float * RESTRICT b,
        scs_int len) {
#ifdef LAPACK_LIB_FOUND
    addScaledArray(a, b, len, -1.0);
#else
    register scs_int j = 0;
    const scs_int block_size = 4;
    const scs_int block_len = len >> 2;
    const scs_int remaining = len % block_size;

    j = 0;
    while (j < block_len * block_size) {
        a[j] -= b[j];
        ++j;
        a[j] -= b[j];
        ++j;
        a[j] -= b[j];
        ++j;
        a[j] -= b[j];
        ++j;
    }
    j = block_size * block_len;
    switch (remaining) {
        case 3: a[j + 2] -= b[j + 2];
        case 2: a[j + 1] -= b[j + 1];
        case 1: a[j] -= b[j];
        case 0:;
    }
#endif
}

scs_float calcNormDiff(
        const scs_float * RESTRICT a,
        const scs_float * RESTRICT b,
        scs_int l) {
    scs_float nmDiff = 0.0, tmp;
    scs_int i;
    for (i = 0; i < l; ++i) {
        tmp = (a[i] - b[i]);
        nmDiff += tmp * tmp;
    }
    return SQRTF(nmDiff);
}

scs_float calcNormInfDiff(
        const scs_float * RESTRICT a,
        const scs_float * RESTRICT b,
        scs_int l) {
    scs_float tmp, max = 0.0;
    scs_int i;
    for (i = 0; i < l; ++i) {
        tmp = ABS(a[i] - b[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

scs_float * cgls_malloc_workspace(scs_int m, scs_int n) {
    const scs_int maxmn = m > n ? m : n;
    if (m <= 0 || n <= 0) {
        return SCS_NULL;
    }
    return malloc((maxmn + m + 2 * n) * sizeof (scs_float));
}

scs_int cgls(
        scs_int m,
        scs_int n,
        const scs_float * RESTRICT A,
        const scs_float * RESTRICT b,
        scs_float * RESTRICT x,
        scs_float tol,
        scs_int * RESTRICT maxiter,
        scs_float * RESTRICT workspace
        ) {
    const scs_int maxmn = m > n ? m : n;
    scs_float * r = workspace;
    scs_float * p = r + n;
    scs_float * t = p;
    scs_float * xi = p + maxmn;
    scs_float * phi = xi + n;
    scs_float r_norm_old;
    scs_float r_norm_new;
    scs_int k;


    /* t = b */
    memcpy(t, b, m * sizeof (*t));
    /* t = t - Ax */
    matrixMultiplicationColumnPacked(m, 1, n, -1.0, A, 1.0, x, t);
    /* r = A' * t */
    matrixMultiplicationTransColumnPacked(n, 1, m, 1.0, A, 0.0, t, r);
    /* p = r */
    memcpy(p, r, n * sizeof (*p));
    /* r_norm_old = norm(r)^2 */
    r_norm_old = calcNormSq(r, n);

    for (k = 0; k < *maxiter; ++k) {
        double alpha;
        /* phi = A * p */
        matrixMultiplicationColumnPacked(m, 1, n, 1.0, A, 0.0, p, phi);
        /* xi = A' * phi */
        matrixMultiplicationTransColumnPacked(n, 1, m, 1.0, A, 0.0, phi, xi);
        /* alpha = r_norm_old / (p'*xi) */
        alpha = r_norm_old / innerProd(p, xi, n);
        /*  x = x + alpha * p */
        axpy2(x, x, p, 1.0, alpha, n);
        /* r = r - alpha * xi */
        axpy2(r, r, xi, 1.0, -alpha, n);
        /* r_norm_new = norm(r)^2 */
        r_norm_new = calcNormSq(r, n);
        if (sqrt(r_norm_new) < tol) {
            break;
        }
        /* p = beta * p + r*/
        axpy2(p, p, r, r_norm_new / r_norm_old, 1.0, n);
        r_norm_old = r_norm_new;
    }

    if (k == *maxiter) {
        return 1;
    }

    *maxiter = k + 1;

    return 0;
}

#ifdef LAPACK_LIB_FOUND

scs_int qr_workspace_size(
        scs_int m,
        scs_int n
        ) {
    scs_int lwork = -1;
    scs_int status;
    scs_int nrhs = 1;
    scs_int lda = m;
    scs_int ldb = m;
    scs_float wkopt;
    if (m <= 0 || n <= 0) {
        return 0;
    }
    __scs_gels((char *) "No transpose", &m, &n, &nrhs, 0, &lda, 0, &ldb, &wkopt, &lwork,
            &status);
    return (scs_int) wkopt;
}

scs_int qrls(
        scs_int m,
        scs_int n,
        scs_float * RESTRICT A,
        scs_float * RESTRICT b,
        scs_float * RESTRICT wspace,
        scs_int wsize
        ) {
    scs_int status;
    scs_int nrhs = 1;
    scs_int lda = m;
    scs_int ldb = m;
    __scs_gels("No transpose", &m, &n, &nrhs, A, &lda, b, &ldb, wspace, &wsize, &status);
    return status;
}

scs_int svd_workspace_size(
        scs_int m,
        scs_int n
        ) {
    blasint status;
    blasint nrhs = 1;
    scs_float rcond = 1.;
    scs_float wkopt;
    scs_float singular_values;
    blasint rank;
    blasint lwork = -1;

    if (m <= 0 || n <= 0) {
        return 0;
    }

    __scs_dgelss(&m, &n, &nrhs, 0, &m, 0, &m,
            &singular_values, &rcond, &rank,
            &wkopt, &lwork, &status);

    return (scs_int) wkopt;
}

__attribute__ ((noinline)) scs_int svdls(
        scs_int m,
        scs_int n,
        scs_float * RESTRICT A,
        scs_float * RESTRICT b,
        scs_float * RESTRICT wspace,
        scs_int wsize,
        scs_float rcond,
        scs_float * RESTRICT singular_values,
        scs_int * RESTRICT rank
        ) {

    blasint status;
    blasint nrhs = 1;
    __scs_dgelss(&m, &n, &nrhs, A, &m, b, &m,
            singular_values, &rcond, rank,
            wspace, &wsize, &status);
    return (scs_int) status;
}
#endif /* #ifdef LAPACK_LIB_FOUND */