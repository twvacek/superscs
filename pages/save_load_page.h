/*! \page page_save_load Saving and Loading Problems
 * 
 * \section superscs-yaml-format SuperSCS YAML format
 * 
 * A conic problem is described by the tuple \f$(A,b,c,\mathcal{K})\f$ where \f$A\f$
 * is an \f$m\times n\f$ \ref page_sparse_matrices "sparse matrix" and 
 * \f$\mathcal{K}\f$ is a cone.
 * 
 * These data can be saved in a 
 * <a href="http://docs.ansible.com/ansible/devel/reference_appendices/YAMLSyntax.html">YAML</a> 
 * file from which they can be accessed
 * from MATLAB, C, R, Java, Python and any other programming language.
 * 
 * YAML files are easy to parse and are human- and machine-readable.
 * 
 * Let us consider the following second-order cone program:
 * 
 * \f{eqnarray*}{
 * &&\mathrm{Minimize}\ \langle c, x \rangle\\
 * &&Ax + s = b\\
 * &&s\in\mathcal{K},
 * \f}
 * 
 * where \f$x\in\mathbb{R}^3\f$, \f$A\in\mathbb{R}^{4\times 3}\f$ is the following
 * \ref page_sparse_matrices "sparse matrix"
 * 
 * \f{eqnarray*}{
 * A &=& \begin{bmatrix}
 * 0.3\\
 * & 0.7\\
 * && 0.2\\
 * -0.5 & 0.9
 * \end{bmatrix}
 * \f}
 * 
 * and \f$c\in\mathbb{R}^3\f$ and \f$b\in\mathbb{R}^4\f$ are the vectors
 * 
 * \f{eqnarray*}{
 * c &=& \begin{bmatrix}
 * 1 & -2 & -3
 * \end{bmatrix}^{\top}
 * \f}
 * 
 * and
 * 
 * \f{eqnarray*}{
 * b &=& \begin{bmatrix}
 * 0.2 & 0.1 & -0.1 & 0.1
 * \end{bmatrix}^{\top}.
 * \f}
 * 
 * Let \f$\mathcal{K}\f$ be the second-order cone in \f$\mathbb{R}^4\f$.
 * 
 * The YAML representation of this problem is as follows:
 * 
 * ~~~~~{.yaml}
 * --- # SuperSCS Problem
 * problem:
 *     name: 'test-problem-1'
 *     A: 
 *         m: 4
 *         n: 3
 *         nnz: 5
 *         a: [0.3,-0.5,0.7,0.9,0.2]
 *         I: [0,2,4,5]
 *         J: [0,3,1,3,2]
 *     b: [0.2,0.1,-0.1,0.1]
 *     c :[1,-2,-3]
 *     K:
 *         eq: 0
 *         ep: 0
 *         q: 4
 *         f: 0
 *         l: 0
 *         s: []
 *         ed: 0
 *         p: []
 * ...
 * ~~~~~
 * 
 * \section superscs-yaml-matlab MATLAB
 * 
 * In MATLAB, you may serialize your problem using <code>problem_to_yaml</code>.
 * 
 * In MATLAB the data of a conic optimization problem are stored in a structure
 * called `data` with fields `A`, `b` and `c` and another structure called `K` 
 * containing the cone specifications. 
 * 
 * To save the contents of `data` and `K` in `my_problem.yml` run:
 * 
 * ~~~~~
 * problem_to_yaml('my_problem.yml', 'problem-1', data, K);
 * ~~~~~
 * 
 * To print the YAML-serialized problem data to the standard output run:
 * 
 * ~~~~~
 * problem_to_yaml(1, 'problem-1', data, K);
 * ~~~~~
 * 
 * To print the YAML representation to some other output stream, e.g., a stream 
 * to a file created using `fopen` run:
 * 
 * ~~~~~
 * fid = fopen('path/to/myfile.yml', 'w');
 * problem_to_yaml(fid, 'problem-1', data, K);
 * fclose(fid);
 * ~~~~~
 * 
 * Retrieving data from a YAML file is as simple as
 * 
 * ~~~~~
 * [data, K] = problem_from_yaml('example.yml');
 * ~~~~~
 * 
 * Here is a full example of saving and loading data:
 * 
 * ~~~~~
 * filename = 'example.yml';
 * data.A = sparse([0.3 0 0 ; 0 0.7 0; 0 0 0.2; -0.5 0.9 0]);  % define A
 * data.b = [0.2; 0.1; -0.1; 0.1];                             % define b
 * data.c = [1;-2;-3];                                         % define c
 * K.eq = 0; K.ep = 0; K.q = 4;                                % define K
 * problem_to_yaml(filename, 'test-problem-1', data, K);       % save data
 * [data_loaded, K_loaded] = problem_from_yaml(filename);      % load data
 * ~~~~~
 * 
 * \sa \ref page_sparse_matrices
 */