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
#ifndef UTIL_H_GUARD
#define UTIL_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdarg.h>
#include "scs.h"

    /* timing code courtesy of A. Domahidi */
#if (defined NOTIMER)
    typedef void *timer;
#elif(defined _WIN32 || defined _WIN64 || defined _WINDLL)
    /* Use Windows QueryPerformanceCounter for timing */
#include <windows.h>

    typedef struct timer {
        LARGE_INTEGER scs_tic;
        LARGE_INTEGER scs_toc;
        LARGE_INTEGER freq;
    } timer;

#elif(defined __APPLE__)
    /* Use MAC OSX mach_time for timing */
#include <mach/mach_time.h>

    typedef struct timer {
        uint64_t scs_tic;
        uint64_t scs_toc;
        mach_timebase_info_data_t tinfo;
    } timer;

#else
    /* Use POSIX clock_gettime() for timing on other machines */
#include <time.h>

    /** 
     * \brief SCS timer  
     */
    typedef struct timer {
        struct timespec tic;
        struct timespec toc;
    } timer;

#endif

    /* these all return milli-seconds */

    /**
     * \brief Starts the timer
     * @param t timer
     */
    void scs_tic(timer *t);
    /**
     * \brief Stops the timer 
     * 
     * This function prints a message of the form: 
     * 
     * ~~~~~
     * time: %8.4f milli-seconds.\n
     * ~~~~~
     * 
     * to the standard output using \c printf.
     * 
     * @param t timer 
     * @return elapsed time in milliseconds
     */
    scs_float scs_toc(timer *t);
    /**
     * \brief Stops the timer and prints a custom message
     * 
     * 
     * @param str string
     * @param t timer 
     * @return elapsed time
     */
    scs_float scs_strtoc(char *str, timer *t);
    /**
     * \brief Stops the timer 
     * 
     * \note In contrast to #scs_toc, this function does not print anything
     * 
     * @param t timer 
     * @return elapsed time in milliseconds
     * 
     * @sa #scs_toc
     */
    scs_float scs_toc_quiet(timer *t);

    /**
     * \brief Prints the content of a Cone object
     * @param k pointer to cone
     */
    void scs_print_cone_data(const ScsCone * RESTRICT k);
    /**
     * \brief Prints the content of a Data object
     * @param d pointer to data
     */
    void scs_print_data(const ScsData *d);
    /**
     * \brief Prints the content of a Work object
     * @param w pointer to work
     */
    void scs_print_work(const ScsWork *w);

    /**
     * \brief Prints an array
     * 
     * @param arr pointer to array
     * @param n length of array
     * @param name name of the array
     */
    void scs_print_array(
            const scs_float * RESTRICT arr, 
            scs_int n, 
            const char *RESTRICT name);

    /**
     * \brief Sets the settings to certain default values
     * 
     * <table>
     * <tr><th>Parameter<th>Default value<th>Default value Macro
     * <tr><td>\ref ScsSettings#normalize "normalize"<td>1<td>::SCS_NORMALIZE_DEFAULT
     * <tr><td>\ref ScsSettings#scale "scale"<td>1.0<td>::SCS_SCALE_DEFAULT
     * <tr><td>\ref ScsSettings#rho_x "rho_x"<td>0.001<td>::SCS_RHO_X_DEFAULT
     * <tr><td>\ref ScsSettings#max_iters "max_iters"<td>10000<td>::SCS_MAX_ITERS_DEFAULT
     * <tr><td>\ref ScsSettings#max_time_milliseconds "max_time_milliseconds"<td>300000<td>::SCS_MAX_TIME_MILLISECONDS
     * <tr><td>\ref ScsSettings#previous_max_iters "previous_max_iters"<td>-1<td>::SCS_PMAXITER_DEFAULT
     * <tr><td>\ref ScsSettings#eps "eps"<td>1e-3<td>::SCS_EPS_DEFAULT
     * <tr><td>\ref ScsSettings#alpha "alpha"<td>1.5<td>::SCS_ALPHA_DEFAULT
     * <tr><td>\ref ScsSettings#verbose "verbose"<td>1<td>::SCS_VERBOSE_DEFAULT
     * <tr><td>\ref ScsSettings#warm_start "warm_start"<td>0<td>::SCS_WARM_START_DEFAULT
     * <tr><td>\ref ScsSettings#do_super_scs "do_super_scs"<td>1<td>::SCS_DO_SUPERSCS_DEFAULT
     * <tr><td>\ref ScsSettings#k0 "k0"<td>0<td>::SCS_K0_DEFAULT
     * <tr><td>\ref ScsSettings#k1 "k1"<td>1<td>::SCS_K1_DEFAULT
     * <tr><td>\ref ScsSettings#k2 "k2"<td>1<td>::SCS_K2_DEFAULT
     * <tr><td>\ref ScsSettings#c_bl "c_bl"<td>0.999<td>::SCS_C_BL_DEFAULT
     * <tr><td>\ref ScsSettings#c_bl "c1"<td>0.9999<td>::SCS_C1_DEFAULT
     * <tr><td>\ref ScsSettings#ls "ls"<td>10<td>::SCS_LS_DEFAULT
     * <tr><td>\ref ScsSettings#sse "sse"<td>0.999<td>::SCS_SSE_DEFAULT
     * <tr><td>\ref ScsSettings#beta "beta"<td>0.5<td>::SCS_BETA_DEFAULT
     * <tr><td>\ref ScsSettings#sigma "sigma"<td>0.01<td>::SCS_SIGMA_DEFAULT
     * <tr><td>\ref ScsSettings#direction "direction"<td>\ref restarted_broyden "restarted_broyden"
     *     <td>::SCS_DIRECTION_DEFAULT
     * <tr><td>\ref ScsSettings#thetabar "thetabar"<td>0.1<td>::SCS_THETABAR_DEFAULT
     * <tr><td>\ref ScsSettings#memory "memory"<td>10<td>::SCS_MEMORY_DEFAULT
     * <tr><td>\ref ScsSettings#broyden_init_scaling "broyden_init_scaling"<td>1<td>::SCS_BROYDEN_ISCS_SCALE_DEFAULT
     * <tr><td>\ref ScsSettings#do_record_progress "do_record_progress"<td>0<td>::SCS_DO_RECORD_PROGRESS_DEFAULT
     * <tr><td>\ref ScsSettings#do_override_streams "do_override_streams"<td>0<td>::SCS_OVERRIDE_STREAMS_DEFAULT
     * <tr><td>\ref ScsSettings#output_stream "output_stream"<td>\c stdout <td>::SCS_OUT_STREAM_DEFAULT
     * </table>
     * 
     * @param d Pointer to data
     * 
     * \warning If you want to increase the maximum number of iteration with respect
     * to the previous run and you have set \ref ScsSettings#do_record_progress "do_record_progress"
     * to \c 1, then you should not use this function. If you really want to use it, however,
     * you should set the parameter \ref ScsSettings#previous_max_iters "previous_max_iters"
     * to the maximum number of iterations you used in the previous run. This is in 
     * order to avoid memory management errors. 
     * 
     * \warning Alternatively, a simple solution is to invoke ::scs_free_info after you 
     * call ::scs and then again ::scs_init_info. Then it is safe to call this function and
     * run ::scs again.
     * 
     * \note If you have set \ref ScsSettings#do_record_progress "do_record_progress" to \c 0,
     * you may ignore this warning.
     * 
     * \sa \ref sec_superscs_config_factory "Easy configuration in MATLAB CVX"
     */
    void scs_set_default_settings(ScsData * RESTRICT d);

    /**
     * \brief Frees the memory allocated for a Sol object
     * 
     * @param sol pointer to allocated #ScsSolution structure
     * 
     * \sa scs_init_sol
     */
    void scs_free_sol(ScsSolution * RESTRICT sol);
    /**
     * \brief Frees the memory allocate of a Data and a Cone object
     * @param d pointer to allocated #ScsData structure
     * @param k pointer to allocated #ScsCone structure
     * 
     * \sa scs_set_default_settings
     * \sa scs_init_data
     */
    void scs_free_data(ScsData * RESTRICT d, ScsCone * RESTRICT k);
    /**
     * \brief Frees the memory allocated for an Info object
     * @param info pointer to allocated #ScsInfo structure
     * 
     * \sa ::scs_init_info
     */
    void scs_free_info(ScsInfo * RESTRICT info);

    /**
     * \brief Custom print function for SCS.
     * 
     * This functions allows to print in different streams. The argument \c print_mode
     * specifies whether it is allowed to override the default stream and use a 
     * print function other than \c printf. 
     * 
     * For example, if SCS is interfaced via a MEX function, MATLAB expects to 
     * use \c printf exclusively which it then delegated to \c mexPrintf; a function
     * that prints the program's output to the console of MATLAB.
     * 
     * When SCS is called from other software, it is likely that \c print_mode 
     * has to be set to 0.
     * 
     * @param print_mode whether to override the default behavior (using \c printf)
     * @param __stream an output stream
     * @param __format string format 
     * @param ... arguments specifying data to print
     * @return return value of \c print or \c vfprintf
     */
    int scs_special_print(scs_int print_mode,
            FILE * RESTRICT __stream,
            const char *RESTRICT __format, ...);

#ifdef __cplusplus
}
#endif
#endif
