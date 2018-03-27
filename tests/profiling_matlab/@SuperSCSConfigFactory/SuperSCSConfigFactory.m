classdef SuperSCSConfigFactory < handle
    
    methods (Static, Access = public)
        
        function ops = scsConfig()
            ops = SuperSCSConfigFactory.profile_ops(0);
            ops.k0 = 0;
            ops.k1 = 0;
            ops.k2 = 0;
            ops.ls = 0;
        end
        
        function ops = oldScsConfig()
            ops = SuperSCSConfigFactory.profile_ops(0);
            ops.do_super_scs = 0;
        end
        
        function ops = broydenConfig(memory)
            ops = SuperSCSConfigFactory.profile_ops();
            ops.direction = 100;
            if nargin >=1
                ops.memory = memory;
            else
                ops.memory = 50;
            end
        end
        
        function ops = andersonConfig(memory)
            ops = SuperSCSConfigFactory.profile_ops();
            ops.direction = 150;
            if nargin >=1
                ops.memory = memory;
            else 
                ops.memory = 10;
            end
        end
        
        function ops = fprDirectionConfig()
            ops = SuperSCSConfigFactory.profile_ops();
            ops.direction = 200;
        end
        
    end
    
    methods (Static, Access = private)        
        options = profile_ops(do_super_scs);
    end
    
end