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
