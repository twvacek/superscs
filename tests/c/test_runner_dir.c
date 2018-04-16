#include "test_runner_dir.h"
#include "test_superscs.h"
#include "linsys/indirect/private.h"

int main(int argc, char** argv) {
    int r;
    number_of_assertions = 0;

    printf("\n***** Test Results *****\n\n");

    r = TEST_SUCCESS;

    /* Test functions: */
    r += scs_test(&test_dummy_method, "Dummy passing test");
    r += scs_test(&test_problem_metadata, "Metadata");
    r += scs_test(&test_serialize_YAML, "Saving to YAML");
    r += scs_test(&test_serialize_YAML_no_metadata, "Saving to YAML (no meta)");
    r += scs_test(&test_copy_YAML, "Copying YAML");
    r += scs_test(&test_parse_YAML, "Reading from YAML");
    r += scs_test(&test_parse_YAML_2, "YAML with qsize=2");
    r += scs_test(&test_parse_YAML_3, "YAML with ssize=2");
    r += scs_test(&test_SDP_from_YAML, "Solve SDP from YAML");
    r += scs_test(&test_logreg_from_YAML, "Solve logreg from YAML");
    r += scs_test(&test_power_from_YAML, "Solve power cone problem from YAML");
    r += scs_test(&test_exponential_unbdd_from_YAML, "Solve exp cone problem from YAML");
    r += scs_test(&test_overtime_stop, "Stop on overtime");
    r += scs_test(&test_superscs_with_anderson, "Test SuperSCS with Anderson's accel.");
    r += scs_test(&test_superscs_011_progress, "Test SuperSCS (0,1,1) thoroughly");
    r += scs_test(&testscs_millis_to_time, "Milliseconds to time");
    r += scs_test(&testAxpy2, "AXPY2");
    r += scs_test(&testUnrolledDot, "Unrolled dot");
    r += scs_test(&testscs_subtract_array, "Unrolled subtraction");
    r += scs_test(&testNormDifference, "Norm of difference");
    r += scs_test(&testProjLinSysv2, "Test projLinSysv2");
    r += scs_test(&testCglsSquareMatrix, "Test CGLS");
    r += scs_test(&testCglsTallMatrix, "Test CGLS with tall matrix");
    r += scs_test(&testCglsFatMatrix, "Test CGLS with fat matrix");
    r += scs_test(&testQrLsTallMatrix, "QR-based least squares (tall)");
    r += scs_test(&testSvdLsTallMatrix, "SVD-based least squares (tall)");
    r += scs_test(&testSvdLsRankDeficient, "SVD-based least squares (rank def.)");
    r += scs_test(&testscs_scale_array, "Test scs_scale_array");
    r += scs_test(&testGemm, "Test GEMM");
    r += scs_test(&testGemmCP, "Test GEMM/CP");
    r += scs_test(&testGemmTransCP, "Test GEMM/Tran/CP");
    r += scs_test(&test_cache_increments, "Test Restarted Broyden cache");
    r += scs_test(&test_broyden_direction_empty_memory, "Test Restarted Broyden direction");
    r += scs_test(&test_full_broyden, "Test full Broyden");
    r += scs_test(&test_cache_s, "Test Broyden S-Cache");
    r += scs_test(&test_broyden, "Test Broyden dir correctness");
    r += scs_test(&test_superscs_solve, "Test SuperSCS");
    r += scs_test(&test_superscs_000, "Test SuperSCS (0,0,0)");
    r += scs_test(&test_superscs_001_fpr, "Test SuperSCS (0,0,1) with FPR");
    r += scs_test(&test_superscs_001_rbroyden, "Test SuperSCS (0,0,1) with R-Broyden");
    r += scs_test(&test_superscs_100_rbroyden, "Test SuperSCS (1,0,0) with R-Broyden");
    r += scs_test(&test_residuals, "Test residuals");
    r += scs_test(&test_rho_x, "Test rho_x");
    r += scs_test(&test_validation, "Test validation");
    r += scs_test(&test_no_normalization, "Test SuperSCS unnormalized");
    r += scs_test(&test_warm_start, "Test SuperSCS warm_start");
    r += scs_test(&test_scale, "Test SuperSCS scalings");
    printf("\nTotal assertions: %d\n", number_of_assertions);
    if (r == TEST_SUCCESS) {
        printf("\n~ All tests passed\n\n");
        return (EXIT_SUCCESS);
    } else {
        printf("\n~ %d Tests Failed\n\n", r);
        return (EXIT_FAILURE);
    }

}