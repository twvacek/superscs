%% Benchmark parameters

clc;
clear;
cg_rate      = 1.2;                     % CG tolerance rate
aa_memories  = [3, 5, 10];              % AA memories to be tested
bro_memories = [50, 100];               % Broyden memories to be tested
tol          = 1e-4;                    % tolerance
max_iters    = 1e6;                     % maximum number of iterations
max_time_milliseconds = 2.5*60*1e3;     % maximum allowed runtime (2.5 minutes)

%% Execute the benchmarks

mm_runner = MarosMeszarosRunner();
mm_runner.set_max_filesize_MB(1.5);
mm_runner.set_verbose(true);

% Run original SCS
mm_runner.add_config(SuperSCSConfig.scsConfig(...
    'cg_rate',cg_rate, ...
    'tolerance', tol, ...
    'max_time_milliseconds', max_time_milliseconds, ...
    'max_iters', max_iters));

% Run DR
mm_runner.add_config(SuperSCSConfig.douglasRachfordConfig(...
    'cg_rate', cg_rate, ...
    'tolerance', tol, ...
    'max_time_milliseconds', max_time_milliseconds, ...
    'max_iters', max_iters));

% Run SuperSCS with Anderson's acceleration and various different memory
% values
for aa_mem = aa_memories
    mm_runner.add_config(SuperSCSConfig.andersonConfig(...
        'memory', aa_mem, ...
        'cg_rate',cg_rate, ...
        'tolerance', tol, ...
        'max_time_milliseconds', max_time_milliseconds, ...
        'max_iters', max_iters));
end

% Run SuperSCS with restarted limited-memory Broyden directions and
% different memory lengths
for bro_mem = bro_memories
    mm_runner.add_config(SuperSCSConfig.broydenConfig(...
        'memory', bro_mem,...
        'cg_rate', cg_rate, ...
        'tolerance', tol,...
        'max_time_milliseconds', max_time_milliseconds, ...
        'max_iters', max_iters));
end

% Execute benchmarks
mm_runner.run();

% Save the results
save MM_RUNNER_NEW_ACCURATE_MAXTIME_B.mat mm_runner
%% Results in text format
clc
mm_runner.stream_fid = 1;
mm_runner.print_txt();

%% Results in annotated HTML format

mm_runner.stream_fid = fopen('a.html', 'w');
mm_runner.print_html(' * ');
fclose(mm_runner.stream_fid);

%% PLOT performance plot
c = [];
for i=1:size(mm_runner.info_cache, 2)
    s = (cellfun(@(s)isempty(strfind(s,'Inaccurate')), {mm_runner.info_cache(:,i).status})');
    dc = [mm_runner.info_cache(:,i).iter]'./s;
    c = [c dc];
end

[t, p] = perf_profile(c);

figure;
set(0,'DefaultAxesFontSize',12)
semilogx(t, p(:,5), 'linewidth', 2); hold on;
semilogx(t, p(:,7), 'linewidth', 2);

xlabel('performance ratio'); 
ylabel('Problems solved'); 
grid on;
axis tight;
ylim([0,1]);