function out = qp_wrapper_solver(P, q, r, A, l, u, solver_options)
n = size(P,1);
cvx_begin quiet
    cvx_solver scs
    set_pars(solver_options)
    variable x(n)
    minimize( 0.5*x'*P*x + q'*x + r );
    subject to
        l <= A*x <= u
cvx_end

out.x = x;