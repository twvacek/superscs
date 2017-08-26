#include "linAlg.h"
#include <math.h>
#include <stdio.h>


#define MC  384
#define KC  384
#define NC  4096

#define MR  4
#define NR  4

/* 
 *   Local buffers for storing panels from A, B and C
 */
static double _A[MC*KC];
static double _B[KC*NC];
static double _C[MR*NR];

/*
 *  Packing complete panels from A (i.e. without padding)
 */
static void
pack_MRxk(int k, const double *A, int incRowA, int incColA,
        double *buffer) {
    int i, j;

    for (j = 0; j < k; ++j) {
        for (i = 0; i < MR; ++i) {
            buffer[i] = A[i * incRowA];
        }
        buffer += MR;
        A += incColA;
    }
}

/*
 *  Packing panels from A with padding if required
 */
static void
pack_A(int mc, int kc, const double *A, int incRowA, int incColA,
        double *buffer) {
    int mp = mc / MR;
    int _mr = mc % MR;

    int i, j;

    for (i = 0; i < mp; ++i) {
        pack_MRxk(kc, A, incRowA, incColA, buffer);
        buffer += kc*MR;
        A += MR*incRowA;
    }
    if (_mr > 0) {
        for (j = 0; j < kc; ++j) {
            for (i = 0; i < _mr; ++i) {
                buffer[i] = A[i * incRowA];
            }
            for (i = _mr; i < MR; ++i) {
                buffer[i] = 0.0;
            }
            buffer += MR;
            A += incColA;
        }
    }
}

/*
 *  Packing complete panels from B (i.e. without padding)
 */
static void
pack_kxNR(int k, const double *B, int incRowB, int incColB,
        double *buffer) {
    int i, j;

    for (i = 0; i < k; ++i) {
        for (j = 0; j < NR; ++j) {
            buffer[j] = B[j * incColB];
        }
        buffer += NR;
        B += incRowB;
    }
}

/*
 *  Packing panels from B with padding if required
 */
static void
pack_B(int kc, int nc, const double *B, int incRowB, int incColB,
        double *buffer) {
    int np = nc / NR;
    int _nr = nc % NR;

    int i, j;

    for (j = 0; j < np; ++j) {
        pack_kxNR(kc, B, incRowB, incColB, buffer);
        buffer += kc*NR;
        B += NR*incColB;
    }
    if (_nr > 0) {
        for (i = 0; i < kc; ++i) {
            for (j = 0; j < _nr; ++j) {
                buffer[j] = B[j * incColB];
            }
            for (j = _nr; j < NR; ++j) {
                buffer[j] = 0.0;
            }
            buffer += NR;
            B += incRowB;
        }
    }
}

/*
 *  Micro kernel for multiplying panels from A and B.
 */
static void
dgemm_micro_kernel(int kc,
        double alpha, const double *A, const double *B,
        double beta,
        double *C, int incRowC, int incColC) {
    double AB[MR * NR];

    int i, j, l;

    /*  Compute AB = A*B */
    for (l = 0; l < MR * NR; ++l) {
        AB[l] = 0;
    }
    for (l = 0; l < kc; ++l) {
        for (j = 0; j < NR; ++j) {
            for (i = 0; i < MR; ++i) {
                AB[i + j * MR] += A[i] * B[j];
            }
        }
        A += MR;
        B += NR;
    }

    /*
     *  Update C <- beta*C
     */
    if (beta == 0.0) {
        for (j = 0; j < NR; ++j) {
            for (i = 0; i < MR; ++i) {
                C[i * incRowC + j * incColC] = 0.0;
            }
        }
    } else if (beta != 1.0) {
        for (j = 0; j < NR; ++j) {
            for (i = 0; i < MR; ++i) {
                C[i * incRowC + j * incColC] *= beta;
            }
        }
    }

    /*
     *  Update C <- C + alpha*AB (note: the case alpha==0.0 was already treated in
     *                                  the above layer dgemm_nn)
     */
    if (alpha == 1.0) {
        for (j = 0; j < NR; ++j) {
            for (i = 0; i < MR; ++i) {
                C[i * incRowC + j * incColC] += AB[i + j * MR];
            }
        }
    } else {
        for (j = 0; j < NR; ++j) {
            for (i = 0; i < MR; ++i) {
                C[i * incRowC + j * incColC] += alpha * AB[i + j * MR];
            }
        }
    }
}

