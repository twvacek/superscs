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
for mem = [50],    
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

%% LOGREG 
id = 789123100;
o = profile_ops;
o.do_super_scs = 0;
profile_runner_logreg;

id = id + 1;
o = profile_ops;
profile_runner_logreg;

for lbfgs_mem = [100],
    id = id + 1;
    o.memory = lbfgs_mem;
    profile_runner_logreg;
end
if 1>0,
    return;
end
%% PCA
id = 33319806700;
o = profile_ops;
profile_runner_pca;

id = id + 1;
o.do_super_scs = 0;
profile_runner_pca;

id = id + 1;
o.do_super_scs = 1;
o.memory = 100;
profile_runner_pca;
%% NORM-CONSTRAINED
o = profile_ops; 
log_normc = [];
reps = 5;
o.verbose = 2;
for m = [500 1000],
    problem.m = m;
    problem.n = round(problem.m/2);
    problem.p = round(2 * problem.n);
    problem.density= 0.5;
    problem.rca = 0.01;
    problem.density_c = 0.1;
    problem.bmag = 10;
    problem.Gmag = 1.5;
    
    for k=1:reps,
        profile_normcon(problem, tol, o);
        % log results
        load('temp.mat');
        data = rmfield(data,'A');
        out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
        out.cost = info.solveTime/strcmp('Solved',info.status);
        log_normc = [log_normc, out];
    end
end
delete('temp.mat');
save 'profile_results/NORMC.mat' log_normc


%% SDP1 [Matrix approximation]
reps = 5;
log_sdp1 = [];
for n = [100 500 800 1e3],
    problem.n = n;
    for r=1:reps,
        profile_sdp1(problem, tol, o);
        % log results
        load('temp.mat');
        data = rmfield(data,'A');
        out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
        out.cost = info.solveTime/strcmp('Solved',info.status);
        log_sdp1 = [log_sdp1, out];
    end
end
delete('temp.mat');
save 'profile_results/SDP1.mat' log_sdp1

%% SDP2 [Minimum trace]
log_sdp2 = [];

problem.n = 100;
problem.log_eig_min = -1;
problem.log_eig_max = 1;
profile_sdp2(problem, tol, o);



%% FUSED LASSO [TV regularization]

problem.m = 1000;
problem.ni = 10;
problem.k = 1000;
problem.rho=0.05;
problem.sigma=0.05;
profile_fused_lasso(problem, tol, o);

%% QP
log_qp = [];
reps = 5;
o.do_super_scs = 0;
o.memory = 100;
for n=500:50:2000,
    problem.n = n;
    problem.rho = 0.001;
    problem.Q_log_eig_min = -5;
    problem.Q_log_eig_max = -2;
    for r=1:reps,
        profile_qp(problem, tol, o);
        % log results
        load('temp.mat');
        data = rmfield(data,'A');
        out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
        out.cost = info.solveTime/strcmp('Solved',info.status);
        log_qp = [log_qp, out];
    end
end
delete('temp.mat');
save 'profile_results/QP.mat' log_qp

%% Performance profiling
