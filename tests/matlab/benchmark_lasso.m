clear;
rng('default');
rng(1);

n = 1000; m = ceil(n/5); s=ceil(n/10);

x_true=[randn(s,1);zeros(n-s,1)]; % true sparse signal
x_true = x_true(randperm(n));

density = 0.2;
rcA = 1e-8;
A=sprandn(m,n,density,rcA);

b = A*x_true + 0.4*randn(m,1);
mu = 15;

scs_options = SuperSCSConfig.broydenConfig('tolerance', 1e-8,...
    'do_record_progress',1,'memory',100,'verbose',1);
tic;
cvx_begin
    cvx_solver scs
    scs_set_options(scs_options)
    variable x_c(n)
    minimize(0.5*sum_square(A*x_c - b) + mu*norm(x_c,1))
cvx_end
toc


load(scs_options.dumpfile)
semilogy(info.progress_time/1e3, info.progress_respri)
hold on