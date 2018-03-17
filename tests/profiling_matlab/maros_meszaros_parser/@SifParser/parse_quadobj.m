function parse_quadobj(obj)
while 1
    line = fgetl(obj.sif_fid);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line);
        break;
    end
    quadobj_tokens = strsplit(strtrim(line), ' ');
    obj.quadobj = [obj.quadobj;
        {quadobj_tokens{1:2} str2double(quadobj_tokens{3})}];
end
end