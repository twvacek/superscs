function problem_to_yaml(destination, problem_name, data, K)
%PROBLEM_TO_YAML serializes SuperSCS problem data to YAML
%
%Syntax:
%problem_to_yaml(destination, problem_name, data, K)
%
%Input arguments:
% destination       a file path (a string; either a relative or an absolute
%                   file path) OR the output of fopen(path, 'w')
% problem_name      a name for your problem 
% data              a structure with the problem data; the structure should
%                   contain the fields: `A`, `b` and `c`
% K                 the cones
%
%

should_close_fid = 0;
if ischar(destination),
    fid = fopen(destination, 'w');
    should_close_fid = 1;
elseif isnumeric(destination)
    fid = destination;    
end
space = '  ';
fprintf(fid, '---\n# SuperSCS Problem Data\n');
fprintf(fid, 'problem:\n');
fprintf(fid, '%sname: ''%s''\n', space, problem_name);
yamlify_sparse_matrix(fid, data.A)
fprintf(fid, '%sb:\n', space);
yamlify_array(fid, [space, space], data.b)
fprintf(fid, '%sc:\n', space);
yamlify_array(fid, [space space], data.c)
fprintf(fid, '%sK:\n', space);
fields_K = fieldnames(K);
for i=1:numel(fields_K)
    fprintf(fid, '%s%s%s: %g\n', space, space, fields_K{i}, K.(fields_K{i}));    
end
fprintf(fid, '...');
if should_close_fid,
    fclose(fid);
end

function yamlify_sparse_matrix(fid, A)
space = '  ';
double_space = [space space];
triple_space = [double_space space];
[m, n, nnz, a, jc, ir] = sparse_to_csc(A);
fprintf(fid, '%sA: \n', space);
fprintf(fid, '%sm: %d\n', double_space, m);
fprintf(fid, '%sn: %d\n', double_space, n);
fprintf(fid, '%snnz: %d\n', double_space, nnz);
fprintf(fid, '%sa:\n', double_space);
yamlify_array(fid, triple_space, a);
fprintf(fid, '%sj:\n', double_space);
yamlify_array(fid, triple_space, jc);
fprintf(fid, '%si:\n', double_space);
yamlify_array(fid, triple_space, ir);

function yamlify_array(fid, prefix, x)
for i=1:numel(x)
    fprintf(fid, '%s- %g\n', prefix, x(i));
end
