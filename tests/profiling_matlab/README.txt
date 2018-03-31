Profiling framework

This folder and its subfolders contain MATLAB functions
and scripts to benchmark SuperSCS and help determine an
optimal configuration (choice of directions, memory, etc)


Contents:
 profiling_helpers/    functions used to run profiling problems
 profile_runners/      functions which call the profile helpers
                       with different problem parameters; these
                       define a suite of numerical experiments
 experimenters/        experimenters  call the  profile runners 
                       with different solver parameters.
 profile_results/      profiling  results  are  stored  in this 
                       folder

 
