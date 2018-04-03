function idx_row = get_row_idx(obj, row_name)
IndexC = strfind(obj.rows(:,2), row_name);
idx = not(cellfun('isempty', IndexC));
idx_row = obj.rows{idx, 3};
end