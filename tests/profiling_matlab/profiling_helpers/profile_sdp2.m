function out = profile_sdp2(problem, e, o)

n=problem.n;
A = diag(-logspace(problem.log_eig_min, problem.log_eig_max, n));
U = orth(randn(n,n));
A = U'*A*U;

cvx_begin sdp
    cvx_solver scs
    set_pars(o, e);
    variable P(n,n) symmetric
    minimize(trace(P))
    A'*P + P*A <= -eye(n)
    P >= eye(n)
cvx_end    
    
out = [];