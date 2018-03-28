function profile_runner_lasso(solver_options, id, runner_options)
% LASSO PROBLEMS

rng(1); % for reproducibility (so that every time this script is called,
        % the same problems will be run).
records = []; info = []; data = []; K = []; pars = []; problem = [];
k = 0;

reps = 3;
span_n = round(logspace(2.8, 3.4, 4)); 
span_mu = logspace(-2,0,3);
span_rca = logspace(-5,-1,4);
span_dens = [0.1 0.5];

if nargin >=3
    if isfield(runner_options, 'reps'), reps = runner_options.reps; end
    if isfield(runner_options, 'span_n'), span_n = runner_options.span_n; end
    if isfield(runner_options, 'span_mu'), span_mu = runner_options.span_mu; end
    if isfield(runner_options, 'span_rca'), span_rca = runner_options.span_rca; end
    if isfield(runner_options, 'span_dens'), span_dens = runner_options.span_dens; end
end

for n = span_n, 
    for mu = span_mu, 
        for rca = span_rca, 
            for dens = span_dens,
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
                    profile_lasso(problem, solver_options);
                    % log results
                    load(solver_options.dumpfile);
                    data = rmfield(data,'A');
                    out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
                    out.cost = info.solveTime/isempty(strfind(info.status, 'Inaccurate'));
                    records = [records, out];
                end
            end
        end
    end
end
delete(solver_options.dumpfile);
fname = [get_scs_rootdir() 'tests/profiling_matlab/profile_results/' ...
    num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(solver_options, 'LASSO', id, records);