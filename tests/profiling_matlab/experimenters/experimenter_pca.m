clear all
tol = 1e-4;
rng('default')
rng(1);
load gong.mat;
%% PCA
% 1. Run SCS
sound(y);
id = 100034800;
o = profile_ops;
o.do_super_scs = 0;
profile_runner_pca;
sound(y);

% 2. Run SuperSCS (Broyden, mem=100)
id = id + 1;
o.do_super_scs = 1;
o.direction = 100;
o.memory = 100;
profile_runner_pca;
sound(y);

% 3. Run SuperSCS (Broyden, mem=100, k0=1)
id = id + 1;
o.do_super_scs = 1;
o.direction = 100;
o.memory = 100;
o.k0=1;
profile_runner_pca;
sound(y);

% 4. Run SuperSCS (Anderson, mem=20)
id = id + 1;
o.do_super_scs = 1;
o.direction = 150;
o.memory = 20;
o.k0=0;
profile_runner_pca;
sound(y);

% 5. Run SuperSCS (Anderson, mem=20, K0=1)
id = id + 1;
o.do_super_scs = 1;
o.direction = 150;
o.memory = 15;
o.k0=1;
profile_runner_pca;
sound(y);
