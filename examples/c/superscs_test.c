// FILE: superscs_test.c 

#include <stdio.h>
#include <stdlib.h>
#include "superscs/scs.h"
#include "superscs/util.h"

int main(int argc, char** argv) {
    ScsData * data;
    ScsCone * cone;
    ScsInfo * info = scs_init_info();
    ScsSolution * sol = scs_init_sol();
    const char * filepath = "tests/c/data/test-1.yml";
    scs_int status;
    
    // load problem from file
    status = scs_from_YAML(filepath, &data, &cone);
    
    // solver options
    scs_set_restarted_broyden_settings(data, 100);    
    data->stgs->verbose = 1;
    
    // solve the problem
    status = scs(data, cone, sol, info);
    
    // free allocated memory
    scs_free_data_cone(data, cone);
    scs_free_info(info);
    scs_free_sol(sol);
    
    return (EXIT_SUCCESS);
}

