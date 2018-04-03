classdef SifObject < handle
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
    
    properties (Constant)
        ftp_server = 'ftp.numerical.rl.ac.uk';    %Server name
        ftp_folder = 'pub/cuter/marosmeszaros';   %Folder in FTP server
        local_destination = [get_scs_rootdir() 'tests/profiling_matlab/maros_meszaros/sif_data/'];
    end
    
    properties (Access = private)
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
        bounds_specified;       %Whether bounds have been specified (0/1)
        c_fix = [];             %fixed variables
    end % end of properties
    
    methods(Access = public)
        function obj = SifObject(sif_name)
            obj.sif_name = obj.sifload(sif_name);
            obj.clear_data();
        end
        
        function [nvar, neq, nineq, nlineq, nuineq] = size(obj)
            nvar = obj.n_vars;
            neq =  obj.n_equality_rows;
            nineq = obj.n_constraints;
            nlineq = obj.n_l_inequality_rows;
            nuineq = obj.n_g_inequality_rows;
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
            data.c_fix = obj.c_fix;
        end
        
        function var_names = get_variable_names(obj)
            var_names = obj.variables;
        end
        
        function name = get_filename(obj)
            name = obj.sif_name;
        end
        
        function prob_name = get_problem_name(obj)
            prob_name = obj.problem_name;
        end
        
        function disp(obj)
            fprintf('SIF/MPS/QPS Object\n');
            fprintf('Problem name               : %s\n', obj.get_problem_name());
            if ~isempty(obj.variables)
                fprintf('Number of variables        : %d\n', obj.n_vars);
                fprintf('Number of inequalities     : %d\n', obj.n_constraints);
                fprintf('Number of equalities       : %d\n', obj.n_equality_rows);
            end
        end
        
        parse(obj)
        
    end % end public methods
    
    
    methods (Access = private)
        delegate_section(obj, r, line)        
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
            IndexC = strfind(obj.rows(:,2), row_name);
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
    
    
    methods (Static, Access = public)
        function lst = list()
            ftpobj = ftp(SifObject.ftp_server);
            cd(ftpobj,SifObject.ftp_folder);
            lst = dir(ftpobj);
            if isempty(lst)
                lst = [];
                return;
            end
            lst = {lst(:).name};
            taboo = [];
            for i=1:length(lst)
                if isempty(regexp(lst{i}, '.SIF$', 'once'))
                    taboo = [taboo, i];
                end
            end
            lst(taboo) = [];
            close(ftpobj);
        end
        
        function download_all()
            lst = SifObject.list();
            ftpobj = ftp(SifObject.ftp_server);
            cd(ftpobj,SifObject.ftp_folder);
            for i = 1:length(lst)
                sif_filename = lst{i};
                if ~isempty(regexp(sif_filename, '.SIF$', 'ONCE'))
                    mget(ftpobj, sif_filename, SifObject.local_destination);
                end
            end
            close(ftpobj);
        end
        
        function parse_all()
            parsed_destination_dir = [get_scs_rootdir() ...
                'tests/profiling_matlab/maros_meszaros/parsed_data/'];
            sif_files = dir([SifObject.local_destination '*.SIF']);
            for i = 1:length(sif_files)
                current_sif_name = sif_files(i).name;
                fprintf('Parsing %s... ', current_sif_name);
                parse_start = tic;
                sif_object = SifObject(current_sif_name);
                destination = [parsed_destination_dir current_sif_name '.mat'];
                if exist(destination, 'file') ~= 2
                    try
                        sif_object.parse();
                    catch
                        warning('SifObject:parsingError', ...
                            'Exception caught while parsing');
                    end
                    parse_elapsed_time = toc(parse_start);
                    save(destination, 'sif_object');
                    fprintf(' done in %gs\n', parse_elapsed_time);
                else
                    fprintf('Object %s already parsed\n', current_sif_name);
                end                
            end
        end
    end % end of public static methods
    
    methods (Static, Access = private)
        function r = detect_new_section(line)
            reg = '(?<section>\NAME|ROWS$|COLUMNS$|RHS$|BOUNDS$|QUADOBJ$|RANGES$|ENDATA$)';
            r = regexp(line, reg, 'names');
        end
        
        
        function sif_name = sifload(sif_name)
            if isempty(regexp(sif_name,'.SIF$', 'ONCE'))
                sif_name = [sif_name, '.SIF'];
            end
            if exist([SifObject.local_destination sif_name], 'file') ~= 2
                ftpobj = ftp(SifObject.ftp_server);
                cd(ftpobj,SifObject.ftp_folder);
                mget(ftpobj, sif_name, SifObject.local_destination);
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