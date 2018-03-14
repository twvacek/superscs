% LOGISTIC REGRESSION (180 problems)
rng(1); % for reproducibility (so that every time this script is called,
        % the same problems will be run).
records = [];
reps = 5;
k = 0;
for p = [10 50 100],
    for b = [10 30 100],
        for lam = logspace(-2,-0.5,4), 
            problem.density = 0.1;
            problem.p = p;   % features
            problem.q = b*problem.p; % samples
            problem.lam = lam;
            for r = 1:reps,
                k = k + 1;
                fprintf('~~~ RUNNING PROBLEM #%d [p=%d, q=%d]\n', k, problem.p, problem.q);
                profile_logreg(problem, tol, o);
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
delete('temp.mat');
fname = ['profile_results/' num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(o, tol, 'LOGREG', id, records);
