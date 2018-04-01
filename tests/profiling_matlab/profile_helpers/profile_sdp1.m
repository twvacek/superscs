function out = profile_sdp1(problem, solver_options)
%PROFILE_SDP1 solves the problem
%
% Minimize_Z ||Z-P||_fro
% subject to
%  Z: hermitian, toeplitz
%  Z >= 0
%
%Syntax:
%out = profile_sdp1(problem, solver_options)
%
%Input arguments:
% problem           structure defining the problem specifications with
%                   fields:
%  n                row dimension of Z
%
% solver_options    structure with solver options which are passed to
%                   set_pars.
%
%Output arguments:
% out               structure containing the total runtime (field name: time)
%              
%See also
% set_pars

n=problem.n;
P = randn(n,n);

tstart_sdp1 = tic;
cvx_begin sdp quiet
    cvx_solver scs
    set_pars(solver_options);
    variable Z(n,n) hermitian toeplitz
    dual variable Q
    minimize( norm( Z - P, 'fro' ) )
    Z >= 0 : Q;
cvx_end

out.time = toc(tstart_sdp1);
