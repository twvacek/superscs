classdef MarosMeszarosRunner < handle
    
    properties (Access = public)
        config_cache;
        max_filesize_mb;
        info_cache;
        verbose
        stream_fid;
        problem_names;
    end % END of properties
    
    methods (Static, Access = private)
        function info = make_info_template()
            info = struct('iter', [], ...
                'status', 'Pending', ...
                'pobj', [], ...
                'dobj', [], ...
                'resPri', [],...
                'resDual', [],...
                'resInfeas', [],...
                'resUnbdd', [],...
                'relGap', [],...
                'setupTime', [],...
                'solveTime', [],...
                'progress_iter', [],...
                'progress_relgap', [],...
                'progress_respri', [],...
                'progress_resdual', [],...
                'progress_pcost', [],...
                'progress_dcost', [],...
                'progress_time', [],...
                'progress_mode', [],...
                'progress_ls', [],...
                'allocated_memory_bytes', []);
        end
    end % END of static private methods
    
    methods (Access = private)
        function bootstrap_info(obj, num_problems)
            info_template = MarosMeszarosRunner.make_info_template();
            obj.info_cache = repmat(info_template, num_problems, numel(obj.config_cache));
        end
        
        function print_header_line(obj)
            for j=1:numel(obj.config_cache)+1,
                fprintf(obj.stream_fid,'|------------------');
            end
            fprintf(obj.stream_fid,'|\n');
        end
        
        function print_header(obj)
            if isempty(obj.config_cache), return; end
            obj.print_header_line();
            fprintf(obj.stream_fid, '| %16s ', 'PROBLEM');
            for j=1:numel(obj.config_cache),
                fprintf(obj.stream_fid, '| %16s ', obj.config_cache(j).get_config_id);
            end
            fprintf('|\n');
            obj.print_header_line();
        end
        
        function print_info(obj, info)
            if strcmp(info.status, 'Solved')
                fprintf(obj.stream_fid, '| %7.1fms (%4d) ', info.solveTime, ...
                    info.iter);
            else
                fprintf(obj.stream_fid, '|        X         ');
            end
        end
    end % END of private methods
    
    methods (Access = public)
        
        function obj = MarosMeszarosRunner()
            obj.config_cache = [];
            obj.max_filesize_mb = 40;
            obj.stream_fid = 1;
        end
        
        function obj = add_config(obj, config)
            if ~isa(config,'SuperSCSConfig')
                error('ME:IllegalProperty', ...
                    'You must provide a SuperSCSConfig object');
            end
            obj.config_cache = [obj.config_cache, config];
        end
        
        function obj = set_verbose(obj, verbosity_level)
            obj.verbose = verbosity_level;
        end
        
        function obj = set_max_filesize_MB(obj, max_size)
            obj.max_filesize_mb = max_size;
        end
        
        function run(obj)
            if isempty(obj.config_cache), return; end
            if obj.verbose > 0, obj.print_header(); end
            parsed_data_path = [get_scs_rootdir ...
                'tests/profiling_matlab/maros_meszaros/parsed_data/'];
            parsed_data_dir = dir([parsed_data_path '*.mat']);
            num_sif_objects = numel(parsed_data_dir);
            num_configs = numel(obj.config_cache);
            sif_object = [];
            obj.problem_names = cell(num_sif_objects, 1);
            
            idx_solved_problem = 0;
            
            bootstrap_info(obj, num_sif_objects);
            
            for i = 1:num_sif_objects,
                
                file_name = parsed_data_dir(i).name;
                if parsed_data_dir(i).bytes/1e6 > obj.max_filesize_mb,
                    continue;
                end
                load([parsed_data_path file_name]);
                
                % Run for the first configuration / the first time CVX
                % parses the problem and returns `data` and `cones` which
                % are subsequently passed to SCS directly (without the
                % overhead of parsing the problem).
                config = obj.config_cache(1);
                try
                    [~, info, data, cones] = solve_maros_meszaros(sif_object, config);
                    idx_solved_problem = idx_solved_problem + 1;
                catch
                    % CVX could not parse this problem!
                    continue
                end
                
                obj.problem_names{idx_solved_problem} = ...
                    sif_object.get_problem_name;
                obj.info_cache(idx_solved_problem, 1) = info;
                
                if obj.verbose > 0,
                    fprintf(obj.stream_fid, '| %16s ', sif_object.get_problem_name);
                    obj.print_info(info);
                end
                
                for j = 2:num_configs
                    config = obj.config_cache(j);                  
                    [~,~,~,info] = scs_indirect(data, cones, config.to_struct());
                    obj.info_cache(idx_solved_problem, j) = info;
                    obj.print_info(info);
                end
                
                if obj.verbose > 0, fprintf(obj.stream_fid, '|\n'); end
            end
            % trim
            obj.problem_names = obj.problem_names{1:idx_solved_problem};
            obj.info_cache = obj.info_cache(idx_solved_problem,:);
        end % END of `run`
        
    end % END of public methods
end