
mm_runner = MarosMeszarosRunner();
mm_runner.set_max_filesize_MB(1.5);
mm_runner.set_verbose(true);
mm_runner.add_config(SuperSCSConfig.andersonConfig('memory', 4));
mm_runner.add_config(SuperSCSConfig.andersonConfig('memory', 5));

mm_runner.run();