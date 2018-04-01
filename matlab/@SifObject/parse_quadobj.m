function parse_quadobj(obj)

while 1
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line); break;
    end
    tokens = obj.process_punch_line(line);
    col1 = tokens{1}; col2 = tokens{2}; value = tokens{3};
    obj.quadobj = [obj.quadobj; {col1, col2, str2double(value)}];
end

end