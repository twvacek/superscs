%SPARSE_TO_CSC converts a given sparse matrix into its CSC representation.
%
%Syntax:
%[m, n, nnz, a, ir, jc] = SPARSE_TO_CSC(A);
%
%Input arguments:
% A     a sparse matrix
%
%Ouput arguments:
% m     number of rows of A
% n     number of columns of A
% nnz   number of nonzero elements in A
% a     data of A
% ir    cumulative number of nonzero elements in each column (ir(1) = 0)
% jc    array of the row-coordinates of the nonzero elements of A

%Built-in function
%Part of SuperSCS