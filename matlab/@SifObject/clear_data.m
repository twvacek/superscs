function clear_data(obj)
obj.rows = cell(0);
obj.quadobj = cell(0);
obj.columns = cell(0);
obj.rhs = cell(0);
obj.bounds = cell(0);
obj.variables = cell(0);
obj.n_vars = 0;
obj.n_constraints = 0;
obj.bounds_specified = 0;
obj.n_constraints = 0;
obj.n_equality_rows = 0;
obj.n_g_inequality_rows = 0;
obj.n_l_inequality_rows = 0;
obj.n_vars = 0;
obj.A = [];
obj.b = [];
obj.Q = [];
obj.q = [];
obj.C = [];
obj.c = [];
obj.l = [];
obj.u = [];
obj.c_fix = [];
end