function profile_runner_logreg(solver_options, id, runner_options)

% LOGISTIC REGRESSION (288 problems)
rng(1); % for reproducibility (so that every time this script is called,
% the same problems will be run).
records = []; info = []; data = []; K = []; pars = []; problem = [];

reps = 2;
span_p         = [10 50 100];
span_b         = [20 100];
span_lam       = [0.01 0.2 3];
span_density   = [0.05 0.1];
span_w_density = [0.1 0.25]; 
span_sigma     = [0.1 3];

if nargin >=3
    if isfield(runner_options, 'reps'), reps = runner_options.reps; end
    if isfield(runner_options, 'span_p'), span_p = runner_options.span_p; end
    if isfield(runner_options, 'span_b'), span_b = runner_options.span_b; end
    if isfield(runner_options, 'span_lam'), span_lam = runner_options.span_lam; end
    if isfield(runner_options, 'span_density'), span_density = runner_options.span_density; end
    if isfield(runner_options, 'span_w_density'), span_w_density = runner_options.span_w_density; end
    if isfield(runner_options, 'span_sigma'), span_sigma = runner_options.span_sigma; end
end

problem_data = cartesian(span_p, span_b, span_lam, span_density, ...
    span_w_density, span_sigma, 1:reps);
n_problems = size(problem_data, 1);
fprintf('EXPERIMENTER_LOGREG: %d PROBLEMS\n', n_problems);

for i=1:n_problems,
    problem.p = problem_data(i,1);   % features
    b = problem_data(i,2);
    problem.q = b*problem.p; % samples
    problem.lam = problem_data(i,3);
    problem.density = problem_data(i,4);
    problem.sigma = problem_data(i,5);
    problem.w_density = problem_data(i,6);
    
    fprintf(['RUNNING PROBLEM %3d/%3d [p=%3d, q=%5d, lambda=%1.4f, ', ... 
        'density=%1.2f, w-density=%1.2f, sigma=%1.2f, r=%1d]\n'], ...
        i, n_problems, ...
        problem.p, problem.q, problem.lam, problem.density, problem.w_density, ...
        problem.sigma, problem_data(i,7));
    profile_logreg(problem, solver_options);
    % log results
    load(solver_options.dumpfile);
    data = rmfield(data,'A');
    out = struct('info', info, 'data', data, 'K', K, 'pars', pars, 'problem', problem);
    out.cost = info.solveTime/isempty(strfind(info.status, 'Inaccurate'));
    records = [records, out];
end
delete(solver_options.dumpfile);
fname = [get_scs_rootdir() 'tests/profiling_matlab/profile_results/' ...
    num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(solver_options, 'LOGREG-X', id, records);
