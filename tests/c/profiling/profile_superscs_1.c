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
 * File:   profile_superscs_1.c
 * Author: Pantelis Sopasakis
 *
 * Created on April 11, 2018, 11:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "scs.h"

#ifndef SCS_DIR
#define SCS_DIR restarted_broyden
#endif

#ifndef SCS_MEM
#define SCS_MEM 50
#endif

int main(int argc, char** argv) {
    ScsData * data = SCS_NULL;
    ScsCone * cone = SCS_NULL;
    ScsInfo * info = scs_init_info();
    ScsSolution * sol = scs_init_sol();
    const char * filepath = "tests/c/data/liswet1.yml";
    scs_int status;

    status = scs_from_YAML(filepath, &data, &cone);

    if (status != 0) {
        printf("Parsing of %s failed!\n", filepath);
        return 2;
    }

    data->stgs->do_super_scs = 1;
    data->stgs->direction = (ScsDirectionType) (SCS_DIR);
    data->stgs->memory = (scs_int) (SCS_MEM);
    data->stgs->cg_rate = 1.2;
    data->stgs->verbose = 1;
    if (data->stgs->direction == restarted_broyden) {
        data->stgs->k0 = 0;
    }
    data->stgs->eps = 1e-3;
    data->stgs->max_iters = 1e4;
    status = scs(data, cone, sol, info);

    printf("status = %d\n", status);

    scs_free_data(data, cone);
    scs_free_info(info);
    scs_free_sol(sol);

    return (EXIT_SUCCESS);
}

