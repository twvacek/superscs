rng('default');
rng(1);

m = 500;
n = 200;
percentage_missing = 0.9;
n_nan = ceil(percentage_missing*m*n);
M = 100*randn(m, n);
idx = randperm(m*n);
idx_nan = idx(1:n_nan);
idx_not_nan = idx(n_nan+1:end);
M(idx_nan) = nan;
lam = 1e-3;

scs_options = SuperSCSConfig.andersonConfig('tolerance', 1e-4,...
    'do_record_progress',1,'verbose',1,'memory',5);

cvx_begin sdp
    cvx_solver scs
    set_pars(scs_options)
    variable X(m,n)
    minimize (lam * norm_nuc(X) + sum_square(X(idx_not_nan)-M(idx_not_nan)))
    subject to
        X(idx_not_nan)==M(idx_not_nan)
cvx_end


load(scs_options.dumpfile)
semilogy(info.progress_time/1e3, info.progress_respri)
hold on