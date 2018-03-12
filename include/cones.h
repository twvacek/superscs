#ifndef CONES_H_GUARD
#define CONES_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include "glbopts.h"
#include "scs_blas.h"

    /* NB: rows of data matrix A must be specified in this exact order */

    /** \brief Cone structure */
    struct SCS_CONE {
        scs_int f; /**< \brief number of linear equality constraints */
        scs_int l; /**<  \brief length of LP cone */
        scs_int *__restrict q; /**<  \brief array of second-order cone constraints */
        scs_int qsize; /**<  \brief length of SOC array */
        scs_int *__restrict s; /**<  \brief array of SD constraints */
        scs_int ssize; /**<  \brief length of SD array */
        scs_int ep; /**<  \brief number of primal exponential cone triples */
        scs_int ed; /**<  \brief number of dual exponential cone triples */
        scs_float * p; /**<  \brief array of power cone params, must be in [-1, 1],
                     negative values are interpreted as specifying the dual cone */
        scs_int psize; /**<  \brief number of (primal and dual) power cone triples */
    };

    /** private data to help cone projection step */

    /** \brief Workspace for cones */
    typedef struct {
#ifdef LAPACK_LIB_FOUND
        /* workspace for eigenvector decompositions: */
        scs_float * __restrict Xs;
        scs_float * __restrict Z;
        scs_float * __restrict e;
        scs_float * __restrict work;
        blasint * __restrict iwork, lwork, liwork;
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
            const Cone * __restrict k,
            scs_int ** __restrict boundaries);

    ConeWork *initCone(const Cone * __restrict k);

    char *getConeHeader(const Cone *k);

    scs_int validateCones(
            const Data * __restrict d, 
            const Cone * __restrict k);

    /** 
     * pass in iter to control how accurate the cone projection
     * with iteration, set iter < 0 for exact projection, warm_start contains guess
     * of solution, can be SCS_NULL
     */
    scs_int projDualCone(
            scs_float * __restrict x,
            const Cone * __restrict k,
            ConeWork * __restrict c,
            const scs_float * __restrict warm_start,
            scs_int iter);

    void finishCone(
            ConeWork * __restrict coneWork);

    char *getConeSummary(
            const Info * __restrict info, 
            ConeWork * __restrict c);

#ifdef __cplusplus
}
#endif
#endif
