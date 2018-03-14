% PCA PROBLEMS [PCA-1B]e
rng(1); % for reproducibility (so that every time this script is called,
% the same problems will be run).
records = [];
reps = 3;
k=0;

for n = [50 80 100],
    for log_eig_min = [-1.5 -0.5]
        for log_eig_max = [0 1]
            problem.n = n;
            problem.log_eig_min = log_eig_min;
            problem.log_eig_max = log_eig_max;
            for r=1:reps,
                k = k+1;
                fprintf(...
                    ['SDP-2 PROBLEM #%d ', ...
                    '[n=%d, log_eig = (%f, %f), rep=%d]\n'],...
                    k, n, log_eig_min, log_eig_max, r);
                profile_sdp2(problem, tol, o);
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
register_profile_data(o, tol, 'SDP-2', id, records);
