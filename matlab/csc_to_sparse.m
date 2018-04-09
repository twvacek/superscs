%CSC_TO_SPARSE converts the CSC data of a sparse matrix to a standard
%MATLAB sparse matrix.
%
%Syntax:
%S = sparse_to_csc(num_rows, a, I, J)
%
%Input arguments:
% num_rows   the number of rows of the sparse matrix
% a          the matrix data
% I          cumulative number of nonzero elements in each column (ir(1) = 0)
% J          array of the row-coordinates of the nonzero elements of A
%
%Output arguments:
% S          corresponding sparse matrix
%
%See also
%sparse_to_csc