clc;

parsed_data_path = [get_scs_rootdir ...
    'tests/profiling_matlab/maros_meszaros/parsed_data/'];
parsed_data_dir = dir([parsed_data_path '*.mat']);
num_sif_objects = numel(parsed_data_dir);
sif_object = [];
info = [];
structure_template = struct('sif','?','scs',Inf,'broyden_50',Inf, ...
    'broyden_100',Inf,'aa_5',Inf,'aa_10',Inf);
results = repmat(structure_template, num_sif_objects, 1 );


fprintf('|----------------');
fprintf('|----------------');
fprintf('|----------------');
fprintf('|----------------');
fprintf('|----------------');
fprintf('|-----------------|\n')

fprintf('|           SIF  ');
fprintf('|           SCS  ');
fprintf('|    BROYDEN 50  ');
fprintf('|   BROYDEN 100  ');
fprintf('|         AA  5  ')
fprintf('|         AA 10   |\n')

fprintf('|----------------');
fprintf('|----------------');
fprintf('|----------------');
fprintf('|----------------');
fprintf('|----------------');
fprintf('|-----------------|\n')


for i = 1:num_sif_objects
    skip_all = false;
    
    file_name = parsed_data_dir(i).name;
    if parsed_data_dir(i).bytes/1e6 > 1.5, continue; end
    load([parsed_data_path file_name]);
    
    results(i).sif = file_name;
    
    fprintf('|     %9s  '       , sif_object.get_problem_name);
    
    config = SuperSCSConfig.oldScsConfig();
    try
        [~, info] = solve_maros_meszaros(sif_object, config);
        results(i).scs = info.solveTime/1e3/isempty(strfind(info.status, 'Inaccurate'));
    catch
        skip_all = true;
        results(i).scs = -1;
        results(i).broyden_50 = -1;
        results(i).broyden_100 = -1;
        results(i).aa_5 = -1;
        results(i).aa_10 = -1;        
    end
        
    
    fprintf('|     %9.2f  '   , results(i).scs);
    
    if skip_all, 
        fprintf('|     %9.2f  '   , -1);
        fprintf('|     %9.2f  '   , -1);
        fprintf('|     %9.2f  '   , -1);
        fprintf('|     %9.2f   |\n', -1);
        continue; 
    end
    
    config = SuperSCSConfig.broydenConfig('k0',0);
    try
        %[~, info] = solve_maros_meszaros(sif_object, config);
        %results(i).broyden_50 = info.solveTime/1e3/isempty(strfind(info.status, 'Inaccurate'));
    catch
        results(i).broyden_50 = -1;
    end
    fprintf('|     %9.2f  '   , results(i).broyden_50);
    
    config = SuperSCSConfig.broydenConfig('k0',0, 'memory', 100);
    try
        %[~, info] = solve_maros_meszaros(sif_object, config);
        %results(i).broyden_100 = info.solveTime/1e3/isempty(strfind(info.status, 'Inaccurate'));
    catch
        results(i).broyden_100 = -1;
    end
    fprintf('|     %9.2f  '   , results(i).broyden_100);
    
    
    config = SuperSCSConfig.andersonConfig('memory', 5);
    try
        [~, info] = solve_maros_meszaros(sif_object, config);
        results(i).aa_5 = info.solveTime/1e3/isempty(strfind(info.status, 'Inaccurate'));
    catch
        results(i).aa_5 = -1;
    end
    fprintf('|     %9.2f  '   , results(i).aa_5);
    
    
    config = SuperSCSConfig.andersonConfig('memory', 10);
    try
        [~, info] = solve_maros_meszaros(sif_object, config);
        results(i).aa_10 = info.solveTime/1e3/isempty(strfind(info.status, 'Inaccurate'));
    catch
        results(i).aa_10 = -1;
    end
    fprintf('|     %9.2f   |\n', results(i).aa_10);
end