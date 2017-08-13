clear;
o = profile_ops;
tol = 1e-3;
id = round(rand*1e5);
o.do_super_scs = 1;
o.memory = 50;
o.thetabar = 0.05;
%% LASSO PROBLEMS (288)
records = [];
reps = 3;
k = 0;
for n = round(logspace(2.8, 3.2, 3)), % [631 1000 1585]
    for mu = logspace(-2,0,4), %[0.01  0.0464 0.2154 1.0]
        for rca = logspace(-5,-1,4), % [1e-5 2e-4 0.0046 0.1]
            for dens = [0.1 0.5],
                problem.n = n;
                problem.m = ceil(n/5);
                problem.s = ceil(n/10);
                problem.mu = mu;
                problem.density = dens;
                problem.rcA = rca;
                for r=1:reps, % repetitions (problem is random)
                    k = k + 1;
                    fprintf('PROBLEM #%d [n=%d, mu=%g, rca=%g, density=%g, rep=%d]\n', ...
                        k, n, mu, rca, dens, r);
                    profile_lasso(problem, tol, o);
                    % log results
                    load('temp.mat');
                    data = rmfield(data,'A');
                    out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
                    out.cost = info.solveTime/strcmp('Solved',info.status);
                    records = [records, out];
                end
            end
        end
    end
end
delete('temp.mat');
fname = ['profile_results/' num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(o, tol, 'LASSO', id, records);

%% LOGREG (180)
log_logreg = [];
reps = 5;
for p = round(logspace(1, 3, 3)),
    for b = [10 50 100]
        for lam = logspace(-2,-0.5,4),
            problem.density = 0.1;
            problem.p = 100;   % features
            problem.q = b*problem.p; % samples
            problem.lam = lam;
            o.verbose = 2;
            for r = 1:reps,
                profile_logreg(problem, tol, o);
                % log results
                load('temp.mat');
                data = rmfield(data,'A');
                out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
                out.cost = info.solveTime/strcmp('Solved',info.status);
                log_logreg = [log_logreg, out];
            end
        end
    end
end
delete('temp.mat');
fname = ['profile_results/LOGREG_' num2str(o.do_super_scs) '_' num2str(id) '.mat'];
save(fname, 'log_logreg')

%% PCA
log_pca = [];
reps = 5;
for d=100:100:800, %9
    o.verbose = 2;
    problem.d = d;
    problem.p = 5;
    problem.density = 0.1;
    problem.rcA = 0.0001;
    problem.lam = 10;
    for r=1:reps,
        profile_pca(problem, tol, o);
        % log results
        load('temp.mat');
        data = rmfield(data,'A');
        out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
        out.cost = info.solveTime/strcmp('Solved',info.status);
        log_pca = [log_pca, out];
    end
end
delete('temp.mat');
save 'profile_results/PCA.mat' log_pca

%% NORM-CONSTRAINED
log_normc = [];
reps = 5;
for m = [500 1000],
    problem.m = m;
    problem.n = ceil(problem.m/2);
    problem.p = round(2.5 * problem.n);
    problem.density= 0.5;
    problem.rca = 0.01;
    problem.density_c = 0.1;
    problem.bmag = 10;
    problem.Gmag = 2;
    
    for r=1:5,
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

for n=100:50:2000,
    problem.n = 500;
    problem.rho = 0.001;
    problem.Q_log_eig_min = -4;
    problem.Q_log_eig_max = 8;
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
