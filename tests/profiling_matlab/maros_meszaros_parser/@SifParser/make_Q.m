function make_Q(obj)
obj.Q = sparse(obj.n_vars, obj.n_vars);
for i = 1:size(obj.quadobj,1)
    varname_row = obj.quadobj{i,1};
    varname_col = obj.quadobj{i,2};
    idx_row = obj.get_variable_idx(varname_row);
    idx_col = obj.get_variable_idx(varname_col);
    obj.Q(idx_row, idx_col) = obj.quadobj{i,3};
    if idx_col ~= idx_row,
        obj.Q(idx_col, idx_row) = obj.Q(idx_row, idx_col);
    end
end
end