function make_bc(obj)

obj.b = sparse(obj.n_equality_rows, 1);
obj.c = sparse(obj.n_g_inequality_rows + obj.n_l_inequality_rows, 1);

for i=1:size(obj.rhs,1)
    row_name = obj.rhs{i,2};
    value    = obj.rhs{i,3};
    idx_row = obj.get_row_idx(row_name);
    row_type = obj.retrieve_row_type(row_name);
    switch row_type
        case 'E'
            obj.b(idx_row) = value;
        case 'L'
            obj.c(idx_row) = value;
        case 'G'
            obj.c(idx_row) = -value;
        otherwise
            % do nothing
    end
end

end