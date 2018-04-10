#include "mex.h"
#include <string.h>

/* -----------------------------------------
 * Template:
 * [m, n, nnz, a, I, J] = sparse_to_csc(S)
 * ----------------------------------------- */
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    const mxArray * inputMatrix ;
    mwSize num_rows;
    mwSize num_cols;
    mwSize num_nnz;
    mwIndex *irs;
    mwIndex *jcs;
    double * pr;
    size_t i;
    
    if (nrhs!=1){
        mexErrMsgIdAndTxt("SCS:nrhs", "this function requires exactly one input argument");
    }
    if (nlhs>6){
        mexErrMsgIdAndTxt("SCS:nlhs", "cannot return more than size output arguments");
    }
    
    /* Get the pointer of the input argument */
    inputMatrix = prhs [0];
    
    if (!mxIsSparse(inputMatrix)){
        mexErrMsgIdAndTxt("SCS:not_sparse", "the provided argument is not a sparse matrix");
    }
    
    if (nlhs != 6) {
        mexWarnMsgIdAndTxt ("SCS:nlhs",
                "you should rather call this function with six output arguments");        
    }
    if (nrhs == 0) {
        return;
    }
    
    num_rows = mxGetM(inputMatrix);
    num_cols = mxGetN(inputMatrix);
    num_nnz  = mxGetNzmax(inputMatrix);
    pr       = mxGetPr(inputMatrix);
    jcs      = mxGetIr(inputMatrix);
    irs      = mxGetJc(inputMatrix);
    
    
    if (nlhs >=1) {
        plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL );
        *mxGetPr(plhs[0]) = num_rows;
    }
    
    if (nlhs >=2) {
        plhs[1] = mxCreateDoubleMatrix(1, 1, mxREAL );
        *mxGetPr(plhs[1]) = num_cols;
    }
    
    if (nlhs >=3) {
        plhs[2] = mxCreateDoubleMatrix(1, 1, mxREAL );
        *mxGetPr(plhs[2]) = num_nnz;
    }
    
    if (nlhs >=4) {
        plhs[3] = mxCreateDoubleMatrix(num_nnz, 1, mxREAL );
        memcpy(mxGetPr(plhs[3]), pr, num_nnz * sizeof(double));
    }
    
    if (nlhs >= 5) {        
       plhs[4] = mxCreateDoubleMatrix(num_cols + 1, 1, mxREAL );
       for (i=0; i<num_cols + 1; ++i)
           mxGetPr(plhs[4])[i] = irs[i];
    }
    if (nlhs >= 6) {        
       plhs[5] = mxCreateDoubleMatrix(num_nnz, 1, mxREAL );
       for (i=0; i<num_nnz; ++i)
           mxGetPr(plhs[5])[i] = jcs[i];
    }

}