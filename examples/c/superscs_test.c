// FILE: superscs_test.c 

#include <stdio.h>
#include <stdlib.h>
#include "scs.h"
int main(int argc, char** argv) {
    ScsData * data = SCS_NULL;
    ScsCone * cone = SCS_NULL;
    ScsInfo * info = scs_init_info();
    ScsSolution * sol = scs_init_sol();
    const char * filepath = "tests/c/data/test-1.yml";
    scs_int status;
    // load problem from file
    status = scs_from_YAML(filepath, &data, &cone);
    // solver options
    data->stgs->do_super_scs = 1;
    data->stgs->direction = restarted_broyden;
    data->stgs->memory = 100;
    data->stgs->verbose = 1;
    // solve the problem
    status = scs(data, cone, sol, info);
    // free allocated memory
    scs_free_data(data, cone);
    scs_free_info(info);
    scs_free_sol(sol);
    return (EXIT_SUCCESS);
}

