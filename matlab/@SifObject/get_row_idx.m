function idx_row = get_row_idx(obj, row_name)
%GET_ROW_IDX returns the id of a row of given name (row_name)
idx = strcmp(obj.rows(:,2), row_name);
idx_row = obj.rows{idx, 3};
end