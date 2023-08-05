#include "array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray *initialize(int initial_capacity, int initial_size) {
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

    dy_arr_ptr->size = initial_size;
    dy_arr_ptr->capacity = initial_capacity;
    return dy_arr_ptr;
};

DynamicArray *insert(DynamicArray *dy_arr, int pos, int value) {
    if (dy_arr->size == dy_arr->capacity) {
        int *new_data = resize(dy_arr->data, 1);
        dy_arr->data = new_data;
    };

    for (int i = dy_arr->size; i >= pos; i--) {
        dy_arr->data[i + 1] = dy_arr->data[i];
    };

    dy_arr->data[pos] = value; // actual insertion!
    dy_arr->size++;
    return dy_arr;
};

int *resize(int *data, int size) {
    int *new_data = (int *)realloc(data, sizeof(int) * (size + 1));
    if (new_data == NULL) {
        fprintf(stderr, "Failed to reallocate memory fo dynamic array data.\n");
        exit(EXIT_FAILURE);
    };
    return new_data;
};
