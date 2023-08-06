#include "test_array.h"
#include "array.h"
#include <assert.h>
#include <stdio.h>

void test_empty_initialize() {
    DynamicArray *dy_arr = initialize(10, 0);
    assert(dy_arr->size == 0);
    assert(dy_arr->capacity == 10);
    puts("test_empty_initialize \033[0;32mPASSED.\033[0m");
};

void test_initialize_at_capacity() {
    int capacity = 10;
    DynamicArray *dy_arr = initialize(capacity, capacity);
    assert(dy_arr->capacity == capacity);
    assert(dy_arr->size == capacity);
    puts("test_initialize_at_capacity \033[0;32mPASSED.\033[0m");
};

//void test_get_at() {
//	int initial_capacity = 10;
//	int initial_size = 5;
//	DynamicArray *dy_arr = initialize(initial_capacity, initial_size);
//	get_at(i)
//};
//
void test_array() {
    test_empty_initialize();
    test_initialize_at_capacity();
};
