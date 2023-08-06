#include "array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray initialize(size_t initial_capacity) {
    DynamicArray dy_arr;

    dy_arr.data = (int *)malloc(initial_capacity * sizeof(int));
    if (dy_arr.data == NULL) {
        fprintf(stderr,
                "Failed to allocation memory for dynamic array data.\n");
        exit(EXIT_FAILURE);
    };

    dy_arr.size = 0;
    dy_arr.capacity = initial_capacity;
    return dy_arr;
};
