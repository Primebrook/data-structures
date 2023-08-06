#include "array.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

DynamicArray initialize(size_t initial_capacity, size_t initial_size) {
	if (initial_size > initial_capacity){
		fprintf(stderr, "Initial size cannot be greater than initial capacity.\n");
		exit(EXIT_FAILURE);
	}
    DynamicArray dy_arr;

    dy_arr.data = calloc(initial_size, sizeof(int));
    if (dy_arr.data == NULL) {
        fprintf(stderr,
                "Failed to allocation memory for dynamic array data.\n");
        exit(EXIT_FAILURE);
    };

    dy_arr.size = initial_size;
    dy_arr.capacity = initial_capacity;
    return dy_arr;
};

void set_at(DynamicArray *dy_arr, size_t pos, int value) {
    assert(dy_arr); // come back to this: is this defo needed?
    assert(dy_arr->data);

    if (pos >= dy_arr->size) {
        fprintf(stderr, "Specified index is greater than size. \n");
        return;
    };
    dy_arr->data[pos] = value;
};
