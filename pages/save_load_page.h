/*! \page page_save_load Saving and Loading Problems
 * 
 * \section superscs-yaml-format SuperSCS YAML format
 * 
 * A conic problem is described by the tuple \f$(A,b,c,\mathcal{K})\f$ where \f$A\f$
 * is an \f$m\times n\f$ \ref page_sparse_matrices "sparse matrix" and 
 * \f$\mathcal{K}\f$ is a cone.
 * 
 * These data can be saved in a YAML file from which they can be accessed
 * from MATLAB, C, R, Java, Python and any other programming language.
 * 
 * YAML files are easy to parse and are human- and machine-readable.
 * 
 * ~~~~~{.yaml}
 * problem:
 *   name: 'p1'
 *   A: 
 *     m: 4
 *     n: 3
 *     nnz: 5
 *     a:
 *       - 0.3
 *       - -0.5
 *       - 0.7
 *       - 0.9
 *       - 0.2
 *     j:
 *       - 0
 *       - 2
 *       - 4
 *       - 5
 *     i:
 *       - 0
 *       - 3
 *       - 1
 *       - 3
 *       - 2
 *   b:
 *     - 0.2
 *     - 0.1
 *     - -0.1
 *     - 0.1
 *   c:
 *     - 1
 *     - -2
 *     - -3
 *   K:
 *     q: 4
 *     ed: 0
 *     eq: 0
 *     ep: 0
 * ~~~~~
 * 
 * \section superscs-yaml-matlab MATLAB
 * 
 * In MATLAB, you may serialize your problem using <code>problem_to_yaml</code>.
 */