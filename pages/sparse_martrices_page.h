/*! \page page_sparse_matrices Sparse Matrices
 * 
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
 */