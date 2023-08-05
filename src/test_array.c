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
void test_insert() {
    DynamicArray *dy_arr = initialize(10);
    int pos = 5;
    int value = 5000;

    DynamicArray *modified_dy_arr = insert(dy_arr, pos, value);

    assert(dy_arr->size == 1);
    assert(dy_arr->data[5] == 5000);
};
