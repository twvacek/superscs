function idx = get_variable_idx(obj, variable_name)
IndexC = regexp(obj.variables, [variable_name '$']);
idx = find(not(cellfun('isempty', IndexC)));
end