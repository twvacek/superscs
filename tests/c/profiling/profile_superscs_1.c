/* 
 * File:   profile_superscs_1.c
 * Author: chung
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

    data->stgs->do_super_scs = 1;
    data->stgs->direction = (ScsDirectionType)(SCS_DIR);
    data->stgs->memory = (scs_int)(SCS_MEM);
    data->stgs->cg_rate = 1.2;
    data->stgs->verbose = 1;
    if (data->stgs->direction == restarted_broyden){
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

