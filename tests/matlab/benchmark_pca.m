%{ 
clear;
rng('default');
rng(1);

d = 200;
p = 5;
A = sprandn(p,d,0.3,0.0001);
S = full(A'*A);

lam = 10;

cvx_begin sdp
    cvx_solver scs
    cvx_solver_settings('eps', 1e-3,...
        'verbose', 1,...
        'do_super_scs', 1, ...
        'direction', 100, ...
        'memory', 100,...
        'do_record_progress',1,...
        'dumpfile','pca.mat');
    variable X(d,d) symmetric
    minimize(-trace(S*X) + lam*norm(X,1))
    trace(X)==1
    X>=0
cvx_end  
%%
load('pca.mat')
semilogy(info.progress_time, info.progress_respri,'linewidth',2); hold on
semilogy(info.progress_time, info.progress_resdual,'linewidth',2);
legend('Primal Residual', 'Dual Residual');
xlabel('time [ms]'); ylabel('residual');
grid on

%}
%%
% NICE BENCHMARK
% Find X, low rank matrix, so that X is close to Y

n = 10;
r = 2;
lam = 5;
E = randn(n,r);
Y = E*E';


cvx_begin sdp
    cvx_solver scs
    cvx_solver_settings('eps', 1e-5,...
        'verbose', 1,...
        'do_super_scs', 1, ...
        'memory', 100);
    variable X(n,n) symmetric
    minimize(norm(X-Y,'fro'))
    subject to
    norm_nuc(X) <= 1
cvx_end  

plot(svd(X))