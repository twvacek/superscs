function out = profile_qp(problem, e, o)

n = problem.n;
rho = problem.rho;
Q0 = diag(logspace(problem.Q_log_eig_min, problem.Q_log_eig_max, n));
U = orth(randn(n,n));
Q = U*Q0*U' + rho*eye(n);
q = randn(n,1);
r = randn;

l = randn(n,1);
u = randn(n,1);
lb = min(l,u);
ub = max(l,u);
cvx_begin
    cvx_solver scs
    set_pars(o, e);
    variable x(n)
    minimize( 0.5*x'*Q*x + q'*x + r )
    subject to:
      lb <= x <= ub      
cvx_end

out = [];