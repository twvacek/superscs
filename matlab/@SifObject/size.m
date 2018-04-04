function [nvar, neq, nineq, nlineq, nuineq, nfix] = size(obj)
%SIZE returns the sizes of a SifObject object
%
%Syntax:
%[nvar, neq, nineq, nlineq, nuineq, nfix] = sif_object.size();
%
%Output arguments:
%  nvar     number of decision variables
%  neq      number of equality constraints
%  nineq    number of inequality constraints
%  nlineq   number of lower inequality constraints
%  nuineq   number of upper inequality constraints
%  nfix     number of fixed variables
%

nvar = obj.n_vars;
neq =  obj.n_equality_rows;
nineq = obj.n_constraints;
nlineq = obj.n_l_inequality_rows;
nuineq = obj.n_g_inequality_rows;
nfix = size(obj.c_fix, 1);
end