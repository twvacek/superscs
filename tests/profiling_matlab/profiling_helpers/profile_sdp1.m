function out = profile_sdp1(problem, e, o)

n=problem.n;
P = randn(n,n);

cvx_begin sdp
    cvx_solver scs
    set_pars(o, e);
    variable Z(n,n) hermitian toeplitz
    dual variable Q
    minimize( norm( Z - P, 'fro' ) )
    Z >= 0 : Q;
cvx_end

out = [];