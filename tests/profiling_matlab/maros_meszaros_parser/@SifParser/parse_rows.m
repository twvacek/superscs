function parse_rows(obj)

k = 0;
while 1    
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line); break;
    end
    tokens = obj.process_punch_line(line);
    row_type = tokens{1}; row_name = tokens{2};    
    if strcmp(row_type,'N'), idx = -1; else k = k + 1; idx = k;end
    obj.rows = [obj.rows; {row_type row_name idx}];
end

end