/*
 *  Compute Y += alpha*X
 */
static void
dgeaxpy(int m,
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
dgescal(int m,
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
dgemm_macro_kernel(int mc,
        int nc,
        int kc,
        double alpha,
        double beta,
        double *C,
        int incRowC,
        int incColC) {
    int mp = (mc + MR - 1) / MR;
    int np = (nc + NR - 1) / NR;

    int _mr = mc % MR;
    int _nr = nc % NR;

    int mr, nr;
    int i, j;

    for (j = 0; j < np; ++j) {
        nr = (j != np - 1 || _nr == 0) ? NR : _nr;

        for (i = 0; i < mp; ++i) {
            mr = (i != mp - 1 || _mr == 0) ? MR : _mr;

            if (mr == MR && nr == NR) {
                dgemm_micro_kernel(kc, alpha, &_A[i * kc * MR], &_B[j * kc * NR],
                        beta,
                        &C[i * MR * incRowC + j * NR * incColC],
                        incRowC, incColC);
            } else {
                dgemm_micro_kernel(kc, alpha, &_A[i * kc * MR], &_B[j * kc * NR],
                        0.0,
                        _C, 1, MR);
                dgescal(mr, nr, beta,
                        &C[i * MR * incRowC + j * NR * incColC], incRowC, incColC);
                dgeaxpy(mr, nr, 1.0, _C, 1, MR,
                        &C[i * MR * incRowC + j * NR * incColC], incRowC, incColC);
            }
        }
    }
}

/*  Compute C <- beta*C + alpha*A*B */

void
dgemm_nn(int m,
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
    int mb = (m + MC - 1) / MC;
    int nb = (n + NC - 1) / NC;
    int kb = (k + KC - 1) / KC;

    int _mc = m % MC;
    int _nc = n % NC;
    int _kc = k % KC;

    int mc, nc, kc;
    int i, j, l;

    double _beta;

    if (alpha == 0.0 || k == 0) {
        dgescal(m, n, beta, C, incRowC, incColC);
        return;
    }

    for (j = 0; j < nb; ++j) {
        nc = (j != nb - 1 || _nc == 0) ? NC : _nc;

        for (l = 0; l < kb; ++l) {
            kc = (l != kb - 1 || _kc == 0) ? KC : _kc;
            _beta = (l == 0) ? beta : 1.0;

            pack_B(kc, nc,
                    &B[l * KC * incRowB + j * NC * incColB], incRowB, incColB,
                    _B);

            for (i = 0; i < mb; ++i) {
                mc = (i != mb - 1 || _mc == 0) ? MC : _mc;

                pack_A(mc, kc,
                        &A[i * MC * incRowA + l * KC * incColA], incRowA, incColA,
                        _A);

                dgemm_macro_kernel(mc, nc, kc, alpha, _beta,
                        &C[i * MC * incRowC + j * NC * incColC],
                        incRowC, incColC);
            }
        }
    }
}

void matrixMultiplicationColumnPacked(
        int m,
        int n,
        int k,
        double alpha,
        const double *A,
        double beta,
        const double *B,
        double *C) {
    dgemm_nn(m, n, k, alpha, A, 1, m, B, 1, k, beta, C, 1, m);
}

void matrixMultiplicationTransColumnPacked(
        int m,
        int n,
        int k,
        double alpha,
        const double *A,
        double beta,
        const double *B,
        double *C) {
    dgemm_nn(m, n, k, alpha, A, k, 1, B, 1, k, beta, C, 1, m);
}

/* x = b*a */
void setAsScaledArray(scs_float *x, const scs_float *a, const scs_float b,
        scs_int len) {
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
}

/* a *= b */
void scaleArray(scs_float *a, const scs_float b, scs_int len) {
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
}

/* x'*y */
scs_float innerProd(const scs_float *x, const scs_float *y, scs_int len) {
    register scs_int j;
    register scs_float ip = 0.;
    register scs_float s0 = 0.;
    register scs_float s1 = 0.;
    register scs_float s2 = 0.;
    register scs_float s3 = 0.;
    const scs_int block_size = 4;
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
}

/* ||v||_2^2 */
scs_float calcNormSq(const scs_float *v, scs_int len) {
    return innerProd(v, v, len);
}

/* ||v||_2 */
scs_float calcNorm(const scs_float *v, scs_int len) {
    return SQRTF(calcNormSq(v, len));
}

scs_float calcNormInf(const scs_float *a, scs_int l) {
    scs_float tmp, max = 0.0;
    scs_int i;
    for (i = 0; i < l; ++i) {
        tmp = ABS(a[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

/* saxpy a += sc*b */
void addScaledArray(
        scs_float *a,
        const scs_float *b,
        scs_int len,
        const scs_float sc) {
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
}

void axpy2(scs_float *x, scs_float * u, const scs_float * v, scs_float a, scs_float b, scs_int n) {
    register scs_int j;
    const scs_int block_size = 4;
    const scs_int block_len = n >> 2; /* divide by 4*/
    const scs_int remaining = n % block_size;
    j = 0;
    while (j < block_len * block_size) {
        x[j] = a * u[j] + b * v[j];
        ++j;
        x[j] = a * u[j] + b * v[j];
        ++j;
        x[j] = a * u[j] + b * v[j];
        ++j;
        x[j] = a * u[j] + b * v[j];
        ++j;
    }
    j = block_size * block_len;
    switch (remaining) {
        case 3: x[j + 2] = a * u[j + 2] + b * v[j + 2];
        case 2: x[j + 1] = a * u[j + 1] + b * v[j + 1];
        case 1: x[j] = a * u[j] + b * v[j];
        case 0:;
    }
}

void addArray(
        scs_float *a,
        const scs_float *b,
        scs_int len) {

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
}

void subtractArray(
        scs_float *a,
        const scs_float *b,
        scs_int len) {

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
}

scs_float calcNormDiff(const scs_float *a, const scs_float *b, scs_int l) {
    scs_float nmDiff = 0.0, tmp;
    scs_int i;
    for (i = 0; i < l; ++i) {
        tmp = (a[i] - b[i]);
        nmDiff += tmp * tmp;
    }
    return SQRTF(nmDiff);
}

scs_float calcNormInfDiff(const scs_float *a, const scs_float *b, scs_int l) {
    scs_float tmp, max = 0.0;
    scs_int i;
    for (i = 0; i < l; ++i) {
        tmp = ABS(a[i] - b[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

/* sum(x) */
scs_float sumArray(const scs_float *x, scs_int len) {
    register scs_int j;
    register scs_float sum = 0.;
    register scs_float s0 = 0.;
    register scs_float s1 = 0.;
    register scs_float s2 = 0.;
    register scs_float s3 = 0.;
    const scs_int block_size = 4;
    const scs_int block_len = len >> 2;
    const scs_int remaining = len % block_size;

    j = 0;
    while (j < block_len * block_size) {
        s0 += x[j];
        ++j;
        s1 += x[j];
        ++j;
        s2 += x[j];
        ++j;
        s3 += x[j];
        ++j;
    }
    sum = s0 + s1 + s2 + s3;
    j = block_size * block_len;
    switch (remaining) {
        case 3: sum += x[j + 2];
        case 2: sum += x[j + 1];
        case 1: sum += x[j];
        case 0:;
    }
    return sum;
}