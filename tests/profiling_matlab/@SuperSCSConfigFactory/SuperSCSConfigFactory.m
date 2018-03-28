classdef SuperSCSConfigFactory < handle
    %SuperSCSConfigFactory is a factory class to facilitate the
    %construction of SuperSCS configuration. 
    %
    
    methods (Static, Access = public)
        
        function ops = scsConfig()
            %SCSCONFIG returns the standard SCS configuration
            ops = SuperSCSConfigFactory.profile_ops(0);
            ops.k0 = 0;
            ops.k1 = 0;
            ops.k2 = 0;
            ops.ls = 0;
        end
        
        function ops = oldScsConfig()
            %OLDSCSCONFIG returns the SCS configuration using the legacy SCS
            %implementation
            ops = SuperSCSConfigFactory.profile_ops(0);
            ops.do_super_scs = 0;
        end
        
        function ops = broydenConfig(memory)
            %BROYDENCONFIG returns the SuperSCS configuration with
            %Broyden's directions with memory equal to 50 and k0, k1 and k2
            %all activated
            ops = SuperSCSConfigFactory.profile_ops();
            ops.direction = 100;
            if nargin >=1
                ops.memory = memory;
            else
                ops.memory = 50;
            end
        end
        
        function ops = andersonConfig(memory)
            %ANDERSONCONFIG returns the SuperSCS configuration with
            %Anderson's directions with memory equal to 10 and k0, k1 and k2
            %all activated
            ops = SuperSCSConfigFactory.profile_ops();
            ops.direction = 150;
            if nargin >=1
                ops.memory = memory;
            else 
                ops.memory = 10;
            end
        end
        
        function ops = fprDirectionConfig()
            %FPRDIRECTIONCONFIG returns the SuperSCS configuration using
            %the FPR as a direction and with all k0, k1 and k2 steps
            %activated.
            ops = SuperSCSConfigFactory.profile_ops();
            ops.direction = 200;
        end
        
    end
    
    methods (Static, Access = private)        
        options = profile_ops(do_super_scs);       
    end
    
end