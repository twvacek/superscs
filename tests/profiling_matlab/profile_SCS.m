o = profile_ops;
tol = 1e-3;

%% LASSO PROBLEMS (600)
log_lasso = [];
reps = 5;
for n = round(logspace(3, 4, 3)),
    for mu = logspace(-2,0,4),
        for rca = logspace(-5,-1,5),
            for dens = [0.1 0.5],
                problem.n = n;
                problem.m = ceil(n/5);
                problem.s = ceil(n/10);
                problem.mu = mu;
                problem.density = dens;
                problem.rcA = rca;
                for r=1:reps, % repetitions (problem is random)
                    profile_lasso(problem, tol, o);
                    % log results
                    load('temp.mat');
                    data = rmfield(data,'A');
                    out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
                    out.cost = info.solveTime/strcmp('Solved',info.status);
                    log_lasso = [log_lasso, out];
                end
            end
        end
    end
end
delete('temp.mat');
save 'LASSO.mat' log_lasso

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

%% PCA
log_pca = [];
for d=100:100:800, %9
    o.verbose = 2;
    problem.d = d;
    problem.p = 5;
    problem.density = 0.1;
    problem.rcA = 0.0001;
    problem.lam = 10;
    profile_pca(problem, tol, o);
    % log results
    load('temp.mat');
    data = rmfield(data,'A');
    out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
    out.cost = info.solveTime/strcmp('Solved',info.status);
    log_pca = [log_pca, out];
end



%% NORM-CONSTRAINED
log_normc = [];
for m = [500 1000],
    problem.m = m;
    problem.n = ceil(problem.m/2);
    problem.p = round(2.5 * problem.n);
    problem.density= 0.5;
    problem.rca = 0.01;
    problem.density_c = 0.1;
    problem.bmag = 10;
    problem.Gmag = 2;
    
    profile_normcon(problem, tol, o);
    
    % log results
    load('temp.mat');
    data = rmfield(data,'A');
    out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
    out.cost = info.solveTime/strcmp('Solved',info.status);
    log_normc = [log_normc, out];
end