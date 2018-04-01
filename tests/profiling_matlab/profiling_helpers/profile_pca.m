function out = profile_pca(problem, solver_options)
%PROFILE_PCA solves the following regularized PCA problem
%
% Minimize_X -trace(S*X) + lam*||X||_1
% subject to
%  X: d-by-d symmetric
%  trace(X) = 1
%  X >= 0
%
%Syntax:
%out = profile_pca(problem, solver_options)
%
%Input arguments:
% problem           structure defining the problem specifications with
%                   fields:
%  d                row dimension of X
%  p                matrix S is defined as S = A'*A, where A is a p-by-d
%                   (sparse) matrix
%  density          is the density of the sparse matrix A
%  rcA              an approximation of the reciprocal condition number 
%                   of matrix A
%  
% solver_options    structure with solver options which are passed to
%                   set_pars.
%
%Output arguments:
% out               structure containing the total runtime (field name: time)
%
%See also:
% set_pars

d = problem.d; % 200
p = problem.p; % 5
A = sprandn(p, d, problem.density, problem.rcA);
S = full(A'*A);

lam = problem.lam;

tstart_pca = tic;
cvx_begin sdp quiet
    cvx_solver scs
    set_pars(solver_options);
    variable X(d,d) symmetric
    minimize(-trace(S*X) + lam*norm(X,1))
    trace(X)==1
    X>=0
cvx_end  
out.time = toc(tstart_pca);
