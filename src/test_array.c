#include <check.h>
#include "array.h"

// This is a test setup function that will be called before each test
void setup(void) {}

// This is a test teardown function that will be called after each test
void teardown(void) {}

// Sample test case
START_TEST(test_dynamic_array_creation) {
    DynamicArray *arr = initialize(INITIAL_CAPACITY, INT);
    ck_assert_ptr_nonnull(arr);
    ck_assert_int_eq(size(arr), 0);
    ck_assert_int_eq(arr->capacity, INITIAL_CAPACITY);
    ck_assert_int_eq(arr->type, INT);
    destroy(arr);
}
END_TEST

// Add more test cases as needed

int main(void) {
    Suite *s;
    SRunner *runner;
    int number_failed;

    s = suite_create("DynamicArray");
    TCase *tc_core = tcase_create("Core");
    
    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, test_dynamic_array_creation);
    // Add more test cases to the core test case

    suite_add_tcase(s, tc_core);

    runner = srunner_create(s);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
