clear all
tol = 1e-4;
rng('default')
rng(1);
load gong.mat;
%% SDP1
sound(y);

% -- Run SCS
id = 777100000;
o = profile_ops;
o.do_super_scs = 0;
profile_runner_qp;
sound(y);

% -- Run SuperSCS
id = id + 1;
o.do_super_scs = 1;
o.k0 = 0;
o.direction = 100;
o.memory = 100;
profile_runner_qp;
sound(y);

% -- Run SuperSCS with AA, memory = 15 and k0
id = id + 1;
o.do_super_scs = 1;
o.direction = 150;
o.memory = 15;
o.k0 = 1;
profile_runner_qp;
sound(y);

% -- Run SuperSCS with AA, memory = 10 and k0
id = id + 1;
o.do_super_scs = 1;
o.direction = 150;
o.memory = 10;
o.k0 = 1;
profile_runner_qp;
sound(y);