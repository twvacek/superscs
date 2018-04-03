function make_lu(obj)

if ~obj.bounds_specified
    return
end

obj.l = sparse(obj.n_vars,1);
obj.u = Inf(obj.n_vars,1);

for i=1:size(obj.bounds,1)
    bound_designation = obj.bounds{i,1};
    row_name = obj.bounds{i,3};
    id_variable = obj.get_variable_idx(row_name);
    switch bound_designation
        case {'FR', 'MI'}
            obj.l(id_variable) = -Inf;
        case 'LO'
            obj.l(id_variable) = str2double(obj.bounds{i,4});
        case 'UP'
            obj.u(id_variable) = str2double(obj.bounds{i,4});
        case 'FX'            
            obj.c_fix = [obj.c_fix; id_variable, str2double(obj.bounds{i,4})];
        case 'BV'
            error('Binary variables (BV) are not supporter');
        otherwise
            error(['Unknown designation: ''' bound_designation ...
                ''' in section ''BOUNDS''.']);
    end
end

end