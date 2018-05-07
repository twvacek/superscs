function out = profile_pca(problem, solver_options)
%PROFILE_PCA solves the following regularized PCA problem
%
% Minimize_X -trace(S*X) + lam*||X||_1
% subject to
%  X: data-by-data symmetric
%  trace(X) = 1
%  X >= 0
%
%Syntax:
%out = profile_pca(problem, solver_options)
%
%Input arguments:
% problem           structure defining the problem specifications with
%                   fields:
%  data                row dimension of X
%  p                matrix S is defined as S = A'*A, where A is a p-by-d
%                   (sparse) matrix
%  density          is the density of the sparse matrix A
%  rcA              an approximation of the reciprocal condition number 
%                   of matrix A
%  
% solver_options    structure with solver options which are passed to
%                   scs_set_options.
%
%Output arguments:
% out               structure containing the total runtime (field name: time)
%
%See also:
% scs_set_options

data = problem.d; % 200
p = problem.p; % 5
A = sprandn(p, data, problem.density, problem.rcA);
S = full(A'*A);

lam = problem.lam;

tstart_pca = tic;
cvx_begin sdp quiet
    cvx_solver scs
    scs_set_options(solver_options);
    variable X(data,data) symmetric
    minimize(-trace(S*X) + lam*norm(X,1))
    trace(X)==1
    X>=0
cvx_end  
out.time = toc(tstart_pca);
