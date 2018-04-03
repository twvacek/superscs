function delegate_section(obj, r, line)
switch (r.section)
    case 'NAME'
        split_name_at_space = strsplit(line, ' ');
        obj.problem_name = split_name_at_space{2};
    case 'ROWS'
        obj.parse_rows();
    case 'COLUMNS'
        obj.parse_columns();
    case 'RHS'
        obj.parse_rhs();
    case 'QUADOBJ'
        obj.parse_quadobj();
    case 'BOUNDS'
        obj.parse_bounds();
    otherwise
        % do nothing
end % end of switch(r.section)
end