clc;

cg_rate = 1.2;
aa_memories = [3,5,10];
bro_memories = [50, 100];


mm_runner = MarosMeszarosRunner();
mm_runner.set_max_filesize_MB(1.5);
mm_runner.set_verbose(true);
mm_runner.add_config(SuperSCSConfig.scsConfig('cg_rate',cg_rate));
for aa_mem = aa_memories
    mm_runner.add_config(SuperSCSConfig.andersonConfig('memory', aa_mem,'cg_rate',cg_rate));
end
for bro_mem = bro_memories
    mm_runner.add_config(SuperSCSConfig.broydenConfig('memory', bro_mem,'cg_rate',cg_rate));
end
mm_runner.run();

save MM_RUNNER_NEW.mat mm_runner
%%

fid = fopen('a.txt', 'w');
mm_runner.stream_fid = fid;
mm_runner.print_html(' * ');
fclose(fid);


%% PLOT performance plot
c = [];
for i=1:6
s = (cellfun(@(s)isempty(strfind(s,'Inaccurate')), {mm_runner.info_cache(:,i).status})');
dc = [mm_runner.info_cache(:,i).solveTime]'./s;
c = [c dc];
end

[t, p] = perf_profile(c);

close
set(0,'DefaultAxesFontSize',12)
semilogx(t, p(:,1), 'linewidth', 3); hold on;
semilogx(t, p(:,2:6), 'linewidth', 2);

xlabel('performance ratio'); ylabel('Problems solved'); grid on
axis tight
ylim([0,1])