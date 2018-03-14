function out = profile_qp(problem, e, o)

n = problem.n;
m = problem.m;
rho = problem.rho;
Q0 = diag(logspace(problem.Q_log_eig_min, problem.Q_log_eig_max, n));
U = orth(randn(n,n));
Q = U'*Q0*U + rho*eye(n);
q = 5 * randn(n,1);
r = randn;
F = rand(m,n);
f = rand(m,1);

l = randn(n,1);
u = l + rand(n,1);

lb = min(l,u) - 0.5;
ub = max(l,u) + 0.5;

cvx_begin
    cvx_solver scs
    set_pars(o, e);
    variable x(n)
        minimize( 0.5*x'*Q*x + q'*x + r )
        subject to:
            lb <= x <= ub
            F*x == f
cvx_end

out = [];