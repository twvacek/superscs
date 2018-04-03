function idx_variable = get_variable_idx(obj, variable_name)
%GET_VARIABLE_IDX returns the id of a variable with given name
%(variable_name)
idx_variable = find(strcmp(obj.variables, variable_name));
end