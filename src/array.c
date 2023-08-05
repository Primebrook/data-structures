#include "array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray *initialize(int initial_capacity) {
    DynamicArray *dy_arr_ptr = malloc(sizeof(DynamicArray));

    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Failed to allocate memory for dynamic array.\n");
        exit(EXIT_FAILURE);
    };

    dy_arr_ptr->data = (int *)malloc(initial_capacity * sizeof(int));
    if (dy_arr_ptr->data == NULL) {
        free(dy_arr_ptr);
        fprintf(stderr,
                "Failed to allocation memory for dynamic array data.\n");
        exit(EXIT_FAILURE);
    };

    dy_arr_ptr->size = 0;
    dy_arr_ptr->capacity = initial_capacity;
    return dy_arr_ptr;
};

DynamicArray *insert(DynamicArray *dy_arr, int pos, int value) {
    return dy_arr;
};
