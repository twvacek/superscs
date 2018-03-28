function out = profile_lasso(problem, solver_options)

n = problem.n; m = problem.m; s = problem.s; density = problem.density;
mu = problem.mu;

x_true=[randn(s,1);zeros(n-s,1)]; % true sparse signal
x_true = x_true(randperm(n));

rcA = problem.rcA;
A=sprandn(m,n,density,rcA);

b = A*x_true + 0.1*randn(m,1);

tic;
cvx_begin
    cvx_solver scs
    set_pars(solver_options)
    variable x_c(n)
    minimize(0.5*sum_square(A*x_c - b) + mu*norm(x_c,1))
cvx_end
out.time = toc;