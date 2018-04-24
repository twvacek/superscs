density = 0.4;
p = 100;   % features
q = 10*p;   % total samples
w_true = sprandn(p,1,0.2);
X_tmp = 3*sprandn(p, q, density);
ips = -w_true'*X_tmp;
ps = (exp(ips)./(1 + exp(ips)))';
labels = 2*(rand(q,1) < ps) - 1;
X_pos = X_tmp(:,labels==1);
X_neg = X_tmp(:,labels==-1);
X = [X_pos -X_neg]; % include labels with data
lam = .1; 


scs_options = SuperSCSConfig.douglasRachfordConfig('tolerance', 1e-4,...
    'do_record_progress',1,'memory',100,'verbose',2);


cvx_begin
   cvx_solver scs
   set_pars(scs_options);
   variable w(p)
   minimize(sum(log_sum_exp([sparse(1,q);w'*X])) + lam * norm(w,1))       
cvx_end



load(scs_options.dumpfile)
semilogy(info.progress_time/1e3, info.progress_respri)
hold on