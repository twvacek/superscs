function options = profile_ops(do_super_scs)

perform_super_scs = 1;
if nargin >= 1
    perform_super_scs = do_super_scs;
end

options.alpha     = 1.5;
options.beta      = 0.5;
options.c1        = 0.99;
options.c_bl      = 0.99;
options.cg_rate   = 2;
options.direction = 100;
options.do_super_scs = 1;
if perform_super_scs
    options.k0 = 1;
    options.k1 = 1;
    options.k2 = 1;
    options.ls = 10;
else
    options.k0 = 0;
    options.k1 = 0;
    options.k2 = 0;
    options.ls = 0;
end
options.memory    = 50;
options.normalize = 1;
options.rho_x     = 0.001;
options.scale     = 1;
options.sigma     = 0.1;
options.sse       = 0.999;
options.thetabar  = 0.2;
options.verbose   = 0;
options.do_record_progress = 0;
options.use_indirect = 1;
options.max_iters    = 5000;
options.warm_start   = 0;
options.dumpfile     = [get_scs_rootdir() 'temp/temp.mat'];