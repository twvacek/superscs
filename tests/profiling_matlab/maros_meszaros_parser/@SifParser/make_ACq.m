function make_ACq(obj)

obj.A = sparse(obj.n_equality_rows, obj.n_vars);
obj.C = sparse(obj.n_l_inequality_rows + obj.n_g_inequality_rows, obj.n_vars);
obj.q = sparse(obj.n_vars, 1);

for i=1:size(obj.columns,1)
    var_name = obj.columns{i,1};
    row_name = obj.columns{i,2};
    value = obj.columns{i,3};
    row_type = obj.retrieve_row_type(row_name);
    idx_var = obj.get_variable_idx(var_name);
    idx_row = obj.get_row_idx(row_name);
    switch row_type
        case 'N'
            obj.q(idx_var) = value;
        case 'E'
            obj.A(idx_row, idx_var) = value;
        case 'L'
            obj.C(idx_row, idx_var) = value;
        case 'G'
            obj.C(idx_row, idx_var) = -value;
        otherwise
            % do nothing
    end
end

end