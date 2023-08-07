#include "dynamic_array.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DynamicArray initialize(int *initial_values, size_t initial_size) {
    size_t initial_capacity = GROWTH_FACTOR * initial_size;

    DynamicArray dy_arr;
    dy_arr.data = malloc(initial_capacity * sizeof(int));
    if (dy_arr.data == NULL) {
        fprintf(stderr,
                "Failed to allocation memory for dynamic array data.\n");
        exit(EXIT_FAILURE);
    };
    memcpy(dy_arr.data, initial_values, initial_size * sizeof(int));

    dy_arr.size = initial_size;
    dy_arr.capacity = initial_capacity;
    return dy_arr;
};

void set_at(DynamicArray *dy_arr, size_t pos, int value) {
    assert(dy_arr); // come back to this: is this defo needed?
    assert(dy_arr->data);

    if (pos >= dy_arr->size) {
        fprintf(stderr, "Specified index is greater than size.\n");
        return;
    };
    dy_arr->data[pos] = value;
};

int get_at(DynamicArray *dy_arr, size_t pos) {
    if (pos >= dy_arr->size) {
        fprintf(stderr, "Specified index is greater than size.\n");
        exit(EXIT_FAILURE);
    };
    return dy_arr->data[pos];
};

void iter_seq(DynamicArray *dy_arr) {
    for (size_t i = 0; i < dy_arr->size; i++) {
        printf("%d", dy_arr->data[i]);
    };
};

void insert_at(DynamicArray *dy_arr, size_t pos, int value) {
    if (dy_arr->size >= dy_arr->capacity) {
        resize(dy_arr);
    };

    if (pos > dy_arr->size) {
        fprintf(stderr,
                "Specified index is greater than current array size.\n");
        exit(EXIT_FAILURE);
    };

    memmove(dy_arr->data + pos + 1, dy_arr->data + pos,
            sizeof(int) * (dy_arr->size - pos));
    dy_arr->size = dy_arr->size + 1;
    set_at(dy_arr, pos, value);
};

void resize(DynamicArray *dy_arr) {
    size_t new_capacity = GROWTH_FACTOR * dy_arr->capacity + 1;
    dy_arr->capacity = new_capacity;

    int *new_data = realloc(dy_arr->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "Memory reallocation for resize unsuccessful.\n");
        exit(EXIT_FAILURE);
    };
    dy_arr->data = new_data;
};

void delete_last(DynamicArray *dy_arr) {
    dy_arr->size -= !!(dy_arr->size); // double bang FTW!
};
