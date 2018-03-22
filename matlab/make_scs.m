% Directories (absolute paths)
scs_root_dir = get_scs_rootdir();
scs_matlab_dir = [scs_root_dir 'matlab/'];
source_dir = [scs_root_dir 'src/'];
linsys_src_dir = [scs_root_dir 'linsys/'];
include_dir = [scs_root_dir 'include'];

gpu = false; % compile the gpu version of SCS
float = false; % using single precision (rather than double) floating points
int = false; % use 32 bit integers for indexing
% WARNING: OPENMP WITH MATLAB CAN CAUSE ERRORS AND CRASH, USE WITH CAUTION:
% openmp parallelizes the matrix multiply for the indirect solver (using CG):
flags.COMPILE_WITH_OPENMP = false;

flags.BLASLIB = '-lmwblas -lmwlapack';
% MATLAB_MEX_FILE env variable sets blasint to ptrdiff_t
flags.LCFLAG = '-DMATLAB_MEX_FILE -DLAPACK_LIB_FOUND -DCTRLC=1 -DCOPYAMATRIX';
flags.INCS = '';
flags.LOCS = '';


common_scs = [source_dir 'linAlg.c ' ...
    source_dir 'cones.c ' ...
    source_dir 'cs.c ' ...
    source_dir 'util.c ' ...
    source_dir 'scs.c ' ...
    source_dir 'ctrlc.c ' ...
    source_dir 'directions.c ' ...
    linsys_src_dir 'common.c ' ...
    source_dir 'scs_version.c ' ...
    scs_matlab_dir 'scs_mex.c'];
if (~isempty (strfind (computer, '64')))
    flags.arr = '-largeArrayDims';
else
    flags.arr = '';
end

if ( isunix && ~ismac )
    flags.link = '-lm -lut -lrt';
elseif  ( ismac )
    flags.link = '-lm -lut';
else
    flags.link = '-lut';
    flags.LCFLAG = sprintf('-DNOBLASSUFFIX %s', flags.LCFLAG);
end

if (float)
    flags.LCFLAG = sprintf('-DFLOAT %s', flags.LCFLAG);
end
if (int)
    flags.INT = '';
else
    flags.INT = '-DDLONG';
end

if (flags.COMPILE_WITH_OPENMP)
    flags.link = strcat(flags.link, ' -lgomp');
end

compile_direct(flags, common_scs);
compile_indirect(flags, common_scs);
if (gpu)
    compile_gpu(flags, common_scs);
end

% compile scs_version
mex('-O', ['-I' include_dir], [source_dir 'scs_version.c'], ...
    [scs_matlab_dir 'scs_version_mex.c'], ...
    '-output', [scs_matlab_dir 'scs_version']);


%
clear data cones x y s info
disp('Example run:');
randn('seed',9);
m = 9;
n = 4;
data.A = sparse(randn(m,n));
data.b = randn(m,1);
data.c = randn(n,1);
cones.q = m;
[x,y,s,info] = scs_direct(data,cones,struct('eps',1e-5,'do_super_scs',1,'memory',50,'rho_x',.001));
assert(strcmp(info.status,'Solved')==1);
assert(abs(info.pobj-info.dobj)<1e-4);

%
[x,y,s,info] = scs_indirect(data,cones,struct('eps',1e-5,'do_super_scs',1,'rho_x',.001));
assert(strcmp(info.status,'Solved')==1);
assert(abs(info.pobj-info.dobj)<1e-4);

if (gpu)
    [x,y,s,info] = scs_gpu(data,cones,[]);
end


% % test-warm start with solution
% disp('Warm-starting:')
% %TODO: There is some problem with warm-starting...
% %  data.x = x;
% %  data.y = y;
% %  data.s = s;
% [x,y,s,info] = scs_indirect(data,cones,struct('eps',1e-10,'verbose',1,'do_super_scs',1,'memory',100));
% assert(strcmp(info.status,'Solved')==1);
% assert(abs(info.pobj-info.dobj)<1e-4);

disp(['[SuperSCS] Adding ' scs_matlab_dir ' to the path']);
addpath(genpath(scs_matlab_dir))
savepath();
disp('[SuperSCS]  SUCCESSFULLY INSTALLED SuperSCS')
disp('(If using SuperSCS with CVX, note that it only supports CVX v3.0 or later).')
