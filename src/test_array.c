#include "test_array.h"
#include "array.h"
#include <assert.h>
#include <stdio.h>

void test_initialize() {
    DynamicArray *dy_arr = initialize(10);
    assert(dy_arr->size == 0);
    assert(dy_arr->capacity == 10);
    printf("test_initialize \033[0;32mPASSED.\033[0m\n");
};
void test_insert(){};
