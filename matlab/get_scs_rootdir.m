function rd = get_scs_rootdir()
rd = which('get_scs_rootdir');
tokens = strsplit(rd, 'matlab/get_scs_rootdir.m');
rd = tokens{1};
end