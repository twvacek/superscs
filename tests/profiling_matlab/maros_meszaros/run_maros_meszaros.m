%% Benchmark parameters

% The MIT License (MIT)
%
% Copyright (c) 2017 Pantelis Sopasakis (https://alphaville.github.io),
%                    Krina Menounou (https://www.linkedin.com/in/krinamenounou), 
%                    Panagiotis Patrinos (http://homes.esat.kuleuven.be/~ppatrino)
% Copyright (c) 2012 Brendan O'Donoghue (bodonoghue85@gmail.com)
%
% Permission is hereby granted, free of charge, to any person obtaining a copy
% of this software and associated documentation files (the "Software"), to deal
% in the Software without restriction, including without limitation the rights
% to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
% copies of the Software, and to permit persons to whom the Software is
% furnished to do so, subject to the following conditions:
%
% The above copyright notice and this permission notice shall be included in all
% copies or substantial portions of the Software.
%
% THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
% IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
% FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
% AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
% LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
% OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
% SOFTWARE.

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
p = 100*p;
set(0,'DefaultAxesFontSize',12)
semilogx(t, p(:,1), 'linewidth', 3); hold on;
semilogx(t, p(:,3), 'linewidth', 2);
semilogx(t, p(:,4), 'linewidth', 2);
semilogx(t, p(:,6), 'linewidth', 2);
semilogx(t, p(:,7), 'linewidth', 2);

legend('SCS', 'AA 3', 'AA 5', 'RB 50', 'RB 100', 'Location', 'SouthEast');
xlabel('Performance ratio'); 
ylabel('Problems solved'); 
grid on;
axis tight;
ylim([0,100]);
