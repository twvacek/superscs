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