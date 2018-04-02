function profile_runner_normcon(solver_options, id, runner_options)
%PROFILE_RUNNER_NORMCON runs a collection of norm-constrained norm
%minimization problems by calling profile_normcon
%
%Syntax:
%profile_runner_normcon(solver_options, id)
%profile_runner_normcon(solver_options, id, runner_options)
%
%Input arguments:
% id        experiment id (at the end of the experiment, the results are
%           stored in a MAT file in tests/profiling_matlab/profile_results
%           and are also registered in the file register.csv in that same
%           folder).
% solver_options a structure with solver options which is passed to
%                profile_lasso
% runner_options this is a structure with the experiment options; it is a
%                structure with the following fields:
%  reps          repetitions of each run (on random data) [default: 2]
%  span_m        the range of m values to be tested [default: [500 1000 3000]]
%  span_n_factor dimension `n` is computed as n = n_factor * m. [default:
%                [0.1 0.5]]
%  span_p        the range of `p` (the row dimension of matrix `G`).
%                [default: [10 100]]
%  span_rca      the range of (approximate) reciprocal condition numbers of
%                `A` [default: logspace(-5, -1, 4)]
%  span_bmag     the range of magnitudes of `b` (see profile_normcon)
%  span_Gmag     the range of magnitudes of `G` (see profile_normcon)
%  span_density  the range of densities of sparse matrix `A` [default: 
%                [0.05 0.1]]
%  span_density_c the range of densities of sparse matrix `G` [default: 0.5]
%
%
% The argument `runner_options` is optional.
%
%See also
%profile_normcon


rng(1); % for reproducibility (so that every time this function is called,
% the same problems will be run).
records = []; info = []; data = []; K = []; pars = []; problem = [];

reps = 2;
span_m         = [500 1000 3000];
span_n_factor  = [0.1 0.5];                 % n = n_factor * m
span_p         = [10 100];
span_rca       = logspace(-5, -1, 4);
span_bmag      = 10;
span_Gmag      = [10 50];
span_density   = [0.05 0.1];
span_density_c = 0.5;

if nargin >=3
    if isfield(runner_options, 'reps'), 
        reps = runner_options.reps; 
    end
    if isfield(runner_options, 'span_m'), 
        span_m = runner_options.span_m; 
    end
    if isfield(runner_options, 'span_n_factor'),
        span_n_factor = runner_options.span_n_factor;
    end
    if isfield(runner_options, 'span_p'),
        span_p = runner_options.span_p;
    end
    if isfield(runner_options, 'span_rca'),
        span_rca = runner_options.span_rca;
    end
    if isfield(runner_options, 'span_bmag'),
        span_bmag = runner_options.span_bmag;
    end
    if isfield(runner_options, 'span_Gmag'),
        span_Gmag = runner_options.span_Gmag;
    end
    if isfield(runner_options, 'span_density'),
        span_density = runner_options.span_density;
    end
    if isfield(runner_options, 'span_density_c'),
        span_density_c = runner_options.span_density_c;
    end
end

problem_data = cartesian(span_m, span_n_factor, span_p, span_rca, ...
    span_bmag, span_Gmag, span_density, span_density_c, 1:reps);
n_problems = size(problem_data, 1);

for i=1:n_problems,
    problem.m         = problem_data(i,1);
    problem.n         = round(problem_data(i,2) * problem.m);
    problem.p         = problem_data(i,3);
    problem.rca       = problem_data(i,4);
    problem.bmag      = problem_data(i,5);
    problem.Gmag      = problem_data(i,6);
    problem.density   = problem_data(i,7);
    problem.density_c = problem_data(i,8);
    r                 = problem_data(i,9);
    
    fprintf(['NORMCON %3d/%3d ', ...
        '[m=%4d, n=%4d, p=%3d, rca=%1.5f, bmag=%1.2f, Gmag=%2.1f, ', ...
        'A-density=%1.2f, G-density=%1.2f, rep=%1d]\n'], ...
        i, n_problems, problem.m, problem.n, problem.p,...
        problem.rca, problem.bmag, problem.Gmag, problem.density, ...
        problem.density_c, r);
    profile_normcon(problem, solver_options);
    
    % log results
    load(solver_options.dumpfile);
    data = rmfield(data,'A');
    out = struct('info', info, 'data', data, 'K', K, 'pars', pars, ...
        'problem', problem);
    out.cost = info.solveTime/isempty(strfind(info.status, 'Inaccurate'));
    records = [records, out];
end


delete(solver_options.dumpfile);
fname = [get_scs_rootdir() 'tests/profiling_matlab/profile_results/' ...
    num2str(id) '.mat'];
save(fname, 'records') % save `records` to file {id}.mat
register_profile_data(solver_options, 'NORMCON', id, records);