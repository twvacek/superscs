% PCA PROBLEMS [PCA-1B]e
rng(1); % for reproducibility (so that every time this script is called,
% the same problems will be run).
records = [];
reps = 2;
k=0;
for d=[50 120 140 180],
    for p = [5 8],
        for rca = logspace(-5,-2,3),
            for lam = [0.1 2 5],
                for dens = [0.05 0.1],
                    problem.d = d;
                    problem.p = p;
                    problem.density = dens;
                    problem.rcA = rca;
                    problem.lam = lam;
                    for r=1:reps,
                        k = k+1;
                        fprintf(...
                            ['PCA PROBLEM #%d ', ...
                            '[d=%d, p=%d, rca=%g, lam=%.1f, den=%.1f, rep=%d]\n'],...
                            k, d, p, rca, lam, dens, r);
                        profile_pca(problem, tol, o);
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
end
delete('temp.mat');
fname = ['profile_results/' num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(o, tol, 'PCA-1B', id, records);
