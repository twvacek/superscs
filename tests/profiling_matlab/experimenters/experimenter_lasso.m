clear all
tol = 1e-4;
rng('default')
rng(1);

%% LASSO (288 problems)

% 1. Run SCS
id = 712698682;
o = profile_ops; 
o.do_super_scs = 0;
profile_runner_lasso;

% 2. Run SuperSCS with different memory lengths
id = id + 1;
o.do_super_scs = 1;
for mem = [100],    
    id = id + 1;
    o.memory = mem;
    profile_runner_lasso;
end

% 3. Run SuperSCS with Anderson's acceleration
id = id + 1;
o.do_super_scs = 1;
for mem = [3 4 5 7 9 11 15 20],    
    id = id + 1;
    o = profile_ops;
    o.direction = 150;
    o.memory = mem;
    profile_runner_lasso;
end
%%
for th = [0.05 0.2 0.3 0.4 0.5 0.6],    
    id = id + 1;
    o = profile_ops;
    o.thetabar = th;
    profile_runner_lasso;
end

for sse = [0.995 0.99 0.98 0.97 0.95]
    id = id + 1;
    o = profile_ops;
    o.sse = sse;
    o.thetabar = 0.5;
    profile_runner_lasso;
end

id = 12570201;
o = profile_ops;
o.memory = 100;
o.ls = 5;
profile_runner_lasso;
