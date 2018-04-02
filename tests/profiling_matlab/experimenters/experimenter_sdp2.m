clear
tol = 1e-4;
rng('default')
rng(1);
load gong.mat;

%% SDP2
sound(y);

% 1. Run SCS
id = 256583398;
solver_options = SuperSCSConfig.scsConfig('tolerance', tol); 
profile_runner_sdp2(solver_options, id);
sound(y);


% 2A. Broyden direction (memory = 50, k0: deactivated)
id = id + 1;
solver_options = SuperSCSConfig.broydenConfig('tolerance', tol, ...
    'memory', 50, 'k0', 0);
profile_runner_sdp2(solver_options, id);
sound(y);

% 2B. Broyden direction (memory = 50, k0: deactivated)
id = id + 1;
solver_options = SuperSCSConfig.broydenConfig('tolerance', tol, ...
    'memory', 50, 'k0', 0);
profile_runner_sdp2(solver_options, id);
sound(y);

% 3. Anderson's acceleration (memory = 15)
id = id + 1;
solver_options = SuperSCSConfig.andersonConfig('tolerance', tol, ...
    'memory', 15);
profile_runner_sdp2(solver_options, id);
sound(y);