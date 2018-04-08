/*! \page page_sparse_matrices Sparse Matrices
 * 
 * \tableofcontents
 * 
 * \section csc-format CSC format
 * Sparse matrix in C are formated in the 
 * <a href="https://en.wikipedia.org/wiki/Sparse_matrix#Compressed_sparse_column_(CSC_or_CCS)">
 * compressed sparse column format</a>.
 * 
 * Let \f$A\in\mathbb{R}^{m\times n}\f$ be a sparse matrix with \f$q\f$ nonzero
 * elements.
 * 
 * The compressed sparse column, henceforth CSC, representation of \f$A\f$ is
 * the triplet \f$(a, I, J)\f$ where 
 * 
 * - \f$a\f$ is an array of length \f$q\f$ with the nonzero entries of \f$A\f$ in 
 *    column-major order,
 * - \f$I\f$ is an array of length \f$n+1\f$ defined recursively in the following 
 *    fashion
 *      - \f$I_0 = 0\f$
 *      - \f$I_{k+1} = I_{k} + \text{nonzeros in } k\text{-th column of } A\f$
 * - \f$J\f$ contains the row indices of the nonzero elements in \f$A\f$.
 * 
 * Let us give a comprehensive example...
 * 
 * Consider the following sparse matrix 
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
 * We shall derive the CSC representation of \f$A\f$.
 * 
 * We have \f$m=4\f$, \f$n=3\f$ and we count \f$q=5\f$ nonzero elements.
 * 
 * Traversing \f$A\f$ in column-major order, we have \f$a = (0.3, -0.5, 0.7, 0.9, 0.2)\f$.
 * 
 * \f$I\f$ is an array of length \f$n+1=4\f$; it is constructed recursively as follows:
 * - \f$I_0=0\f$
 * - \f$I_1=I_0 + \text{nonzeros in first column} = I_0 + 2 = 2\f$
 * - \f$I_2=I_1 + \text{nonzeros in second column} = I_1 + 2 = 4\f$
 * - \f$I_3=I_1 + \text{nonzeros in second column} = I_2 + 1 = 5\f$
 * 
 * Note that the last element of \f$I\f$ is the number of nonzero elements of
 * the original matrix.
 * 
 * Lastly, \f$J\f$ is constructed as follows:
 * - \f$J_0 = \text{row coordinate of }a_0 = 0\f$
 * - \f$J_1 = \text{row coordinate of }a_1 = 3\f$
 * - \f$J_2 = \text{row coordinate of }a_2 = 1\f$
 * - \f$J_3 = \text{row coordinate of }a_3 = 3\f$
 * - \f$J_4 = \text{row coordinate of }a_4 = 2\f$
 * 
 * 
 * 
 * \section matlab-to-csc Exporting to CSC in MATLAB
 * SuperSCS implements the MATLAB function <code>sparse_to_csc</code> with which 
 * you may convert a sparse matrix into its CSC format.
 * 
 * The function signature is:
 * 
 * ~~~~~
 * [m, n, nnz, a, jc, ir] = sparse_to_csc(A);
 * ~~~~~
 * 
 * Note that you first need to run <code>make_scs</code> (see the 
 * \ref page_installation "installation page").
 * 
 * Here is an example of use:
 * 
 * ~~~~~
 * A = [0.3 0 0 ; 0 0.7 0; 0 0 0.2; -0.5 0.9 0];
 * A = sparse(A);
 * [m, n, nnz, a, jc, ir] = sparse_to_csc(A);
 * ~~~~~
 * 
 * This will return:
 * 
 * ~~~~~
 * m = 4
 * n = 3
 * nnz = 5
 * a =
 *     0.3000
 *    -0.5000
 *     0.7000
 *     0.9000
 *     0.2000
 * 
 * jc =
 *      0
 *      2
 *      4
 *      5
 * 
 * ir = 
 *      0
 *      3
 *      1
 *      3
 *      2
 * ~~~~~
 * 
 * \sa \ref page_save_load
 *  
 */