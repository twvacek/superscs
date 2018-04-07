%SPARSE_TO_CSC converts a given sparse matrix into its CSC representation.
%
%Syntax:
%[m, n, nnz, a, jc, ir] = SPARSE_TO_CSC(A);
%
%Input arguments:
% A     a sparse matrix
%
%Ouput arguments:
% m     number of rows of A
% n     number of columns of A
% nnz   number of nonzero elements in A
% a     data of A
% jc    array of the row-coordinates of the nonzero elements of A
% ir    cumulative number of nonzero elements in each column (ir(1) = 0)

%Built-in function
%Part of SuperSCS