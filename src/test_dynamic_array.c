#include "test_dynamic_array.h"
#include "dynamic_array.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define POS 4
#define VALUE 1245235

int initial_values[] = {121, 242, 363, 484, 5105, 6126};
size_t initial_size = sizeof(initial_values) / sizeof(initial_values[0]);
 afssdgskjgah size_t




 im just typing a madness

void test_initialize() {
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    assert(dy_arr.size == initial_size);
    assert(dy_arr.capacity == (size_t)(GROWTH_FACTOR * initial_size));
    assert(dy_arr.data[0] == 121);
    assert(dy_arr.data[1] == 242);
    assert(dy_arr.data[2] == 363);
    assert(dy_arr.data[5] == 6126);
    puts("test_initialize \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_set_at() {
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    set_at(&dy_arr, POS, VALUE);

    assert(dy_arr.data[POS] == VALUE);
    puts("test_set_at \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_get_at() {
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    set_at(&dy_arr, POS, VALUE);

    assert(get_at(&dy_arr, POS) == VALUE);
    puts("test_get_at \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_insert_at() {
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    insert_at(&dy_arr, POS, VALUE);

    assert(dy_arr.data[POS] == VALUE);
    assert(dy_arr.size == initial_size + 1);
    assert(dy_arr.size < dy_arr.capacity);
    puts("test_insert_at \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_insert_at_1() {
    // when initial_size is 0
    DynamicArray dy_arr = initialize(NULL, 0);

    insert_at(&dy_arr, 0, VALUE);

    assert(dy_arr.data[0] == VALUE);
    assert(dy_arr.size == 1);
    assert(dy_arr.capacity == 1);
    puts("test_insert_at_1 \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_insert_at_2() {
    // insert something in front of the first element
    int pos = 0;
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    int old_value = initial_values[pos];

    insert_at(&dy_arr, pos, VALUE);

    assert(dy_arr.data[pos] == VALUE);
    assert(dy_arr.data[pos + 1] == old_value);
    assert(dy_arr.size == initial_size + 1);
    assert(dy_arr.size < dy_arr.capacity);
    puts("test_insert_at_2 \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_insert_at_3() {
    // insert something after the last element
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    int pos = initial_size;
    insert_at(&dy_arr, pos, VALUE);

    assert(dy_arr.data[pos] == VALUE);
    assert(dy_arr.size == initial_size + 1);
    assert(dy_arr.size < dy_arr.capacity);
    puts("test_insert_at_3 \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_delete_last() {
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    delete_last(&dy_arr);

    assert(dy_arr.size == initial_size - 1);
    puts("test_delete_last \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_delete_last_1() {
    // when dy_arr is empty
    DynamicArray dy_arr = initialize(NULL, 0);
    delete_last(&dy_arr);

    assert(dy_arr.size == 0);
    puts("test_delete_last_1 \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_delete_first() {
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    delete_first(&dy_arr);

    assert(dy_arr.size == initial_size - 1);
    assert(dy_arr.data[0] == initial_values[1]);
    puts("test_delete_first \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_delete_first_1() {
    // when dy_arr is empty
    DynamicArray dy_arr = initialize(NULL, 0);
    delete_first(&dy_arr);
    assert(dy_arr.size == 0);
    puts("test_delete_first_1 \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_delete_at() {
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    int next_value = dy_arr.data[POS + 1];
    delete_at(&dy_arr, POS);

    assert(dy_arr.size == initial_size - 1);
    assert(dy_arr.data[POS] == next_value);
    puts("test_delete_at \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_delete_at_1() {
    // when position is 0
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    int pos = 0;
    int next_value = dy_arr.data[pos + 1];
    delete_at(&dy_arr, pos);

    assert(dy_arr.size == initial_size - 1);
    assert(dy_arr.data[pos] == next_value);
    puts("test_delete_at_1 \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_delete_at_2() {
    // when position is size
    DynamicArray dy_arr = initialize(initial_values, initial_size);
    int pos = initial_size;
    int prev_value = dy_arr.data[dy_arr.size - 1];
    delete_at(&dy_arr, pos);

    assert(dy_arr.size == initial_size - 1);
    assert(dy_arr.data[dy_arr.size] == prev_value);
    puts("test_delete_at_2 \033[0;32mPASSED.\033[0m");
    free(dy_arr.data);
};

void test_dynamic_array() {
    test_initialize();
    test_set_at();
    test_get_at();
    test_insert_at();
    test_insert_at_1();
    test_insert_at_2();
    test_insert_at_3();
    test_delete_last();
    test_delete_last_1();
    test_delete_first();
    test_delete_first_1();
    test_delete_at();
    test_delete_at_1();
    test_delete_at_2();
};
