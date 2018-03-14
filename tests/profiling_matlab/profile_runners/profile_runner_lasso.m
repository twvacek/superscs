% LASSO PROBLEMS

rng(1); % for reproducibility (so that every time this script is called,
        % the same problems will be run).
records = [];
reps = 3;
k = 0;
for n = round(logspace(2.8, 3.4, 4)), 
    for mu = logspace(-2,0,3), 
        for rca = logspace(-5,-1,4), 
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
                    out.cost = info.solveTime/isempty(strfind(info.status, 'Inaccurate'));
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