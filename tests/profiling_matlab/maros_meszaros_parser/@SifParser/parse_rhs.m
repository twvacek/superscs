function parse_rhs(obj)
while 1
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line);
        break;
    end
    rhs_tokens = strsplit(strtrim(line), ' ');
    obj.rhs = [obj.rhs; {rhs_tokens{2}, str2double(rhs_tokens{3})}];
    if length(rhs_tokens) == 5
        obj.rhs = [obj.rhs; {rhs_tokens{4}, str2double(rhs_tokens{5})}];
    end
end
end