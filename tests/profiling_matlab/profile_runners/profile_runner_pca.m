% PCA PROBLEMS [PCA-1]
rng(1); % for reproducibility (so that every time this script is called,
        % the same problems will be run).
records = [];
reps = 4;
k=0;
for d=[50 100 150 200],
    problem.d = d;
    problem.p = 5;
    problem.density = 0.1;
    problem.rcA = 0.0001;
    problem.lam = 10;
    for r=1:reps,
        k = k+1;
        fprintf('PCA PROBLEM #%d [d=%d]\n', k, d);
        profile_pca(problem, tol, o);
        % log results
        load('temp.mat');
        data = rmfield(data,'A');
        out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
        out.cost = info.solveTime/strcmp('Solved',info.status);
        records = [records, out];
    end
end
delete('temp.mat');
fname = ['profile_results/' num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(o, tol, 'PCA-1', id, records);
