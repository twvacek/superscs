function rd = get_scs_rootdir()
%GET_SCS_ROOTDIR returns the SuperSCS root directory (absolute path).
%
rd = which('get_scs_rootdir');
tokens = strsplit(rd, 'matlab/get_scs_rootdir.m');
rd = tokens{1};
end