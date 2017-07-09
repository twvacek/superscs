/*! \page page_warm_starting Warm Starting
 * 
 * We may warm start SuperSCS by passing an initial estimate of the (x,y)-solution.
 * 
 * To activate warm starting, set <code>warm_start</code> to \c 1.
 * 
 * Here is a simple example in MATLAB:
 * 
 * ~~~~~{.m}
 * K.q = 4;
 * 
 * A(1,1) = 0.3;
 * A(4,1) = -0.5;
 * A(2,2) = 0.7;
 * A(4,2) = 0.9;
 * A(3,3) = 0.2;
 * 
 * b = [0.2; 0.1; -0.1; 0.1];
 * c = [1;-2;-3];
 * 
 * data.A = sparse(A);
 * data.b = b;
 * data.c = c;
 * 
 * params.eps      = 1e-6;
 * params.verbose  = 1;
 * [x, y, s, info] = scs_direct(data, K, params);
 * ~~~~~
 */