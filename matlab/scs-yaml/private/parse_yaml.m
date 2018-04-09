function out = parse_yaml(filename)

out = [];
fid = fopen(filename,'r');
var_id = [];

% Take me to the first occurence of 'problem'
while ~strcmp(var_id,'problem')
    var_id = read_up_to_colon(fid);
    fgetl(fid);
    fscanf(fid,'\n');
end

%start parsing problem
while ~feof(fid)
    var_id = read_up_to_colon(fid);
    if isempty(var_id), continue; end
    switch var_id,
        case 'name'
            name = strtrim( fgetl(fid) );            
            out.name = name(2:end-1);
        case 'A'
            out = parse_A(fid, out);
        case 'b'
            out.b = read_array(fid);
        case 'c'
            out.c = read_array(fid);
        case 'K'
            out = parse_K(fid, out);
        otherwise
            break;
    end
end

fclose(fid);






function out = parse_A(fid, out)
k = 0;
while k < 6,
    var_id = read_up_to_colon(fid);
    out.A.(var_id) = read_array(fid);
    k = k + 1;
end
% verify A:
if ~isfield(out.A, 'm') ...
        || ~isfield(out.A, 'n') ...
        || ~isfield(out.A, 'nnz') ...
        || ~isfield(out.A, 'a') ...
        || ~isfield(out.A, 'I') ...
        || ~isfield(out.A, 'J'),
    error('yaml:invalid', 'Section `problem.A` should contain (m,n,nnz,a,I,J)');
end

function out = parse_K(fid, out)
k = 0;
while ~feof(fid) && k < 8,
    var_id = read_up_to_colon(fid);
    if isempty(var_id), break; end
    out.K.(var_id) = read_array(fid);
    k = k + 1;
end