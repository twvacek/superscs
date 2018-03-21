function o = profile_ops(do_super_scs)

perform_super_scs = 1;
if nargin >= 1
    perform_super_scs = do_super_scs;
end

o.alpha     = 1.5;
o.beta      = 0.5;
o.c1        = 0.99;
o.c_bl      = 0.99;
o.cg_rate   = 2;
o.direction = 100;
o.do_super_scs = 1;
if perform_super_scs
    o.k0 = 1;
    o.k1 = 1;
    o.k2 = 1;
    o.ls = 10;
else
    o.k0 = 0;
    o.k1 = 0;
    o.k2 = 0;
    o.ls = 0;
end
o.memory    = 50;
o.normalize = 1;
o.rho_x     = 0.001;
o.scale     = 1;
o.sigma     = 0.1;
o.sse       = 0.999;
o.thetabar  = 0.2;
o.verbose   = 1;
o.do_record_progress = 0;
o.use_indirect = 1;
o.max_iters    = 5000;
o.warm_start   = 0;
o.dumpfile     = [get_scs_rootdir() 'temp/temp.mat'];