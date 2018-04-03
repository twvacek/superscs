function parse_rhs(obj)
while 1
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r), obj.delegate_section(r, line); break; end
    
    tokens = obj.process_punch_line(line);
    rhs_name = tokens{1};
    row_name = tokens{2};
    value    = tokens{3};
    rhs_name = strrep(rhs_name, ' ', '_');
    row_name = strrep(row_name, ' ', '_');
    obj.rhs = [obj.rhs; {rhs_name, row_name, str2double(value)}];
    if length(tokens) > 3
        row_name = tokens{4};
        value    = tokens{5};
        row_name = strrep(row_name, ' ', '_');
        obj.rhs = [obj.rhs; {rhs_name, row_name, str2double(value)}];
    end
end
end