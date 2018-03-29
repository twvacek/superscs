function out = profile_sdp1(problem, solver_options)

n=problem.n;
P = randn(n,n);

cvx_begin sdp quiet
    cvx_solver scs
    set_pars(solver_options);
    variable Z(n,n) hermitian toeplitz
    dual variable Q
    minimize( norm( Z - P, 'fro' ) )
    Z >= 0 : Q;
cvx_end

out = [];