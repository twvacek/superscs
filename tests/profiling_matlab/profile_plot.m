%function [t, p] = profile_plot(c)
% c     : np-by-ns
% cmin  : np
% R     : np-by-ns
%

costdata = importdata('profile_results/register.csv');
findprob = find(strcmp(costdata.textdata(2:end,1),'LASSO'));

idx_scs      = costdata.data(costdata.data(findprob,11)==0);
idx_superscs = costdata.data(costdata.data(findprob,11)==1);


load(['profile_results/' num2str(idx_scs) '.mat'])
c = [records.cost]';
for i=1:length(idx_superscs),
    load(['profile_results/' num2str(idx_superscs(i)) '.mat'])
    c = [c [records.cost]'];
end

[np, ns] = size(c);

% cmin: minimum cost per problem (np-by-1)
cmin = min(c,[],2);
R    = c./kron(ones(1,ns),cmin);

t = sort(unique(R));
nt = length(t);
p = zeros(nt, ns);

for i =1:nt,
    tau = t(i);
    p(i,:) = sum(R<=t(i))/np;
end
set(0,'DefaultAxesFontSize',12)
semilogx(t, p, 'linewidth', 2);  xlabel('performance ratio'); ylabel('Problems solved'); grid on
legend('SCS', 'SuperSCS mem=50', 'SuperSCS mem=100', 'SuperSCS mem=10');