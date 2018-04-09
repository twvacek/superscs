function [array, count] = read_array(fid)
fscanf(fid, ' [');
[array, count] = fscanf(fid, '%g,');
if ~feof(fid), fscanf(fid, ']'); end
if ~feof(fid), fscanf(fid,'\n'); end