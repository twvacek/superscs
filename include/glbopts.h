#ifndef SCS_GLB_H_GUARD
#define SCS_GLB_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
    
#ifdef RESTRICT
#undef RESTRICT
#endif
#define RESTRICT __restrict 
   

    /* redefine printfs and memory allocators as needed */
#ifdef MATLAB_MEX_FILE
#include "mex.h"
#define scs_printf mexPrintf
#define scs_free_ mxFree
#define scs_malloc_ mxMalloc
#define scs_calloc_ mxCalloc
#elif defined PYTHON
#include <Python.h>
#include <stdlib.h>
#define scs_printf(...)                                                        \
    {                                                                          \
        PyGILState_STATE gilstate = PyGILState_Ensure();                       \
        PySys_WriteStdout(__VA_ARGS__);                                        \
        PyGILState_Release(gilstate);                                          \
    }
#define scs_free_ free
#define scs_malloc_ malloc
#define scs_calloc_ calloc
#elif(defined(USING_R))
#include <stdlib.h>
#include <stdio.h>
#include <R_ext/Print.h> /* Rprintf etc */
#define scs_printf Rprintf
#define scs_free_ free
#define scs_malloc_ malloc
#define scs_calloc_ calloc
#else
#include <stdio.h>
#include <stdlib.h>
#define scs_printf printf
#define scs_free_ free
#define scs_malloc_ malloc
#define scs_calloc_ calloc
#endif

#define scs_free(x)  if ((x)!=NULL) {  scs_free_(x); x = SCS_NULL; }
#define scs_malloc(x) (((x) > 0) ? scs_malloc_(x) : SCS_NULL)
#define scs_calloc(x, y) scs_calloc_(x, y)

#ifdef DLONG
#ifdef _WIN64
    typedef __int64 scs_int;
    /* #define scs_int __int64 */
#else
    typedef long scs_int;
    /* #define scs_int long */
#endif
#else
    typedef int scs_int;
#endif

#ifndef FLOAT
    typedef double scs_float;
#ifndef NAN
#define NAN ((scs_float)0x7ff8000000000000)
#endif
#ifndef INFINITY
#define INFINITY NAN
#endif
#else
    typedef float scs_float;
#ifndef NAN
#define NAN ((float)0x7fc00000)
#endif
#ifndef INFINITY
#define INFINITY NAN
#endif
#endif

#define SCS_NULL 0

#ifndef MAX
    /**
     * Maximum value of two scalars
     */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
    /**
     * Minimum value of two scalars
     */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef ABS
    /**
     * Absolute value of a number
     */
#define ABS(x) (((x) < 0) ? -(x) : (x))
#endif

#ifndef SGN
    /**
     * Sign of a number
     */
#define SGN(x) (((x) >= 0) ? 1.0 : -1.0) 
#endif

#ifndef POWF
#ifdef FLOAT
#define POWF powf
#else
#define POWF pow
#endif
#endif

#ifndef SQRTF
#ifdef FLOAT
#define SQRTF sqrtf
#else
#define SQRTF sqrt
#endif
#endif


    /**
     * \brief Data of a conic optimization problem
     * 
     * Problem dimensions, matrix \f$A\f$, vectors \f$b\f$ and \f$c\f$ and
     * settings.
     */
    typedef struct SCS_PROBLEM_DATA ScsData;
    /**
     * \brief Solver settings
     */
    typedef struct SCS_SETTINGS ScsSettings;
    /**
     * \brief Primal and dual solution.
     */
    typedef struct SCS_SOL_VARS ScsSolution;
    /**
     * \brief Solver statistics and information.
     */
    typedef struct SCS_INFO ScsInfo;
    /**
     * \brief Scaling/normalization matrices.
     */
    typedef struct SCS_SCALING ScsScaling;
    /**
     * \brief SuperSCS Workspace structure.
     */
    typedef struct SCS_WORK ScsWork; 
    /**
     * \brief Cartesian product of cones.
     * 
     * \sa \ref page_cones "Cones documentation"
     */
    typedef struct SCS_CONE ScsCone;
    /**
     * A finite-memory cache where \f$(Y, U)\f$ are stored.
     */
    typedef struct SCS_DIRECTION_MEMORY DirectionCache;

    /**
     * \brief Direction computation method (in SuperSCS)
     */
    typedef
    enum direction_enum {
        /**
         * Restarted Broyden method
         */
        restarted_broyden = 100,
        /**
         * Restarted Broyden method (experimental)
         */
        restarted_broyden_v2 = 101,
        /**
         * Anderson's acceleration
         */
        anderson_acceleration = 150,
        /**
         * Using \f$d_k = - R_k\f$
         */
        fixed_point_residual = 200,
        /**
         * Full Broyden method
         */
        full_broyden = 300
    }
    ScsDirectionType;

#ifdef __cplusplus
}
#endif
#endif
