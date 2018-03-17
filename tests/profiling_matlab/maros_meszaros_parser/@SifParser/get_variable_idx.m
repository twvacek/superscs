function idx = get_variable_idx(obj, variable_name)
IndexC = strfind(obj.variables, variable_name);
idx = find(not(cellfun('isempty', IndexC)));
end