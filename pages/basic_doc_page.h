/*! \page page_doc Using SuperSCS
 * 
 * \section secc SuperSCS in C 
 * 
 * \section secmatlab SuperSCS in MATLAB
 * 
 * SuperSCS can be called directly, to solve conic problems, in MATLAB.
 * 
 * ~~~~~
 * m = 9;
 * n = 4;
 * data.A = sparse(randn(m,n));
 * data.b = randn(m,1);
 * data.c = randn(n,1);
 * cones.q = m;
 * solver_options = struct('eps',1e-5,'do_super_scs',1,'memory',50,'rho_x',.001);
 * [x,y,s,info] = scs_direct(data, cones, solver_options);
 * ~~~~~
 * 
 * \section seccvx SuperSCS via CVX in MATLAB
 * 
 * \section secpython SuperSCS in Python
 * 
 * In order to use SuperSCS in Python, you first need to \ref sec_installation_python "install the \c superscs module".
 * 
 * Then, it is straightforward to <code>import superscs</code>, define the problem data
 * (matrix \c A as a <code>scipy.sparse</code> matrix and vectors \c b and \c c),
 * the cone and call <code>superscs.solve</code>:
 * 
 * ~~~~~
 * import superscs
 * import numpy as np
 * from scipy import sparse
 * ij = np.array([[0,1,2,3],[0,1,2,3]])
 * A = sparse.csc_matrix(([-1.,-1.,1.,1.], ij), (4,4))
 * b = np.array([0.,0.,1,1])
 * c = np.array([1.,1.,-1,-1])
 * cone = {'l': 4}
 * data = {'A': A, 'b':b, 'c':c}
 * sol = superscs.solve(data, cone, use_indirect = False, memory = 50, verbose = 2)
 * ~~~~~
 * 
 * The last invocation takes as input arguments:
 * 
 * 1. the object \c data which is the triplet \f$(A,b,c)\f$; the problem data,
 * 2. the cone \c cone which, here, is a linear cone of dimension 4,
 * 3. additional optional arguments (such as the LBFGS memory)
 * 
 * The call returns \c sol; an object which return the solver status, the 
 * solution and additional information.
 * 
 * Here is what we see if we print out \c sol from the example above:
 * 
 * ~~~~~{.json}
 * {'info': {'dobj': -1.9999059647316126,
 *           'iter': 3,
 *           'pobj': -1.999698352184447,
 *           'relGap': 4.1525795644121774e-05,
 *           'resDual': 3.168953637264187e-05,
 *           'resInfeas': nan,
 *           'resPri': 6.556650505320437e-05,
 *           'resUnbdd': 1.376693966512017,
 *           'setupTime': 0.104,
 *           'solveTime': 0.477834,
 *           'status': 'Solved',
 *           'statusVal': 1},
 * 's': array([ 0.,  0.,  0.,  0.]),
 * 'x': array([  5.13892443e-05,   5.13892443e-05,   9.99900565e-01,
 *         9.99900565e-01]),
 * 'y': array([ 0.99995195,  0.99995195,  0.99995298,  0.99995298])}
 * ~~~~~
 * 
 * We see that <code>sol.status</code> is <code>Solved</code> and the status code
 * is <code>sol.statusVal: 1</code>, meaning that the problem has been solved.
 * 
 * The triplet <code>(x,y,s)</code> is the solution of the problem and <code>sol.pobj</code>
 * and <code>sol.dobj</code> are the values of the primal and dual objectives.
 * 
 * We may also inspect the relative duality gap, primal and dual residuals, 
 * the residuals associated with the infeasibility and unboundedness of the solution
 * and the number of iterations required to solve the problem.
 * 
 */