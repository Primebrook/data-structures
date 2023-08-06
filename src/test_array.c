#include "test_array.h"
#include "array.h"
#include <assert.h>
#include <stdio.h>

void test_initialize() {
    size_t initial_capacity = 10;
    DynamicArray dy_arr = initialize(initial_capacity);
    assert(dy_arr.size == 0);
    assert(dy_arr.capacity == initial_capacity);
    puts("test_initialize \033[0;32mPASSED.\033[0m");
};

void test_set_at() {
    size_t initial_capacity = 10;
    DynamicArray dy_arr = initialize(initial_capacity);

    size_t pos = 0;
    int value = 3246;
    set_at(&dy_arr, pos, value);

    assert(dy_arr.data[pos] = value);
    puts("test_set_at \033[0;32mPASSED.\033[0m");
};

void test_array() {
    test_initialize();
    test_set_at();
};
