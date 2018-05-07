function [x, info, data, cones, pars] = solve_maros_meszaros(sif_object, solver_options)

x=[]; info = []; data=[]; K = []; pars = [];
qp_data = sif_object.get_qp_data();
n = size(qp_data.Q, 1);

cvx_begin quiet
    cvx_solver scs 
    scs_set_options(solver_options)
    variable x(n)
    minimize( 0.5*x'*qp_data.Q*x + qp_data.q'*x );
    subject to
        qp_data.A*x == qp_data.b
        qp_data.C*x <= qp_data.c       
        for i=1:length(qp_data.u)
            if ~isinf(qp_data.u(i)),
                x(i) <= qp_data.u(i)
            end
        end
        for i=1:length(qp_data.l)
            if ~isinf(qp_data.l(i)),
                x(i) >= qp_data.l(i)
            end
        end
        for i=1:size(qp_data.c_fix)
            x(qp_data.c_fix(i,1)) == qp_data.c_fix(i,2)
        end
cvx_end

load(solver_options.dumpfile)
cones = K;
delete(solver_options.dumpfile)

