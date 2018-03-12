rng('default');
rng(1);
m=100;
n=100;
n_nan = ceil(0.8*m*n);
M = sprandn(m, n, 0.4);
idx = randperm(m*n);
M(idx(1:n_nan))=nan;
lam = 0.5;
tic
cvx_begin sdp
    cvx_solver scs
    cvx_solver_settings('eps', 1e-3,...
        'do_super_scs', 1,...
        'direction', 150,...
        'memory', 4,...
        'rho_x', 0.0001, 'verbose', 1)
    variable X(m,n)
    minimize (norm_nuc(X)  + lam*sum_square(X(:)))
    subject to
    for i=1:m
        for j=1:n
            if (~isnan(M(i,j)))
                X(i,j)==M(i,j)
            end
        end
    end
cvx_end
toc
