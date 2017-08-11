function out = profile_lasso(problem, e, o)

d = problem.d; % 200
p = problem.p; % 5
A = sprandn(p, d, problem.density, problem.rcA);
S = full(A'*A);

lam = problem.lam;

cvx_begin sdp
    cvx_solver scs
    set_pars(o, e);
    variable X(d,d) symmetric
    minimize(-trace(S*X) + lam*norm(X,1))
    trace(X)==1
    X>=0
cvx_end  
out = [];