#ifndef CONES_H_GUARD
#define CONES_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include "glbopts.h"
#include "scs_blas.h"

    /* NB: rows of data matrix A must be specified in this exact order */

    /** 
     * \brief Cone structure 
     *
     * This structure represents a Cartesian product of cones as follows
     * 
     * \f{eqnarray*}{
     * \mathcal{K} = \mathcal{K}^{f}_{n_f} 
     *                  \times 
     *               \mathcal{K}^{l}_{n_l}
     *                  \times
     *               \mathcal{K}^{so}_{n_{so_1},\ldots, n_{so,N_{so}}}
     * \f}
     * 
     */
    struct SCS_CONE {
        /**
         * \brief Number of linear equality constraints (\f$n_f\f$)
         * 
         * The corresponding cone is the zero-cone 
         * \f$\mathcal{K}^{f}_{n_f} = \{0_{n_f}\}\f$
         */
        scs_int f;
        /** 
         * \brief Dimension of LP cone (\f$n_l\f$)
         * 
         * This is used to specify element-wise inequalities.
         *
         * The corresponding cone is the positive orthant
         * \f$\mathcal{K}^{l}_{n_l} = \{x\in\mathbb{R}^{n_l}: x_i \geq 0, \forall i\}\f$
         */
        scs_int l;
        /** 
         * \brief Array of SOC constraints (\f$n_{so_1},\ldots, n_{so,N_{so}}\f$).
         * 
         * This is the Cartesian product of \f$N_{so}\f$ cones with 
         * dimensions \f$n_{so_1},\ldots, n_{so,N_{so}}\f$
         * 
         * The cone is
         * 
         * \f{eqnarray*}{
         * \mathcal{K}^{so}_{n_{so_1},\ldots, n_{so,N_{so}}} = 
         *      \mathcal{K}^{so}_{n_{so_1}} 
         *      \times 
         *      \cdots
         *      \times
         *      \mathcal{K}^{so}_{n_{so, N_{so}}},
         * \f}
         * 
         * where \f$\mathcal{K}^{so}_{n}\f$ is the second-order cone of 
         * dimension \f$n\f$, that is
         * 
         * \f{eqnarray*}{
         * \mathcal{K}^{so}_{n} = \{x = (y,t): y\in\mathbb{R}^{n-1}, t\in\mathbb{R}:
         * \|y\| \leq t\}
         * \f}
         * 
         * This array contains the dimensions \f$(n_{so_1},\ldots, n_{so,N_{so}})\f$.
         * 
         * The length of this array is specified in #qsize.
         * 
         * \sa \ref #qsize "number of second-order cones"
         * 
         */
        scs_int *RESTRICT q;
        /** 
         * \brief Length of SOC array, i.e., number of second-order cones (\f$N_{so}\f$)
         * 
         * \sa \ref #q "array of second-order cones"
         */
        scs_int qsize; 
        /** 
         * \brief array of PSD constraints 
         * 
         * Array of dimensions of PSD constraints.
         * 
         * \sa \ref #ssize "number of PSD cones"
         */
        scs_int *RESTRICT s; 
        /**
         * \brief length of SD array 
         * 
         * \sa \ref #s "array of positive semidefinite cones"
         */
        scs_int ssize; 
        /**
         * \brief Number of primal exponential cone triples (\f$n_{\mathrm{exp}}\f$)
         * 
         * Consider the following set in \f$\mathbb{R}^3\f$
         * \f{eqnarray*}{
         * \mathcal{K}^{\mathrm{e}} = \{(x,y,z)\in\mathbb{R}^3: y e^{x/y} \leq z, y>0\}.
         * \f}
         * 
         * The exponential cone is the closure of \f$\mathcal{K}^{\mathrm{e}}\f$
         * 
         * Consider the following set in \f$\mathbb{R}^3\f$
         * \f{eqnarray*}{
         * \mathcal{K}^{\mathrm{exp}} = \mathrm{cl}\mathcal{K}^{\mathrm{e}}.
         * \f}
         * 
         * Define the Cartesian product of \f$n_{exp}\f$ such cones
         * 
         * \f{eqnarray*}{
         * \mathcal{K}^{\mathrm{exp}}_{n_{\mathrm{exp}}} = 
         * \prod_{i=1}^{n_{\mathrm{exp}}}\mathcal{K}^{\mathrm{exp}}.
         * \f}
         * 
         * \sa \ref #ed "dual exponential cone"
         */
        scs_int ep; 
        /**
         * \brief number of dual exponential cone triples (\f$n_{\mathrm{dexp}}\f$)
         * 
         * The dual exponential cone is the set
         * 
         * \f{eqnarray*}{
         * \mathcal{K}^{\mathrm{dexp}} = 
         * \left\{
         * (u,v,w)\in\mathbb{R}^3: u\leq 0, w \geq 0, -u 
         *   \log(-\textstyle\frac{u}{w})+u-v\leq 0
         * \right\},
         * \f}
         * 
         * with \f$0 \log(0/w)=0\f$ for all \f$w\geq 0\f$.
         * 
         * We define
         * 
         * \f{eqnarray*}{
         * \mathcal{K}^{\mathrm{dexp}}_{n_{\mathrm{dexp}}} = 
         * \prod_{i=1}^{n_{\mathrm{dexp}}}\mathcal{K}^{\mathrm{dexp}}.
         * \f}
         * 
         * \sa \ref #ep "primal exponential cone"
         */
        scs_int ed; 
        /** 
         * \brief Array of power cone params.
         * 
         * \note Cone parameters must be in \f$[-1, 1]\f$. 
         * \note Negative values are interpreted as specifying the dual cone 
         */
        scs_float * p; 
        /** 
         * \brief Number of (primal and dual) power cone tuples.
         *  
         */
        scs_int psize; 
    };

    /** private data to help cone projection step */

    /** \brief Workspace for cones */
    typedef struct {
#ifdef LAPACK_LIB_FOUND
        /* workspace for eigenvector decompositions: */
        scs_float * RESTRICT Xs;
        scs_float * RESTRICT Z;
        scs_float * RESTRICT e;
        scs_float * RESTRICT work;
        blasint * RESTRICT iwork, lwork, liwork;
#endif
        scs_float totalConeTime;
    } ConeWork;

    /**
     * boundaries will contain array of indices of rows of A corresponding to
     * cone boundaries, boundaries[0] is starting index for cones of size larger
     * than 1
     * returns length of boundaries array, boundaries malloc-ed here so should be
     * freed
     */
    scs_int getConeBoundaries(
            const Cone * RESTRICT k,
            scs_int ** RESTRICT boundaries);

    ConeWork *initCone(const Cone * RESTRICT k);

    char *getConeHeader(const Cone *k);

    scs_int validateCones(
            const Data * RESTRICT d,
            const Cone * RESTRICT k);

    /** 
     * pass in iter to control how accurate the cone projection
     * with iteration, set iter < 0 for exact projection, warm_start contains guess
     * of solution, can be SCS_NULL
     */
    scs_int projDualCone(
            scs_float * RESTRICT x,
            const Cone * RESTRICT k,
            ConeWork * RESTRICT c,
            const scs_float * RESTRICT warm_start,
            scs_int iter);

    void finishCone(
            ConeWork * RESTRICT coneWork);

    char *getConeSummary(
            const Info * RESTRICT info,
            ConeWork * RESTRICT c);

#ifdef __cplusplus
}
#endif
#endif
