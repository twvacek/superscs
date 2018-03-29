function out = profile_logreg(problem, e, o)

density = problem.density; % [0.1]
lam     = problem.lam; 
p       = problem.p; % features
q       = problem.q; % total samples
w_true  = sprandn(p, 1, 0.2);

X_tmp  = 3 * sprandn(p, q, density);
ips    = -w_true'*X_tmp;
ps     = (exp(ips)./(1 + exp(ips)))';
labels = 2*(rand(q,1) < ps) - 1;

X_pos = X_tmp(:,labels==1);
X_neg = X_tmp(:,labels==-1);

X = [X_pos -X_neg]; % include labels with data


cvx_begin quiet
    cvx_solver scs
    set_pars(o, e);
    variable w(p)
    minimize(sum(log_sum_exp([sparse(1,q);w'*X])) + lam * norm(w,1))        
cvx_end

out = [];