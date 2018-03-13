clear all
tol = 1e-4;
rng('default')
rng(1);

%% SDP1

% 1. Run SCS
id = 51800000;
o = profile_ops; 
o.do_super_scs = 0;
profile_runner_sdp1;


id = id + 1;
o.do_super_scs = 1;
o.direction = 100;
o.memory = 50;
profile_runner_sdp1;


id = id + 1;
o.do_super_scs = 1;
o.direction = 150;
o.memory = 10;
o.k0 = 1;
profile_runner_sdp1;
