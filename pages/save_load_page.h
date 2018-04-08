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
 * problem:
 *   name: 'test-problem-01'
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
 * ~~~~~
 * 
 * \section superscs-yaml-matlab MATLAB
 * 
 * In MATLAB, you may serialize your problem using <code>problem_to_yaml</code>.
 * 
 * \sa \ref page_sparse_matrices
 */