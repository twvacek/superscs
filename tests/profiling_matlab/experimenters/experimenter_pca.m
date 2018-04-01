clear
tol = 1e-4;
rng('default')
rng(1);
load gong.mat;
%% PCA
% 1. Run SCS
sound(y);
id = 100034800;
solver_options = SuperSCSConfigFactory.scsConfig('tolerance', tol);
profile_runner_pca(solver_options, id);
sound(y);

% 2. Run SuperSCS (Broyden, mem=100, k0=0)
id = id + 1;
solver_options = SuperSCSConfigFactory.broydenConfig('tolerance', tol, 'k0', 0, 'memory', 100);
profile_runner_pca(solver_options, id);
sound(y);

% 3. Run SuperSCS (Broyden, mem=100, k0=1)
id = id + 1;
solver_options = SuperSCSConfigFactory.broydenConfig('tolerance', tol, 'memory', 100);
profile_runner_pca(solver_options, id);
sound(y);

% 4. Run SuperSCS (Anderson, mem=10, 15, 20)
id = id + 1;
solver_options = SuperSCSConfigFactory.andersonConfig('memory', 100);
for mem = [10 15 20]
    solver_options.memory = mem;
    profile_runner_pca(solver_options, id);
    sound(y);
end