classdef SifParser < handle
    %SIFPARSER is a MATLAB class that parses SIF/QPS/MPS files which
    %represent QP problems of the general form
    %
    %  Minimize  (OBJ)  : 0.5 x'*Q*x + q'*x
    %  subject to
    %            (EQ)   : Ax == b
    %            (INEQ) : Cx <= c
    %            (BND)  : l  <= x  <= u
    %            (FIX)  : x(i) == d(i), for i in I_fix
    %
    
    properties 
        sif_name;               %Filename
        sif_fid;                %File ID
        problem_name;           %Problem name as specified in the SIF file
        variables;              %Cell array with names of variables
        rows;                   %Row information
        quadobj;                %Quadratic objective
        columns;                %Columns
        bounds;                 %Bounds
        rhs;                    %Right-hand side vectors
        n_vars;                 %Number of variables
        n_constraints;          %Number of constraints
        n_equality_rows;        %Number of equality constraints (rows)
        n_l_inequality_rows;    %Number of lower inequality constraints (rows)
        n_g_inequality_rows;    %Number of upper inequality constraints (rows)
        Q;                      %Matrix Q
        q;                      %Vector q
        C;                      %Matrix C
        A;                      %Matrix A
        b;                      %Vector b
        c;                      %Vector c
        l;                      %Lower bound l
        u;                      %Upper bound u
        bounds_specified;       %Whether bounds have been specified
        c_fix;
    end % end of properties
    
    methods(Access = public)
        function obj = SifParser(sif_name)
            obj.sif_name = obj.sifload(sif_name);
            obj.clear_data();
        end
        
        function data = get_qp_data(obj)
            data.Q = obj.Q;
            data.q = obj.q;
            data.A = obj.A;
            data.C = obj.C;
            data.b = obj.b;
            data.c = obj.c;
            data.l = obj.l;
            data.u = obj.u;
        end
        
        parse(obj)
                        
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
                case 'BOUNDS'
                    obj.parse_bounds();
                otherwise
                    % do nothing
            end % end of switch(r.section)
        end
        
        clear_data(obj)
        parse_quadobj(obj)
        parse_rows(obj)
        parse_columns(obj)
        parse_rhs(obj)
        make_Q(obj)
        make_ACq(obj)
        make_bc(obj)
        make_lu(obj)
        parse_bounds(obj)
        idx = get_variable_idx(obj, variable_name)
        idx_row = get_row_idx(obj, row_name)
        
        function row_type = retrieve_row_type(obj, row_name)
            IndexC = regexp(obj.rows(:,2), row_name);
            idx = not(cellfun('isempty', IndexC));
            row_type = obj.rows{idx,1};
        end
        
        function update_count_rows_by_type(obj)
            obj.n_equality_rows = length(strfind([obj.rows{:,1}],'E'));
            obj.n_l_inequality_rows = length(strfind([obj.rows{:,1}],'L'));
            obj.n_g_inequality_rows = length(strfind([obj.rows{:,1}],'G'));
        end
        
        function post_process(obj)
            obj.make_Q();
            obj.make_ACq();
            obj.make_bc();
            obj.make_lu();
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
        
        function tokens = process_punch_line(line)
            positions = [1, 5, 15, 25, 40, 50, 65];
            len = length(line);
            tokens = cell(0);
            for k=1:6
                tokens = [tokens, ...
                    strtrim(line(positions(k):min(len,positions(k+1)-1)))];
            end
        end
        
    end % end of private static methods
    
end