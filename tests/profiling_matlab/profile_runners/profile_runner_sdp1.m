function profile_runner_sdp1(o, tol)
% SDP1 PROBLEMS [SDP1]

rng(1); % for reproducibility (so that every time this script is called,
% the same problems will be run).
records = []; info = []; data = []; K = []; pars = []; problem = [];
reps = 5; k=0;

for n = [50 100 150 200 250],
    problem.n = n;    
    for r=1:reps,
        k = k+1;
        fprintf(...
            ['SDP-1 PROBLEM #%d ', ...
            '[n=%d, rep=%d]\n'],...
            k, n, r);
        profile_sdp1(problem, tol, o);
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
register_profile_data(o, tol, 'SDP-1t', id, records);
