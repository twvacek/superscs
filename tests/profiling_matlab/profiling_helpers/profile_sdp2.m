function out = profile_sdp2(problem, solver_options)

n=problem.n;
A = diag(-logspace(problem.log_eig_min, problem.log_eig_max, n));
U = orth(randn(n,n));
A = U'*A*U;

cvx_begin sdp quiet
    cvx_solver scs
    set_pars(solver_options);
    variable P(n,n) symmetric
    minimize(trace(P))
    A'*P + P*A <= -eye(n)
    P >= eye(n)
cvx_end    
    
out = [];