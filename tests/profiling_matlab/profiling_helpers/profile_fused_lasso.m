function out = profile_fused_lasso(problem, solver_options)

m = problem.m;
ni = problem.ni;
k = problem.k;
rho=problem.rho;
sigma=problem.sigma;

A = randn(m, ni*k);
A = A / norm(A);

x0 = zeros(ni*k,1);
for i=1:k
    if rand < rho,
        x0(i*ni:(i+1)*ni) = rand;
    end
end
b = A*x0 + sigma*randn(m,1);
lam = 0.1*sigma*sqrt(m*log(ni*k));

I = speye(ni*k);
T1 = I(1:end-1,:);
T2 = I(2:end,:);
cvx_begin quiet
    cvx_solver scs
    set_pars(solver_options);
    variable x(ni*k)
    minimize( sum_square(A*x - b) + lam*norm(x,1) + lam*norm(T1*x-T2*x, 1) ); 
cvx_end
out = [];