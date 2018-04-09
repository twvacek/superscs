function [data, K, details] = problem_from_yaml(destination)

out = parse_yaml(destination);
data.A = csc_to_sparse(out.A.m, out.A.a, out.A.I, out.A.J);
data.b = out.b;
data.c = out.c;

K = out.K;

details.name = out.name;