function parse_columns(obj)
while 1
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line);
        break;
    end
    % do the parsing
    
    tokens = obj.process_punch_line(line);
    column_name = tokens{1};
    row_name    = tokens{2};
    value       = tokens{3};
    column_name = strrep(column_name,' ','_');
    row_name = strrep(row_name,' ','_');
    obj.columns = [obj.columns; {column_name, row_name, str2double(value)}];
    if length(tokens) > 3
        row_name = tokens{4};
        value    = tokens{5};
        row_name = strrep(row_name,' ','_');
        obj.columns = [obj.columns; 
            {column_name, row_name, str2double(value)}];
    end
end
