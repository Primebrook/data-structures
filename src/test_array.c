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

void test_insert() {
    int initial_size = 8;
    DynamicArray *dy_arr = initialize(10, initial_size);
    int pos = 5;
    int value = 5000;

    DynamicArray *modified_dy_arr = insert(dy_arr, pos, value);

    assert(modified_dy_arr->size == initial_size + 1);
    assert(modified_dy_arr->data[pos] == value);
    puts("test_insert \033[0;32mPASSED.\033[0m");
};

void test_insert_at_capacity() {
    int capacity = 10;
    DynamicArray *dy_arr = initialize(capacity, capacity);
    int pos = 5;
    int value = 5000;

    DynamicArray *modified_dy_arr = insert(dy_arr, pos, value);

    assert(modified_dy_arr->size == capacity + 1);
    assert(modified_dy_arr->data[pos] == value);
    puts("test_insert_at_capacity \033[0;32mPASSED.\033[0m");
};

void test_insert_when_pos_greater_than_capacity() {
    int initial_capacity = 10;
    int initial_size = 8;
    DynamicArray *dy_arr = initialize(initial_capacity, initial_size);
    int pos = 15;
    int value = 15000;

    DynamicArray *modified_dy_arr = insert(dy_arr, pos, value);

    assert(modified_dy_arr->capacity = pos);
    assert(modified_dy_arr->data[pos] == value);
    puts("test_insert_when_pos_greater_than_capacity \033[0;32mPASSED.\033[0m");
};

void test_array() {
    test_empty_initialize();
    test_initialize_at_capacity();
    test_insert();
    test_insert_at_capacity();
    test_insert_when_pos_greater_than_capacity();
};
