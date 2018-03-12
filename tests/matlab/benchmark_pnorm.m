rng('default');
rng(1);

n = 2000;
m = ceil(n/4);
density = 0.3;
G = sprandn(m,n,density);
f = randn(m,1) * n * density;
pow = 4;
tic
cvx_begin
    cvx_solver scs
    cvx_solver_settings('eps', 1e-4,...
        'verbose', 2,...
        'do_super_scs', 1, ...
        'rho_x', .0001,  ...
        'k0', 0, ...
        'direction', 150, ...
        'memory', 20,...
        'use_indirect', 1);
    variable x(n)
    minimize(norm(x, pow))
    subject to
      G*x == f
    cvx_end
toc
