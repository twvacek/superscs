function out = profile_sdp2(problem, solver_options)
%PROFILE_SDP2 solves the problem
%
% Minimize_P trace(P)
% subject to
%  P: symmetric
%  P >= I
%  A'*P + P*A <= -I
%
%Syntax:
%out = profile_sdp2(problem, solver_options)
%
%Input arguments:
% problem           structure defining the problem specifications with
%                   fields:
%  n                row dimension of P
%  log_eig_min      logarithm of the minimum eigenvalue of A
%  log_eig_max      logarithm of the maximum eigenvalue of A
%
% solver_options    structure with solver options which are passed to
%                   set_pars.
%
%Output arguments:
% out               structure containing the total runtime (field name: time)
%
%See also:
% set_pars

n=problem.n;
A = diag(-logspace(problem.log_eig_min, problem.log_eig_max, n));
U = orth(randn(n,n));
A = U'*A*U;

tstart_sdp2 = tic;
cvx_begin sdp quiet
    cvx_solver scs
    set_pars(solver_options);
    variable P(n,n) symmetric
    minimize(trace(P))
    A'*P + P*A <= -eye(n)
    P >= eye(n)
cvx_end    
    
out.time = toc(tstart_sdp2);
