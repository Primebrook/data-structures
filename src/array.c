#include "array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray *initialize(int initial_capacity, int initial_size) {
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

DynamicArray *insert(DynamicArray *dy_arr, int pos, int value) {
    if (pos > dy_arr->capacity) {
        // DynamicArray* resized_dy_arr = resize(dy_arr, size);
    };

    if (dy_arr->size == dy_arr->capacity) {
        int resized = resize(dy_arr, dy_arr->capacity + 1);
        if (resized == 0) {
            fprintf(stderr, "Failed to reallocate memory for resizing.\n");
            exit(EXIT_FAILURE);
        };
    };

    for (int i = dy_arr->size; i >= pos; i--) {
        dy_arr->data[i + 1] = dy_arr->data[i];
    };

    dy_arr->data[pos] = value; // actual insertion!
    dy_arr->size++;
    return dy_arr;
};

int resize(DynamicArray *dy_arr, int new_capacity) {
    int *new_data = realloc(dy_arr->data, sizeof(int) * new_capacity);
    if (new_data == NULL) {
        return 0;
    };

    dy_arr->data = new_data;
    dy_arr->capacity = new_capacity;
    return 1;
};

// int *resize(int *data, int size) {
//     int *new_data = (int *)realloc(data, sizeof(int) * (size + 1));
//     if (new_data == NULL) {
//         fprintf(stderr, "Failed to reallocate memory fo dynamic array
//         data.\n"); exit(EXIT_FAILURE);
//     };
//     return new_data;
// };
