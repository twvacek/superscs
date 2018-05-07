function out = profile_logreg(problem, solver_options)
%PROFILE_LOGREG solves the following logistic regression problem
%
%Minimize_w lambda * ||w||_1 + SUM_i log(1 + exp(a'*w_i + b)),
% 
%The corresponding true value of `w` is a sparse random vector with density
%`w_density`.
%
%Syntax:
%out = profile_logreg(problem, solver_options)
%
%Input arguments:
% problem           structure defining the problem specifications with
%                   fields:
%  density          density of matrix X_t
%  p, q             row and column dimensions of X_t
%  lam              lambda parameter of the problem
%  w_density        density of the true vector `w_true`
%  sigma            parameter sigma (X_t  = sigma*sprandn(p, q, density))
%
% solver_options    structure with solver options which are passed to
%                   scs_set_options.
%
%Output arguments:
% out               structure containing the total runtime (field name: time)
%
%See also:
% scs_set_options

density   = problem.density;     % default: 0.1
w_density = problem.w_density;   % default: 0.2
lam       = problem.lam;         % lambda parameter
p         = problem.p;           % features
q         = problem.q;           % total samples
sigma     = problem.sigma;       % sigma

w_true  = sprandn(p, 1, w_density);
X_tmp  = sigma * sprandn(p, q, density);
ips    = -w_true'*X_tmp;
ps     = (exp(ips)./(1 + exp(ips)))';
labels = 2*(rand(q,1) < ps) - 1;

X_pos = X_tmp(:,labels==1);
X_neg = X_tmp(:,labels==-1);

X = [X_pos -X_neg]; % include labels with data

tstart_logreg = tic;
cvx_begin quiet
    cvx_expert true
    cvx_solver scs
    scs_set_options(solver_options);
    variable w(p)
    minimize(sum(log_sum_exp([sparse(1,q);w'*X])) + lam * norm(w,1))        
cvx_end

out.time = toc(tstart_logreg);
