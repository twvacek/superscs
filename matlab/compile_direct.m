function compile_direct(flags, common_scs)

scs_root_dir = get_scs_rootdir();
scs_matlab_dir = [scs_root_dir 'matlab/'];
linsys_direct_dir = [scs_root_dir 'linsys/direct/'];
include_dir = [scs_root_dir 'include/'];

if (flags.COMPILE_WITH_OPENMP)
    cmd = sprintf(['mex -O %s %s %s %s COMPFLAGS="/openmp \\$COMPFLAGS" ' ...
    'CFLAGS="\\$CFLAGS -fopenmp" -I' scs_root_dir ' -I' include_dir ' %s'], ...
    flags.arr, flags.LCFLAG, flags.INCS, flags.INT);
else
    cmd = sprintf (['mex -O %s %s %s %s -I' scs_root_dir ' -I' include_dir ' %s'], ...
        flags.arr, flags.LCFLAG, flags.INCS, flags.INT);
end

amd_files = {'amd_order', 'amd_dump', 'amd_postorder', 'amd_post_tree', ...
    'amd_aat', 'amd_2', 'amd_1', 'amd_defaults', 'amd_control', ...
    'amd_info', 'amd_valid', 'amd_global', 'amd_preprocess' } ;
for i = 1 : length (amd_files)
    cmd = sprintf (['%s ' linsys_direct_dir 'external/%s.c'], cmd, amd_files {i}) ;
end

cmd = sprintf (['%s ' linsys_direct_dir 'external/ldl.c %s ' ...
    linsys_direct_dir 'private.c %s %s %s -output ' scs_matlab_dir 'scs_direct'], ...
    cmd, common_scs, flags.link, flags.LOCS, flags.BLASLIB);
eval(cmd);
