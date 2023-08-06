#include "test_dynamic_array.h"
#include "dynamic_array.h"
#include <assert.h>
#include <stdio.h>

#define INITIAL_CAPACITY 10
#define INITIAL_SIZE 5
#define POS 4
#define VALUE 1245235

void test_initialize() {
    DynamicArray dy_arr = initialize(INITIAL_CAPACITY, INITIAL_SIZE);
    assert(dy_arr.size == INITIAL_SIZE);
    assert(dy_arr.capacity == INITIAL_CAPACITY);
    puts("test_initialize \033[0;32mPASSED.\033[0m");
};

void test_set_at() {
    DynamicArray dy_arr = initialize(INITIAL_CAPACITY, INITIAL_SIZE);
    set_at(&dy_arr, POS, VALUE);

    assert(dy_arr.data[POS] == VALUE);
    puts("test_set_at \033[0;32mPASSED.\033[0m");
};

void test_get_at() {
    DynamicArray dy_arr = initialize(INITIAL_CAPACITY, INITIAL_SIZE);
    set_at(&dy_arr, POS, VALUE);

    assert(get_at(&dy_arr, POS) == VALUE);
    puts("test_get_at \033[0;32mPASSED.\033[0m");
};

void test_dynamic_array() {
    test_initialize();
    test_set_at();
    test_get_at();
};
