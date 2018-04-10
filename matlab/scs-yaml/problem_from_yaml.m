function [data, cones, details] = problem_from_yaml(yaml_filepath)
%PROBLEM_FROM_YAML constructs a SuperSCS problem from a YAML file
%
%Syntax:
%[data, K, details] = problem_from_yaml(yaml_filepath)
% 
%
%Input arguments:
%  yaml_filepath    path to YAML file
%
%Ouput arguments:
%  data             a structure with fields: `A`, `b` and `c`; the data of
%                   a conic optimization problem
%  cones            the cone specifications of the conic problem
%  details          other details of the problem such as the parsing time
%                   and the name of the problem
%
%See also
%problem_to_yaml, sparse_to_csc, csc_to_sparse

%% Code
start_yaml_parsing = tic;
out = parse_yaml(yaml_filepath);
data.A = csc_to_sparse(out.A.m, out.A.a, out.A.I, out.A.J);
data.b = out.b;
data.c = out.c;
cones = out.K;

details.name = out.name;
details.parsing_time = toc(start_yaml_parsing);