function parse_rows(obj)

k_eq = 0;
k_ineq = 0;
while 1    
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line); break;
    end
    tokens = obj.process_punch_line(line);
    row_type = tokens{1}; row_name = tokens{2};    
    if strcmp(row_type,'N'), 
        idx = -1; 
    elseif strcmp(row_type,'E'), 
        k_eq = k_eq + 1; idx = k_eq;
    elseif strcmp(row_type,'L') || strcmp(row_type,'G'), 
        k_ineq = k_ineq + 1; idx = k_ineq;
    end
    obj.rows = [obj.rows; {row_type row_name idx}];
end

end