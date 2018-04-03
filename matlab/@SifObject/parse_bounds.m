function parse_bounds(obj)

obj.bounds_specified = 1;

while 1
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line);
        break;
    end
    % do the parsing
    
    tokens = obj.process_punch_line(line);
    if length(tokens) == 3
        obj.bounds = [obj.bounds; [tokens, '-']];
    else
        obj.bounds = [obj.bounds; tokens];
    end        
end
obj.bounds = strrep(obj.bounds,' ','_');

end