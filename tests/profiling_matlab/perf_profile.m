function [t, p] = perf_profile(c)
% c     : np-by-ns
% cmin  : np
% R     : np-by-ns
%

[np, ns] = size(c);

% cmin: minimum cost per problem (np-by-1)
cmin = min(c,[],2);
R    = c./kron(ones(1,ns),cmin);

t = sort(unique(R));
nt = length(t);
p = zeros(nt, ns);

for i =1:nt,
    p(i,:) = sum(R<=t(i))/np;
end
