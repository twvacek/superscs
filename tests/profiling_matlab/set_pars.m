function set_pars(o, tol)

cvx_solver_settings('eps', tol,...
    'scale', o.scale,...
    'do_super_scs',o.do_super_scs,...
    'direction', o.direction,...
    'k0', o.k0,...
    'memory', o.memory,...
    'rho_x', o.rho_x,...
    'verbose', o.verbose, ...
    'do_record_progress', o.do_record_progress,...
    'thetabar', o.thetabar,...
    'ls',  o.ls,...
    'sse', o.sse)
if isfield(o, 'dumpfile'),
    cvx_solver_settings('dumpfile', o.dumpfile);
end
if isfield(o, 'use_indirect') && o.use_indirect,
    cvx_solver_settings('use_indirect', o.use_indirect);
end