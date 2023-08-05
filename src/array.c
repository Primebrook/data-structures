#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GROWTH_FACTOR 2 // The factor by which the capacity will increase

// Initialize a dynamic array with the given initial capacity
DynamicArray *initialize(int initial_capacity) {
    DynamicArray *dy_arr_ptr = malloc(sizeof(DynamicArray));
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Failed to allocate memory for dynamic array.\n");
        exit(EXIT_FAILURE);
    }

    dy_arr_ptr->data = (int *)malloc(initial_capacity * sizeof(int));
    if (dy_arr_ptr->data == NULL) {
        free(dy_arr_ptr);
        fprintf(stderr,
                "Failed to allocate memory for dynamic array data.\n");
        exit(EXIT_FAILURE);
    }

    dy_arr_ptr->size = 0;
    dy_arr_ptr->capacity = initial_capacity;
    return dy_arr_ptr;
}

// Resize the dynamic array to the new capacity
void resize(DynamicArray *dy_arr_ptr, int new_capacity) {
    int *new_data = (int *)realloc(dy_arr_ptr->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "Failed to resize dynamic array.\n");
        exit(EXIT_FAILURE);
    }
    dy_arr_ptr->data = new_data;
    dy_arr_ptr->capacity = new_capacity;
}

// Add a value to the dynamic array
void add(DynamicArray *dy_arr_ptr, int value) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    if (dy_arr_ptr->size == dy_arr_ptr->capacity) {
        // Array is full, resize it
        int new_capacity = dy_arr_ptr->capacity * GROWTH_FACTOR;
        resize(dy_arr_ptr, new_capacity);
    }

    if (dy_arr_ptr->size < dy_arr_ptr->capacity) {
        dy_arr_ptr->data[dy_arr_ptr->size] = value;
        dy_arr_ptr->size++;
    } else {
        fprintf(stderr, "Array overflow.\n");
        exit(EXIT_FAILURE);
    }
}

// Get the value at the specified index
int get(DynamicArray *dy_arr_ptr, int index) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    if (index >= 0 && index < dy_arr_ptr->size) {
        return dy_arr_ptr->data[index];
    } else {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
}

// Set the value at the specified index
void set(DynamicArray *dy_arr_ptr, int index, int value) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    if (index >= 0 && index < dy_arr_ptr->size) {
        dy_arr_ptr->data[index] = value;
    } else {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
}

// Get the current size of the dynamic array
int size(DynamicArray *dy_arr_ptr) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    return dy_arr_ptr->size;
}

// Clear the dynamic array (set size to 0)
void clear(DynamicArray *dy_arr_ptr) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    dy_arr_ptr->size = 0;
}

// Destroy the dynamic array and free memory
void destroy(DynamicArray *dy_arr_ptr) {
    if (dy_arr_ptr != NULL) {
        free(dy_arr_ptr->data);
        free(dy_arr_ptr);
    }
}
