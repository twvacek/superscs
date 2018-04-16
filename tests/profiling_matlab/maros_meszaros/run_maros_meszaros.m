clc;

cg_rate = 1.2;
aa_memories = [3,5,10];
bro_memories = [50, 100];
tol = 1e-4;
max_time_milliseconds = 2.5*60*1e3;
max_iters = 1e6;

mm_runner = MarosMeszarosRunner();
mm_runner.set_max_filesize_MB(1.5);
mm_runner.set_verbose(true);
mm_runner.add_config(SuperSCSConfig.scsConfig('cg_rate',cg_rate, 'tolerance', ...
    tol, 'max_time_milliseconds', max_time_milliseconds, 'max_iters', max_iters));
mm_runner.add_config(SuperSCSConfig.douglasRachfordConfig('cg_rate',cg_rate, ...
    'tolerance', tol, 'max_time_milliseconds', max_time_milliseconds, ...
    'max_iters', max_iters));
for aa_mem = aa_memories
    mm_runner.add_config(SuperSCSConfig.andersonConfig('memory', aa_mem, ...
        'cg_rate',cg_rate, 'tolerance', tol, ...
        'max_time_milliseconds', max_time_milliseconds, ...
        'max_iters', max_iters));
end
for bro_mem = bro_memories
    mm_runner.add_config(SuperSCSConfig.broydenConfig('memory', bro_mem,...
        'cg_rate',cg_rate, 'tolerance', tol,...
        'max_time_milliseconds', max_time_milliseconds, ...
        'max_iters', max_iters));
end
mm_runner.run();

save MM_RUNNER_NEW_ACCURATE_MAXTIME.mat mm_runner
%%
clc
fid = 1;
mm_runner.stream_fid = fid;
mm_runner.print_txt()

%%
fid = fopen('a.html', 'w');
mm_runner.stream_fid = fid;
mm_runner.print_html(' * ');
fclose(fid);


%% PLOT performance plot
c = [];
for i=1:size(mm_runner.info_cache, 2)
    s = (cellfun(@(s)isempty(strfind(s,'Inaccurate')), {mm_runner.info_cache(:,i).status})');
    dc = [mm_runner.info_cache(:,i).iter]'./s;
    c = [c dc];
end

[t, p] = perf_profile(c);

figure;
%close
set(0,'DefaultAxesFontSize',12)
semilogx(t, p(:,5), 'linewidth', 2); hold on;
semilogx(t, p(:,7), 'linewidth', 2);

xlabel('performance ratio'); ylabel('Problems solved'); grid on
axis tight
ylim([0,1])