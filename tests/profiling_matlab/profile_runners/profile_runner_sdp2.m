function profile_runner_sdp2(solver_options, id, runner_options)
%PROFILE_RUNNER_SDP2 runs a collection of SDP problems by invoking the
%helper function profile_sdp2
%
%Syntax:
%profile_runner_sdp2(solver_options, id)
%profile_runner_sdp2(solver_options, id, runner_options)
%
%

rng(1); % for reproducibility (so that every time this script is called,
% the same problems will be run).
records = []; info = []; data = []; K = []; pars = []; problem = [];

reps = 3;
span_n = [50 80 100 120];
span_log_eig_min = [-1.5 -0.5];
span_log_eig_max = [0 0.75];

if nargin >=3
    if isfield(runner_options, 'reps'), reps = runner_options.reps; end
    if isfield(runner_options, 'span_n'), span_n = runner_options.span_n; end
    if isfield(runner_options, 'span_log_eig_min'),
        span_log_eig_min = runner_options.span_log_eig_min;
    end
    if isfield(runner_options, 'span_log_eig_max'),
        span_log_eig_max = runner_options.span_log_eig_max;
    end
end


problem_data = cartesian(span_n, span_log_eig_min, span_log_eig_max, 1:reps);
n_problems = size(problem_data, 1);

for i = 1:n_problems,
    problem.n = problem_data(i,1);
    problem.log_eig_min = problem_data(i,2);
    problem.log_eig_max = problem_data(i,3);
    fprintf(...
        ['SDP-2 PROBLEM %3d/%3d ', ...
        '[n=%3d, log_eig = (%1.1f, %1.1f), rep=%1d] '],...
        i, n_problems, problem.n, problem.log_eig_min, problem.log_eig_max, ...
        problem_data(i,4));
    profile_sdp2(problem, solver_options);
    % log results
    load(solver_options.dumpfile);
    data = rmfield(data,'A');
    out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
    out.cost = info.solveTime/isempty(strfind(info.status, 'Inaccurate'));
    records = [records, out];
    fprintf('%s in %.1fs\n', info.status, info.solveTime/1e3);
end

delete(solver_options.dumpfile);
fname = [get_scs_rootdir() 'tests/profiling_matlab/profile_results/' ...
    num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(solver_options, 'SDP-V3', id, records);
