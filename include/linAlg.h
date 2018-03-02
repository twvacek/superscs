#ifndef LINALG_H_GUARD
#define LINALG_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include "scs.h"
#include <math.h>

    /**
     * Performs the operation
     * \f[
     *  x \leftarrow b\cdot a,
     * \f]
     * where \c a is a vector and \c b is a scalar.
     * 
     * @param x
     * @param a
     * @param b
     * @param len
     * 
     * \note with loop unrolling for speed
     */
    void setAsScaledArray(
            scs_float *x,
            const scs_float *a,
            const scs_float b,
            scs_int len);

    /**
     * Performs the operation
     * \f[
     *   a \leftarrow b\cdot a
     * \f]
     * @param a
     * @param b
     * @param len
     * 
     * \note with loop unrolling for speed
     */
    void scaleArray(scs_float *a, const scs_float b, scs_int len);

    /**
     * Computes the inner product of two vectors, that is
     * \f[
     *  \langle x, y \rangle = x'y = \sum_{i=1}^{\mathrm{len}}x_i y_i.
     * \f]
     * @param x
     * @param y
     * @param len
     * @return 
     * 
     * \note with loop unrolling for speed
     */
    scs_float innerProd(const scs_float *x, const scs_float *y, scs_int len);

    /**
     * Returns the square Euclidean norm of a vector.
     * @param v
     * @param len
     * @return 
     * 
     * \note uses ::innerProd
     */
    scs_float calcNormSq(const scs_float *v, scs_int len);

    /**
     * Returns the Euclidean norm of a vector.
     * @param v
     * @param len
     * @return 
     */
    scs_float calcNorm(const scs_float *v, scs_int len);

    /**
     * Returns the infinity norm of a vector.
     * @param a
     * @param l
     * @return 
     */
    scs_float calcNormInf(const scs_float *a, scs_int l);


    /**
     * Performs the operation
     * \f[
     *  a \leftarrow a + \gamma b
     * \f]
     * @param a vector \c a
     * @param b vector \c b
     * @param n length of \c a
     * @param sc the scalar \f$\gamma\f$
     * 
     * \note with loop unrolling for speed
     */
    void addScaledArray(
            scs_float *a,
            const scs_float *b,
            scs_int n,
            const scs_float sc);

    /**
     * Performs the operation
     * \f[
     *  a \leftarrow a + b
     * \f]
     * @param a vector \c a
     * @param b vector \c b
     * @param n length of \c a
     * 
     * \note with loop unrolling for speed
     */
    void addArray(scs_float *a, const scs_float *b, scs_int n);

    /**
     * Computes \f$x \leftarrow \alpha u + \beta v\f$
     * 
     * \note The pointer \c x can have the same value as \c u so as to perform
     * operations like \f$x\leftarrow \alpha x + \beta v\f$.     
     */
    void axpy2(
            scs_float *x,
            scs_float * u,
            const scs_float * v,
            scs_float a,
            scs_float b,
            scs_int n);

    /**
     * Performs the operation
     * \f[
     *  a \leftarrow a - b
     * \f]
     * @param a vector \c a
     * @param b vector \c b
     * @param n length of \c a
     * 
     * \note with loop unrolling for speed
     */
    void subtractArray(scs_float *a, const scs_float *b, scs_int n);

    /**
     * Returns the Euclidean norm of the difference of two vectors
     * @param a
     * @param b
     * @param l
     * @return 
     */
    scs_float calcNormDiff(const scs_float *a, const scs_float *b, scs_int l);

    /**
     * Returns the infinity norm of the difference of two vectors
     * @param a
     * @param b
     * @param l
     * @return 
     */
    scs_float calcNormInfDiff(const scs_float *a, const scs_float *b, scs_int l);


    /**
     * Perofrms the operation
     * \f[
     *    C \leftarrow \beta C + \alpha A B
     * \f]
     * 
     * @param m number of rows of matrix \f$A\f$
     * @param n number of columns of matrix \f$B\f$
     * @param k number of rows of matrix \f$B\f$ (columns of \f$A\f$)
     * @param alpha coefficient \f$\alpha\f$
     * @param A pointer to matrix \f$A\f$
     * @param incRowA increment in traversing the rows of \f$A\f$
     * @param incColA increment in traversing the columns of \f$A\f$
     * @param B pointer to matrix \f$B\f$
     * @param incRowB increment in traversing the rows of \f$B\f$
     * @param incColB increment in traversing the columns of \f$B\f$
     * @param beta coefficient \f$\beta\f$
     * @param C pointer to matrix \f$C\f$
     * @param incRowC increment in traversing the rows of \f$C\f$
     * @param incColC increment in traversing the columns of \f$C\f$
     * 
     * @see ::matrixMultiplicationColumnPacked
     * 
     * \note The implementation of this method is that of 
     * [ULMBLAS](http://apfel.mathematik.uni-ulm.de/~lehn/sghpc/gemm/page13/index.html).
     * 
     * \note The original source code is available at 
     * [this link](http://apfel.mathematik.uni-ulm.de/~lehn/sghpc/gemm/page13/index.html).
     * 
     * \note The [ULMBLAS project](https://github.com/michael-lehn/ulmBLAS) is available
     * on github and is licensed with the 
     * [new BSD licence](https://github.com/michael-lehn/ulmBLAS/blob/master/LICENSE).
     * 
     * \warning This function works only with \c double precision data.
     * 
     */
    void dgemm_nn(
            int m,
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
            int incColC);

    /**
     * Perofrms the operation \f$C \leftarrow \beta C + \alpha A B,\f$
     * where \f$A\f$, \f$B\f$ and \f$C\f$ are column-packed matrices.
     * 
     * This method is a proxy to ::dgemm_nn.
     * 
     * @param m number of rows of matrix \f$A\f$
     * @param n number of columns of matrix \f$B\f$
     * @param k number of rows of matrix \f$B\f$ (columns of \f$A\f$)
     * @param alpha coefficient \f$\alpha\f$
     * @param A pointer to matrix \f$A\f$ in column-packed form
     * @param beta coefficient \f$\beta\f$
     * @param B pointer to matrix \f$B\f$ in column-packed form
     * @param C pointer to matrix \f$C\f$ in column-packed form
     * 
     * @see ::dgemm_nn
     */
    void matrixMultiplicationColumnPacked(
            int m,
            int n,
            int k,
            double alpha,
            const double *A,
            double beta,
            const double *B,
            double *C);

    /**
     * Perofrms the operation \f$C \leftarrow \beta C + \alpha A^{\top} B,\f$
     * where \f$A\f$, \f$B\f$ and \f$C\f$ are column-packed matrices.
     * 
     * This method is a proxy to ::dgemm_nn.
     * 
     * @param m number of rows of matrix \f$A\f$
     * @param n number of columns of matrix \f$B\f$
     * @param k number of rows of matrix \f$B\f$ (columns of \f$A\f$)
     * @param alpha coefficient \f$\alpha\f$
     * @param A pointer to matrix \f$A\f$ in column-packed form
     * @param beta coefficient \f$\beta\f$
     * @param B pointer to matrix \f$B\f$ in column-packed form
     * @param C pointer to matrix \f$C\f$ in column-packed form
     * 
     * @see ::dgemm_nn
     */
    void matrixMultiplicationTransColumnPacked(
            int m,
            int n,
            int k,
            double alpha,
            const double *A,
            double beta,
            const double *B,
            double *C);

    /**
     * Computes the sum \f$\S = \sum_i x_i\f$ of a given array \f$x\f$
     * 
     * @param x given array
     * @param len length of array
     * @return sum
     */
    scs_float sumArray(
            const scs_float *x,
            scs_int len);


    /**
     * Solves a least squares problem using the conjugate gradient method.
     * 
     * Solves the problem: Minimize \f$\|Ax-b\|^2\f$, or, what is the same, the 
     * linear system \f$ A'Ax = A'b\f$.
     *   
     * @param m         Number of rows of matrix A
     * @param n         Number of columns of A
     * @param A         Matrix A (column-packed)
     * @param b         Right-hand side vector b
     * @param x         Solution (on entry: initial guess)
     * @param tol       Tolerance
     * @param maxiter   Maximum number of CG iterations (on exit: number of iterations)
     * @param wspace    Externally allocated memory space serving as workspace. 
     *                  This must be of size (max(m,n) + m + 2 * n) * sizeof(scs_float).
     *                  On exit, the first n memory positions store the residual.
     * 
     * @return status code (0: success, 1: maximum number of iterations reached).
     */
    scs_int cgls(
            scs_int m,
            scs_int n,
            const scs_float* A,
            const scs_float* b,
            scs_float* x,
            scs_float tol,
            scs_int* maxiter,
            scs_float * wspace
            );


#ifdef __cplusplus
}
#endif
#endif
