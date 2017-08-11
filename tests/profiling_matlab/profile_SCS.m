o = profile_ops;
tol = 1e-3;

%% LASSO PROBLEMS
log_lasso = [];
for n=round(logspace(3, 4, 3)),
    for mu=logspace(-2,0,4),
        problem.n = n;
        problem.m = ceil(n/5);
        problem.s = ceil(n/10);
        problem.mu = mu;
        problem.density = 0.1;
        problem.rcA = 0.01;
        for r=1:5, % repetitions (problem is random)
            profile_lasso(problem, tol, o);
            % log results
            load('temp.mat');
            out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
            out.cost = info.solveTime/strcmp('Solved',info.status);
            log_lasso = [log_lasso, out];
        end
    end
end
delete('lasso-temp.mat');

%% LOGREG
log_logreg = [];
for p = round(logspace(1, 3, 3)),
    for b = [10 50 100]
        for lam = logspace(-2,-0.5,4),
            problem.density = 0.1;
            problem.p = 100;   % features
            problem.q = b*problem.p; % samples
            problem.lam = lam;
            o.verbose = 2;
            profile_logreg(problem, tol, o);
            
            load('temp.mat');
            out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
            out.cost = info.solveTime/strcmp('Solved',info.status);
            log_logreg = [log_logreg, out];
        end
    end
end