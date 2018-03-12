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
for mem = [3 4 5 7 9 11 15 20 25 30 50],    
    id = id + 1;
    o = profile_ops;
    o.direction = 150;
    o.memory = mem;
    profile_runner_lasso;
end
