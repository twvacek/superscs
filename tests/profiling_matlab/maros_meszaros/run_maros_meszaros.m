
mm_runner = MarosMeszarosRunner();
mm_runner.set_max_filesize_MB(1.5);
mm_runner.set_verbose(true);
mm_runner.add_config(SuperSCSConfig.andersonConfig('memory', 7));
mm_runner.add_config(SuperSCSConfig.andersonConfig('memory', 5));

mm_runner.run();

%%
fid = fopen('a.txt', 'w');
mm_runner.stream_fid = fid;
mm_runner.print_html('');
fclose(fid);

%%
mm_runner.stream_fid = 1;
mm_runner.print_html('');