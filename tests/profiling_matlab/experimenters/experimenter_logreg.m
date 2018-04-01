clear; clc;
rng('default')
rng(1);
load gong.mat;
tol = 1e-4;

%%
% 1. Run SCS
id = 78234961000;
solver_options = SuperSCSConfigFactory.scsConfig('tolerance', tol);
profile_runner_logreg(solver_options, id);
sound(y);

% 2. Run Broyden (k1,k2, not k0)
solver_options = SuperSCSConfigFactory.broydenConfig('tolerance', tol, 'k0', 0);
for mem = [50, 100]
    id = id + 1;
    solver_options.memory = mem;
    profile_runner_logreg(solver_options, id);
    sound(y);
end

% 3. Run Anderson's acceleration (k0,k1,k2)
id = id + 1;
solver_options = SuperSCSConfigFactory.andersonConfig('tolerance', tol);
for mem = [5, 10, 15]
    id = id + 1;
    solver_options.memory = mem;
    profile_runner_logreg(solver_options, id);
    sound(y);
end

% 4. Run Broyden (k0,k1,k2: all activated)
id = id + 1;
solver_options = SuperSCSConfigFactory.andersonConfig('tolerance', tol);
profile_runner_logreg(solver_options, id);
sound(y);