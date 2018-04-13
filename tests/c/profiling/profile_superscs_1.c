/* 
 * File:   profile_superscs_1.c
 * Author: chung
 *
 * Created on April 11, 2018, 11:31 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "scs.h"

int main(int argc, char** argv) {
    Data * data = SCS_NULL;
    Cone * cone = SCS_NULL;
    Info * info = initInfo();
    Sol * sol = initSol();
    const char * filepath = "tests/c/data/liswet1.yml";
    scs_int status;

    status = fromYAML(filepath, &data, &cone);

    data->stgs->do_super_scs = 1;
    data->stgs->direction = restarted_broyden;
    data->stgs->memory = 50;
    data->stgs->cg_rate = 1.2;
    data->stgs->verbose = 1;
    data->stgs->k0 = 0;
    data->stgs->eps = 1e-3;
    data->stgs->max_iters = 1e4;
    status = scs(data, cone, sol, info);

    printf("status = %d\n", status);
    
    freeData(data, cone);
    freeInfo(info);
    freeSol(sol);

    return (EXIT_SUCCESS);
}

