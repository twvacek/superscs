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

/* 
 * File:   test_utilities.h
 * Author: Pantelis Sopasakis
 *
 * Created on May 26, 2017, 3:25 PM
 */

#ifndef TEST_UTILITIES_H
#define TEST_UTILITIES_H

#include "unit_test_util.h"
#include "linAlg.h"
#include "scs.h"
/* #include <time.h> */

#ifdef __cplusplus
extern "C" {
#endif

    bool testProjLinSysv2(char** str);

    bool testscs_scale_array(char** str);

    bool testGemm(char** str);

    bool testGemmCP(char** str);

    bool testGemmTransCP(char** str);

    bool testUnrolledDot(char** str);

    bool testscs_subtract_array(char** str);

    bool testNormDifference(char** str);

    bool testscs_millis_to_time(char** str);

    bool testAxpy2(char** str);

    bool testCglsSquareMatrix(char** str);

    bool testCglsTallMatrix(char** str);

    bool testCglsFatMatrix(char** str);

    bool testQrLsTallMatrix(char** str);

    bool testSvdLsTallMatrix(char** str);

    bool testSvdLsRankDeficient(char** str);


#ifdef __cplusplus
}
#endif

#endif /* TEST_UTILITIES_H */
