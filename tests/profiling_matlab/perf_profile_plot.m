% problem_group,
%
% 1. id               10. direction         19. scale
% 2. nrecords         11. do_super_scs      20. sigma
% 3. total_time       12. k0                21. sse
% 4. tol              13. k1                22. thetabar
% 5. alpha            14. k2                23. verbose
% 6. beta             15. ls                24. record_progress
% 7. c1               16. memory            25. use_indirect
% 8. c_bl             17. normalize         26. max_iters
% 9. cg_rate,         18. rho_x             27. warm_start

close all;
costdata = importdata('profile_results/register.csv');

problem_group = 'LASSO';
idx_scs      = costdata.data(strcmp(costdata.textdata(2:end,1),problem_group) ...
    & costdata.data(:,11)==0);
idx_superscs = costdata.data(strcmp(costdata.textdata(2:end,1),problem_group) ...
    & costdata.data(:,11)==1 ...
    & costdata.data(:,21)==0.999 ...
    & costdata.data(:,22)==0.1 ...
    & costdata.data(:,15)==10 ...
    & costdata.data(:,16)==50);

idx_scs = 712698682;
idx_superscs = [712698684 712698694];

load(['profile_results/' num2str(idx_scs) '.mat'])
c = [records.cost]';
for i=1:length(idx_superscs),
    load(['profile_results/' num2str(idx_superscs(i)) '.mat'])
    c = [c [records.cost]'];
end

[t, p] = perf_profile(c);
set(0,'DefaultAxesFontSize',12)
semilogx(t, p(:,1), 'linewidth', 3); hold on;
semilogx(t, p(:,2:end), 'linewidth', 2);
xlabel('performance ratio'); ylabel('Problems solved'); grid on
lgnd=cell(1+length(idx_superscs),1);
lgnd{1} = 'SCS';
for i=1:length(idx_superscs),
    lgnd{i+1} = ['SuperSCS, mem = ' num2str(costdata.data(costdata.data(:,1)==idx_superscs(i), 16))];
end
axis tight
legend(lgnd,'Location','SouthEast');

%%
datas = [records.data];
lens = [];
for i=1:length(datas),
    lens = [lens; length(datas(i).b)];
end
plot(lens, c(:,1)./c(:,2),'o')
xlabel('Problem size');
%%
probs = [records.problem];
mus = [];
for i=1:length(datas),
    mus = [mus; probs(i).mu];
end
semilogx(mus, c(:,1)./c(:,2),'o')
xlabel('LASSO parameter \mu')

%%
rcas = [];
for i=1:length(datas),
    rcas = [rcas; probs(i).rcA];
end
semilogx(rcas, c(:,1)./c(:,2),'o')
xlabel('Rec. Cond. Number');