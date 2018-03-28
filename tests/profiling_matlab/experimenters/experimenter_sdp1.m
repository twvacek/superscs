clear all
tol = 1e-4;
rng('default')
rng(1);
load gong.mat;

%% SDP1
sound(y);

% 1. Run SCS
id = 301593185;
o = SuperSCSConfigFactory.scsConfig();
profile_runner_sdp1;
sound(y);


% 2A. Broyden (k0=0)
id = id + 1;
o = SuperSCSConfigFactory.broydenConfig();
o.k0 = 0;
profile_runner_sdp1;
sound(y);

% 2A. Broyden (k0=0)
id = id + 1;
o.k0 = 1;
profile_runner_sdp1;
sound(y);

% 3. Anderson (k0=1)
id = id + 1;
o = SuperSCSConfigFactory.andersonConfig();
profile_runner_sdp1;
sound(y);