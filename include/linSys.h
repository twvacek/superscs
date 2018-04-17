/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Pantelis Sopasakis (https://alphaville.github.io),
 *                    Krina Menounou (https://www.linkedin.com/in/krinamenounou), 
 *                    Panagiotis Patrinos (http://homes.esat.kuleuven.be/~ppatrino)
 * Copyright (c) 2012 Brendan O'Donoghue (bodonoghue85@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */
#ifndef LINSYS_H_GUARD
#define LINSYS_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

/* YOUR LINEAR SYSTEM SOLVER MUST IMPLEMENT THESE METHODS AND PRIVATE_DATA
 * STRUCT */

/* private data structs (that you define) containing any necessary data to solve
 * linear system, etc. */
/* this defines the matrix A, only the linear system solver interacts with this
 * struct */
    /**
     * Structure supporting sparse matrices in CSC format.
     * 
     * \sa \ref page_sparse_matrices "Sparse matrices documentation"
     */
typedef struct A_DATA_MATRIX AMatrix;
/* stores the necessary private workspace, only the linear system solver
 * interacts with this struct */
typedef struct PRIVATE_DATA Priv;

/** 
 * initialize Priv structure and perform any necessary preprocessing 
 */
Priv *initPriv(const AMatrix *A, const ScsSettings *stgs);

/** 
 * solves [d->RHO_X * I  A' ; A  -I] x = b for x, stores result in b, s contains
 * warm-start, iter is current scs iteration count 
 */
scs_int scs_solve_lin_sys(const AMatrix *A, const ScsSettings *stgs, Priv *p,
                    scs_float *b, const scs_float *s, scs_int iter);
/** 
 * frees \c Priv structure and allocated memory in \c Priv 
 */
void freePriv(Priv *p);

/** 
 * forms y += A'*x 
 */
void accumByAtrans(const AMatrix *A, Priv *p, const scs_float *x, scs_float *y);

/** 
 * forms y += A*x 
 */
void accumByA(const AMatrix *A, Priv *p, const scs_float *x, scs_float *y);

/** 
 * returns negative num if input data is invalid 
 */
scs_int validateLinSys(const AMatrix *A);

/** returns string describing method, can return null, if not null free will be
 * called on output 
 */
char *getLinSysMethod(const AMatrix *A, const ScsSettings *stgs);

/** returns string containing summary information about linear system solves, can
 * return null, if not null free will be called on output 
 */
char *getLinSysSummary(Priv *p, const ScsInfo *info);

/* Normalization routines, used if d->NORMALIZE is true */
/** normalizes A matrix, sets <code>w->E</code> and <code>w->D</code> diagonal scaling matrices, 
 * <code>Anew = d->SCALE * (D^-1)*A*(E^-1)</code> (different to paper which is <code>D*A*E</code>)
 * D and E must be all positive entries, D must satisfy cone boundaries
 * must set (<code>w->meanNormRowA</code> = mean of norms of rows of normalized A) THEN scale
 * resulting \c A by <code>d->SCALE</code>.
 */
void normalizeA(AMatrix *A, const ScsSettings *stgs, const ScsCone *k, ScsScaling *scal);

/** 
 * unnormalizes \c A matrix, unnormalizes by <code>w->D</code> and <code>w->E</code> 
 * and <code>d->SCALE</code>.
 */
void unNormalizeA(AMatrix *A, const ScsSettings *stgs, const ScsScaling *scal);

/** 
 * to free the memory allocated in \c AMatrix 
 */
void freeAMatrix(AMatrix *A);

#ifdef COPYAMATRIX

/** 
 * copies \c A (instead of in-place normalization), returns 0 for failure,
 * allocates memory for dstp	
 */
scs_int copyAMatrix(AMatrix **dstp, const AMatrix *src);
#endif

#ifdef __cplusplus
}
#endif

#endif
