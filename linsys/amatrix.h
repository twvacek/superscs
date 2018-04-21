#ifndef AMATRIX_H_GUARD
#define AMATRIX_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

/* this struct defines the data matrix A */
    
    /**
     * \brief The sparse matrix A of the conic optimization problem.
     * 
     * The data are stored in \ref page_sparse_matrices "CSC format".
     * 
     * \sa \ref page_sparse_matrices "Sparse matrices documentation"
     */
struct scs_a_data_matrix {
    /* A is supplied in column compressed format */
    /**
     * \brief Values of \c A
     */
    scs_float *x; /* A values, size: NNZ A */
    /**
     * \brief The row-index of the matrix (\f$J\f$). 
     * 
     * An array of length equal to the number of nonzero elements of \c A.
     */
    scs_int *i;
    /**
     * \brief  Array of column pointers of A in \ref page_sparse_matrices "CSC format"
     * (\f$I\f$).
     * 
     * The length of <code>A->p</code> is equal to <code>A->n + 1</code>.
     * 
     */
    scs_int *p;
    /**
     * \brief  Number of rows (\f$m\f$).
     */
    scs_int m;
    /**
     * \brief  Number of columns (\f$n\f$).
     */
    scs_int n; 
};

#ifdef __cplusplus
}
#endif
#endif
