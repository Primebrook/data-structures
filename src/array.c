#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GROWTH_FACTOR 2 // The factor by which the capacity will increase

// Initialize a dynamic array with the given initial capacity and data type
DynamicArray *initialize(int initial_capacity, DataType type) {
    DynamicArray *dy_arr_ptr = malloc(sizeof(DynamicArray));
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Failed to allocate memory for dynamic array.\n");
        exit(EXIT_FAILURE);
    }

    dy_arr_ptr->data = malloc(initial_capacity * getDataTypeSize(type));
    if (dy_arr_ptr->data == NULL) {
        free(dy_arr_ptr);
        fprintf(stderr, "Failed to allocate memory for dynamic array data.\n");
        exit(EXIT_FAILURE);
    }

    dy_arr_ptr->size = 0;
    dy_arr_ptr->capacity = initial_capacity;
    dy_arr_ptr->type = type;
    return dy_arr_ptr;
}

// Resize the dynamic array to the new capacity
void resize(DynamicArray *dy_arr_ptr, size_t new_capacity) {
    void *new_data = realloc(dy_arr_ptr->data, new_capacity * getDataTypeSize(dy_arr_ptr->type));
    if (new_data == NULL) {
        fprintf(stderr, "Failed to resize dynamic array.\n");
        exit(EXIT_FAILURE);
    }
    dy_arr_ptr->data = new_data;
    dy_arr_ptr->capacity = new_capacity;
}

// Add a value to the dynamic array
void add(DynamicArray *dy_arr_ptr, void *value) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    if (dy_arr_ptr->size == dy_arr_ptr->capacity) {
        // Array is full, resize it
        size_t new_capacity = dy_arr_ptr->capacity * GROWTH_FACTOR;
        resize(dy_arr_ptr, new_capacity);
    }

    if (dy_arr_ptr->size < dy_arr_ptr->capacity) {
        size_t element_size = getDataTypeSize(dy_arr_ptr->type);
        void *destination = (char *)dy_arr_ptr->data + dy_arr_ptr->size * element_size;
        memcpy(destination, value, element_size);
        dy_arr_ptr->size++;
    } else {
        fprintf(stderr, "Array overflow.\n");
        exit(EXIT_FAILURE);
    }
}

// Get the value at the specified index
void* get(DynamicArray *dy_arr_ptr, size_t index) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    if (index >= 0 && index < dy_arr_ptr->size) {
        size_t element_size = getDataTypeSize(dy_arr_ptr->type);
        void *value_ptr = (char *)dy_arr_ptr->data + index * element_size;
        return value_ptr;
    } else {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
}

// ... (Other functions remain the same)

int main() {
    DynamicArray *intArray = initialize(10, INT);
    DynamicArray *floatArray = initialize(10, FLOAT);
    DynamicArray *doubleArray = initialize(10, DOUBLE);
    DynamicArray *charArray = initialize(10, CHAR);

    int intValue = 42;
    float floatValue = 3.14f;
    double doubleValue = 2.71828;
    char charValue = 'A';

    add(intArray, &intValue);
    add(floatArray, &floatValue);
    add(doubleArray, &doubleValue);
    add(charArray, &charValue);

    printf("Int value at index 0: %d\n", *(int *)get(intArray, 0));
    printf("Float value at index 0: %f\n", *(float *)get(floatArray, 0));
    printf("Double value at index 0: %lf\n", *(double *)get(doubleArray, 0));
    printf("Char value at index 0: %c\n", *(char *)get(charArray, 0));

    destroy(intArray);
    destroy(floatArray);
    destroy(doubleArray);
    destroy(charArray);

    return 0;
}
