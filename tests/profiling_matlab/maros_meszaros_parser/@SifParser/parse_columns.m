function parse_columns(obj)
while 1
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line);
        break;
    end
    % do the parsing
    columns_tokens = strsplit(strtrim(line), ' ');
    obj.columns = [obj.columns; {columns_tokens{1:2}, str2double(columns_tokens{3})}];
    if length(columns_tokens) == 5
        obj.columns = [obj.columns; {columns_tokens{[1,4]}, str2double(columns_tokens{5})}];
    end
end
