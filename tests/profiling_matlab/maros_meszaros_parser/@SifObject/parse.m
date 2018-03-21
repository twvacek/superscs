function parse(obj)
obj.clear_data();
obj.sif_fid = fopen([SifObject.local_destination '/'  obj.sif_name]);
if obj.sif_fid < 0, error('Cannot open this .SIF file'); end
while ~feof(obj.sif_fid)
    line = fgetl(obj.sif_fid);
    line = strtrim(line);
    r = obj.detect_new_section(line);
    if ~isempty(r)
        obj.delegate_section(r, line);
    end
end % end of file - end parsin
fclose(obj.sif_fid);
obj.variables = unique(obj.columns(:,1));
obj.n_vars = length(obj.variables);
obj.n_constraints = size(obj.rows, 1) - 1;
obj.update_count_rows_by_type();
obj.post_process();
end