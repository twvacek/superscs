clear; clc;
rng('default')
rng(1);
load gong.mat;
tol = 1e-4;

%% LASSO (288 problems)
sound(y);

% 1. Run SCS
id = 8843960000;
solver_options = SuperSCSConfigFactory.scsConfig();
solver_options.tolerance = tol;
profile_runner_lasso(solver_options, id);
sound(y);

% 2A. Run SuperSCS with different memory lengths (k1,k2: activated, k0=0)
id = id + 1;
solver_options = SuperSCSConfigFactory.broydenConfig();
solver_options.tolerance = tol;
solver_options.k0 = 0;
for mem = [50 100],    
    id = id + 1;
    solver_options.memory = mem;
    profile_runner_lasso(solver_options, id);
    sound(y);
end

% 2B. Run SuperSCS with different memory lengths (k0,k1,k2: activated)
id = id + 1;
solver_options = SuperSCSConfigFactory.broydenConfig();
solver_options.tolerance = tol;
solver_options.k0 = 1;
for mem = [50 100],    
    id = id + 1;
    solver_options.memory = mem;
    profile_runner_lasso(solver_options, id);
    sound(y);
end

% 3. Run SuperSCS with Anderson's acceleration (k0,k1,k2: activated)
id = id + 1;
solver_options.do_super_scs = 1;
solver_options.tolerance = tol;
for mem = [3 4 5 7 9 11 15 20 25 30 50],    
    id = id + 1;
    solver_options = SuperSCSConfigFactory.andersonConfig();
    solver_options.memory = mem;
    profile_runner_lasso(solver_options, id);
    sound(y);
end