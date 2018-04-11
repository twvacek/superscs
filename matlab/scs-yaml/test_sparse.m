clear;
problem_name = 'example-problem-1';
filename = fullfile(get_scs_rootdir, 'matlab', 'scs-yaml', 'example.yml');
ops = struct('creator', 'SuperSCS v1.2.6');
data.A = sparse([0.3 0 0 ; 0 0.7 0; 0 0 0.2; -0.5 0.9 0]);  % define A
data.b = [0.2; 0.1; -0.1; 0.1];                             % define b
data.c = [1;-2;-3];                                         % define c
K.q = 4;                                                    % define K
problem_to_yaml(filename, problem_name, data, K, ops);      % save data
[data_loaded, K_loaded, dtl] = problem_from_yaml(filename); % load data

% Check that everything is OK
assert(norm(data_loaded.A-data.A, Inf) <= 1e-12);
assert(norm(data_loaded.b-data.b, Inf) <= 1e-12);
assert(norm(data_loaded.c-data.c, Inf) <= 1e-12);
assert(K.q == K_loaded.q);
assert(K_loaded.f == 0);
assert(K_loaded.l == 0);
assert(K_loaded.ep == 0);
assert(K_loaded.ed == 0);
assert(K_loaded.psize == 0);
assert(K_loaded.qsize == 1);
assert(K_loaded.ssize == 0);
assert(isempty(K_loaded.s));
assert(isempty(K_loaded.p));
assert(strcmp(problem_name, dtl.name));


%% Another test
data.A = sparse([0.1   0     0.2    0     0;
    0    -0.5   0      0     0.1;
    0     0     0.2    0.4  -0.1;
    -0.3   0     0.8    0.9  -0.2;
    0   0.1     0     -0.9  -0.2;
    1   0       1      0     0]);
data.b = [1;0.8;-1;2;1;1];
data.c = [0.1;0.1;0.2;0.1;0.6];

K.q = [2 2];
K.l = 1;
K.f = 1;

filename = fullfile(get_scs_rootdir, 'matlab', 'scs-yaml', 'example-2.yml');
problem_name = 'example-problem-2';

problem_to_yaml(filename, problem_name, data, K, ops);
[data_loaded, K_loaded, dtl] = problem_from_yaml(filename);
solver_options = struct('eps', 1e-6, 'do_super_scs', 1, 'direction', 150, 'memory', 5, 'k0',0);
[x, y, s, info] = scs_direct(data, K, solver_options)

%% Create random problem and store it in YAML

filename3 = fullfile(get_scs_rootdir, 'tests', 'c', 'data', 'test-3.yml');
[data, K, details] = problem_from_yaml(filename3);
