#include "array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray *initialize(size_t initial_capacity, size_t initial_size) {
    DynamicArray *dy_arr = malloc(sizeof(DynamicArray));

    if (dy_arr == NULL) {
        fprintf(stderr, "Failed to allocate memory for dynamic array.\n");
        exit(EXIT_FAILURE);
    };

    dy_arr->data = (int *)malloc(initial_capacity * sizeof(int));
    if (dy_arr->data == NULL) {
        free(dy_arr);
        fprintf(stderr,
                "Failed to allocation memory for dynamic array data.\n");
        exit(EXIT_FAILURE);
    };

    dy_arr->size = initial_size;
    dy_arr->capacity = initial_capacity;
    return dy_arr;
};

