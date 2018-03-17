function clear_data(obj)
obj.rows = cell(0);
obj.quadobj = cell(0);
obj.columns = cell(0);
obj.rhs = cell(0);
obj.n_vars = 0;
obj.n_constraints = 0;
end