clear
tol = 1e-4;
rng('default')
rng(1);
load gong.mat;
%% PCA
% 1. Run SCS
sound(y);
id = 100034800;
o = SuperSCSConfigFactory.scsConfig();
profile_runner_pca;
sound(y);

% 2. Run SuperSCS (Broyden, mem=100, k0=0)
id = id + 1;
o = SuperSCSConfigFactory.broydenConfig();
o.k0 = 0;
o.memory = 100;
profile_runner_pca;
sound(y);

% 3. Run SuperSCS (Broyden, mem=100, k0=1)
id = id + 1;
o = SuperSCSConfigFactory.broydenConfig();
o.memory = 100;
profile_runner_pca;
sound(y);

% 4. Run SuperSCS (Anderson, mem=10, 15, 20)
id = id + 1;
o = SuperSCSConfigFactory.andersonConfig();
for mem = [10 15 20]
    o.memory = mem;
    profile_runner_pca;
    sound(y);
end