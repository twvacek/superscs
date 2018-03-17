classdef SifParser < handle
    %SIFPARSER is a MATLAB class that parses SIF/QPS/MPS files which
    %represent QP problems of the general form
    %
    %  Minimize  (OBJ)  : 0.5 x'*Q*x + q'*x
    %  subject to 
    %            (EQ)   : Ax == b
    %            (INEQ) : Cx <= c
    %            (BND)  : l  <= x  <= u
    %
    %
    
    properties
        sif_name;
        sif_fid;
        problem_name;
        variables;
        rows;
        quadobj;
        columns;
        rhs;
        n_vars;
        n_constraints;
        n_equality_rows;
        n_l_inequality_rows;
        n_g_inequality_rows;
        Q;
        q;
        l;
        u;
        A;
        C;
    end % end of properties
    
    methods(Access = public)
        function obj = SifParser(sif_name)
            obj.sif_name = obj.sifload(sif_name);
            obj.clear_data();
        end
        
        parse(obj)   
        
        function row_type = retrieve_row_type(obj, row_name)
            IndexC = regexp({obj.rows{:,2}}, row_name);
            idx = not(cellfun('isempty', IndexC));
            row_type = obj.rows{idx,1};
        end
             
    end % end public methods
    
    
    methods (Access = private)
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
                otherwise
                    % do nothing
            end
        end
        
        
        clear_data(obj)
        parse_quadobj(obj)
        parse_rows(obj)
        parse_columns(obj)
        parse_rhs(obj)
        make_Q(obj)
        make_ACc(obj)
        idx = get_variable_idx(obj, variable_name)
        idx_row = get_row_idx(obj, row_name)
        
        function update_count_rows_by_type(obj)
            obj.n_equality_rows = length(strfind([obj.rows{:,1}],'E'));
            obj.n_l_inequality_rows = length(strfind([obj.rows{:,1}],'L'));
            obj.n_g_inequality_rows = length(strfind([obj.rows{:,1}],'G'));
        end             
       
        function post_process(obj)
            obj.make_Q();
            obj.make_ACc();
        end
        
        
    end % end of private methods
    
    methods (Static, Access = private)
        function r = detect_new_section(line)
            reg = '(?<section>\NAME|ROWS$|COLUMNS$|RHS$|BOUNDS$|QUADOBJ$|RANGES$|ENDATA$)';
            r = regexp(line, reg, 'names');
        end
        
        function sif_name = sifload(sif_name)
            if isempty(regexp(sif_name,'.SIF$', 'ONCE'))
                sif_name = [sif_name, '.SIF'];
            end
            if exist(sif_name, 'file') ~= 2
                ftpobj = ftp('ftp.numerical.rl.ac.uk');
                cd(ftpobj,'pub/cuter/marosmeszaros');
                mget(ftpobj, sif_name);
                close(ftpobj);
            end
        end
    end % end of private static methods
    
end