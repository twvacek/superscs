clear; clc;
rng('default')
rng(1);
load gong.mat;
tol = 1e-4;

%%
sound(y);

% 1. Run SCS
id = 281006000;
solver_options = SuperSCSConfig.scsConfig('tolerance', tol);
profile_runner_normcon(solver_options, id);
sound(y);

% 2. Broyden, memory = 100, k0: deactivated
id = id + 1;
solver_options = SuperSCSConfig.broydenConfig('tolerance', tol, 'k0', 0, ...
    'memory', 50);
profile_runner_normcon(solver_options, id);
sound(y);

% 3. Anderson's acceleration, memory = 5, 10, 15, k0: activated
for m = [5, 10, 15]
    id = id + 1;
    solver_options = SuperSCSConfig.andersonConfig('tolerance', tol, 'k0', 1, ...
        'memory', m);
    profile_runner_normcon(solver_options, id);
    sound(y);
end