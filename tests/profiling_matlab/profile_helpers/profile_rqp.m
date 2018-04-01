function out = profile_rqp(problem, e, o)
%PROFILE_QP generates random problems as in the the OSQP paper by B.
%Stellato et al.

n = problem.n;
if isfield(problem, 'm')
    m = problem.m;
else
    m = 10*n;
end


M = sprandn(n, n, 0.5);
P = M*M';

A = sprandn(m, n, 0.5);
q = randn(n, 1);

u = rand(m,1);
l = -rand(m,1);

cvx_begin quiet
    cvx_solver scs
    set_pars(o, e);
    variable x(n)
    minimize( 0.5*x'*P*x + q'*x )
    subject to:
    l <= A*x <= u
cvx_end

out = [];