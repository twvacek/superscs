function out = profile_normcon(problem, e, o)

A = sprandn(problem.m, problem.n, problem.density, problem.rca);
b = problem.bmag*randn(problem.m, 1);
G = problem.Gmag*sprandn(problem.p, problem.n, problem.density_c);

tic;
cvx_begin
    cvx_solver scs
    set_pars(o, e)
    variable x(problem.n)
    minimize( norm(A*x-b) )
    subject to
        norm(G*x) <= 1
cvx_end
toc

out = [];
