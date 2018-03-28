clear all
tol = 1e-4;
rng('default')
rng(1);
load gong.mat;

%% SDP1
sound(y);

% 1. Run SCS
id = 256583398;
o = profile_ops; 
o.do_super_scs = 0;
profile_runner_sdp2;
sound(y);


id = id + 1;
o.do_super_scs = 1;
o.direction = 100;
o.memory = 50;
profile_runner_sdp2;
sound(y);

id = id + 1;
o.do_super_scs = 1;
o.direction = 150;
o.memory = 15;
o.k0 = 1;
profile_runner_sdp2;
sound(y);