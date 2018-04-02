function out = profile_normcon(problem, solver_options)
%PROFILE_NORMCON solves the following norm-constrained problem
%
% Minimize ||A*x - b||
% subject to
%  ||G*x|| <= 1
%
%where `A` is an m-by-n sparse matrix with given density and reciprocal
%condition number, `b` is an m-vector and `G` is a p-by-n sparse matrix
%with given density
%
%Syntax:
%out = profile_normcon(problem, solver_options)
%
%Input arguments:
% problem           structure defining the problem specifications with
%                   fields:
%  m, n             row and column dimensions of `A`
%  p                row dimension of `G`
%  density          density of the sparse matrix `A`
%  rca              approximate reciprocal condition number of A
%  density_c        density of the sparse matrix `G`
%  bmag             magnitude of vector `b` which is constructed by
%                   b = problem.bmag*randn(problem.m, 1);
%  Gmag             magnitude of matrix `G` which is constructed by
%                   G = problem.Gmag*sprandn(problem.p, problem.n, ...
%                   problem.density_c);
%
% solver_options    structure with solver options which are passed to
%                   set_pars.
%
%Output arguments:
% out               structure containing the total runtime (field name: time)
%              
%See also
% set_pars
 
A = sprandn(problem.m, problem.n, problem.density, problem.rca);
b = problem.bmag*randn(problem.m, 1);
G = problem.Gmag*sprand(problem.p, problem.n, problem.density_c);

tstart_normcon = tic;
cvx_begin quiet
    cvx_solver scs
    set_pars(solver_options)
    variable x(problem.n)
    minimize( norm(A*x-b) )
    subject to
        norm(G*x) <= 1
cvx_end
out.time = toc(tstart_normcon);
