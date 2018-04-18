clear; clc;
rng('default')
rng(1);
load gong.mat;
tol = 1e-4;              % tolerance
max_iter = 15000;        % 15k iterations maximum
max_time = 2 * 60 * 1e3; % 2 minutes max

%%
sound(y);

% 1. Run SCS
id = 41702210;
solver_options = SuperSCSConfig.scsConfig(...
    'tolerance', tol, ...
    'max_iters', max_iter, ...
    'max_time_milliseconds', max_time);
profile_runner_normcon(solver_options, id);
sound(y);

% 2. Broyden, memory = 100, k0: deactivated
id = id + 1;
for b_mem = [50, 100]
    solver_options = SuperSCSConfig.broydenConfig(...
        'tolerance', tol, ...
        'max_iters', max_iter, ...
        'max_time_milliseconds', max_time,...
        'k0', 0, ...
        'memory', 50);
    profile_runner_normcon(solver_options, id);
    sound(y);
    id = id + 1;
end

% 3. Anderson's acceleration, memory = 5, 10, 15, k0: activated
for a_mem = [5, 10, 15]
    id = id + 1;
    solver_options = SuperSCSConfig.andersonConfig(...
        'tolerance', tol, ...
        'k0', 1, ...
        'memory', a_mem, ...
        'max_iters', max_iter, ...
        'max_time_milliseconds', max_time);
    profile_runner_normcon(solver_options, id);
    sound(y);
end