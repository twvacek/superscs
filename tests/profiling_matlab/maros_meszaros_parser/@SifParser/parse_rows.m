function parse_rows(obj)
k = 0;
while 1    
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line);
        break;
    end
    rows_tokens = strsplit(strtrim(line), ' ');
    if strcmp(rows_tokens{1},'N')
        obj.rows = [obj.rows; {rows_tokens{1:2}} -1];
    else
        k = k + 1;
        obj.rows = [obj.rows; {rows_tokens{1:2}} k];
    end
    
end
end