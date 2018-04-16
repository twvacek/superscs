#include "test_dummy.h"

bool test_dummy_method(char** str) {
    if (scs_assert_equals_int(1, 1)) {
        SUCCEED(str);
    } else {
        FAIL_WITH_MESSAGE(str, "failure");
    }
}