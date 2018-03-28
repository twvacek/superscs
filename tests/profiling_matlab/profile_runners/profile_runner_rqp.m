% RQP PROBLEMS [RQP]

rng(1); % for reproducibility (so that every time this script is called,
% the same problems will be run).
records = [];
reps = 10;
k=0;
for n=[100 200 300 500],
    problem.n = n;    
    for r=1:reps,
        k = k+1;
        fprintf(['QP PROBLEM #%d [n=%d, rep=%d] (%s)\n'], k, n, r, datetime);
        start_time = tic;
        profile_rqp(problem, tol, o);
        elapsed_time_qp = toc(start_time);
        fprintf('Total elapsed time: %.2f min\n\n', elapsed_time_qp/60);
        % log results
        load(o.dumpfile);
        data = rmfield(data,'A');
        out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
        out.cost = info.solveTime/isempty(strfind(info.status, 'Inaccurate'));
        records = [records, out];
    end
end

delete(o.dumpfile);
fname = [get_scs_rootdir() 'tests/profiling_matlab/profile_results/' num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(o, tol, 'RQP', id, records);