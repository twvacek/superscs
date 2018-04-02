clear; clc;
rng('default')
rng(1);
load gong.mat;
tol = 1e-4;

%% LASSO (288 problems)
sound(y);

% 1. Run SCS
id = 8843960000;
solver_options = SuperSCSConfig.scsConfig('tolerance', tol);
profile_runner_lasso(solver_options, id);
sound(y);

% 2A. Run SuperSCS with different memory lengths (k1,k2: activated, k0=0)
id = id + 1;
solver_options = SuperSCSConfig.broydenConfig('tolerance', tol, 'k0', 0);
for mem = [50 100],    
    id = id + 1;
    solver_options.memory = mem;
    profile_runner_lasso(solver_options, id);
    sound(y);
end

% 2B. Run SuperSCS with different memory lengths (k0,k1,k2: activated)
id = id + 1;
solver_options = SuperSCSConfig.broydenConfig('tolerance', tol, 'k0', 0);
for mem = [50 100],    
    id = id + 1;
    solver_options.memory = mem;
    profile_runner_lasso(solver_options, id);
    sound(y);
end

% 3. Run SuperSCS with Anderson's acceleration (k0,k1,k2: activated)
id = id + 1;
solver_options = SuperSCSConfig.andersonConfig('tolerance', tol);
for mem = [5 10 15 20 25 30],    
    id = id + 1;   
    solver_options.memory = mem;
    profile_runner_lasso(solver_options, id);
    sound(y);
end