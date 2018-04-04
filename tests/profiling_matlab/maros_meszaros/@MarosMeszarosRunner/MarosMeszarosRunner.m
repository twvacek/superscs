classdef MarosMeszarosRunner < handle
    
    properties (Access = public)
        config_cache;
        max_filesize_mb;
        results;
    end
    
    methods (Access = public)
        
        function obj = MarosMeszarosRunner()
            obj.config_cache = [];
            obj.max_filesize_mb = 40;
        end
        
        function obj = add_config(obj, config)
            if ~isa(config,'SuperSCSConfig')
                error('ME:IllegalProperty', 'You must provide a SuperSCSConfig object');
            end
            obj.config_cache = [obj.config_cache, config];
        end
        
        function obj = set_max_filesize_MB(obj, max_size)
            obj.max_filesize_mb = max_size;
        end
        
        function run(obj)
            parsed_data_path = [get_scs_rootdir ...
                'tests/profiling_matlab/maros_meszaros/parsed_data/'];
            parsed_data_dir = dir([parsed_data_path '*.mat']);
            num_sif_objects = numel(parsed_data_dir);
            num_configs = numel(obj.config_cache);
            sif_object = []; info = []; data = []; K = []; pars = [];
            problem_names = cell(num_sif_objects, 1);
            
            for i = 1:num_sif_objects,
                skip_all = false;
                
                file_name = parsed_data_dir(i).name;
                if parsed_data_dir(i).bytes/1e6 > obj.max_filesize_mb, 
                    continue; 
                end
                load([parsed_data_path file_name]);
                
                % Run for the first configuration 
                config = obj.config_cache(1);
                try
                    [~, info, data, cones, pars] = ...
                        solve_maros_meszaros(sif_object, config);                                
                catch
                    continue
                end
                
                
                % run the rest of the problems using (data, cones, pars)
                for j = 2:num_configs 
                end
            end
            
        end
    end
end