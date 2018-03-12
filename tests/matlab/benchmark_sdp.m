%% SDP #1: Minimum trace 
clear;
rng('default');
rng(1);

n=300;
P = randn(n,n);
cvx_begin sdp
cvx_solver scs
cvx_solver_settings('eps', 1e-6,...
        'scale', 1,...
        'do_super_scs',1,...
        'direction', 150,...
        'k0', 0,...
        'memory', 10,...
        'rho_x', 0.0001,...
        'verbose', 2, ...
        'use_indirect', 0)
    variable Z(n,n) hermitian toeplitz
    dual variable Q
    minimize( norm( Z - P, 'fro' ) )
    Z >= 0 : Q;
cvx_end



%% SDP #2: Lyapunov matrix
clear;
rng('default');
rng(1);

n=100;
A = diag(-logspace(-0.5, 1, n));
U = orth(randn(n,n));
A = U'*A*U;
tic
cvx_begin sdp
    cvx_solver scs
    cvx_solver_settings('eps', 1e-3,...
        'verbose', 1,...
        'do_super_scs', 1, ...
        'rho_x', .0001,  ...
        'k0', 0, ...
        'direction', 150, ...
        'memory', 20);
    variable P(n,n) symmetric
    minimize(trace(P))
    A'*P + P*A <= -eye(n)
    P >= eye(n)
cvx_end    
toc    
 