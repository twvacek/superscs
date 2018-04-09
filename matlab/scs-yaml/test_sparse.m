filename = 'example.yml';
data.A = sparse([0.3 0 0 ; 0 0.7 0; 0 0 0.2; -0.5 0.9 0]);  % define A
data.b = [0.2; 0.1; -0.1; 0.1];                             % define b
data.c = [1;-2;-3];                                         % define c
K.eq = 0; K.ep = 0; K.q = 4;                                % define K
problem_to_yaml(filename, 'test-problem-1', data, K);       % save data
[data_loaded, K_loaded] = problem_from_yaml(filename);      % load data