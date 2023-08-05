#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2 // The factor by which the capacity will increase

// Initialize a dynamic array with the given initial capacity and data type
DynamicArray *initialize(size_t initial_capacity, DataType type) {
    DynamicArray *dy_arr_ptr = malloc(sizeof(DynamicArray));
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for dynamic array.\n");
        exit(EXIT_FAILURE);
    }

    dy_arr_ptr->data = malloc(initial_capacity * getDataTypeSize(type));
    if (dy_arr_ptr->data == NULL) {
        free(dy_arr_ptr);
        fprintf(stderr, "Error: Failed to allocate memory for dynamic array data.\n");
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

// Helper function to check for NULL pointer and out-of-bounds index
void checkPointerAndIndex(DynamicArray *dy_arr_ptr, int index) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    if (dy_arr_ptr->data == NULL) {
        fprintf(stderr, "Dynamic array data pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    if (index >= dy_arr_ptr->size) {
        fprintf(stderr, "Index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
}

// Add a value to the dynamic array
void add(DynamicArray *dy_arr_ptr, void *value) {
    checkPointerAndIndex(dy_arr_ptr, dy_arr_ptr->size);

    if (dy_arr_ptr->size == dy_arr_ptr->capacity) {
        // Array is full, resize it
        size_t new_capacity = dy_arr_ptr->capacity * GROWTH_FACTOR;
        resize(dy_arr_ptr, new_capacity);
    }

    size_t element_size = getDataTypeSize(dy_arr_ptr->type);
    void *destination = (char *)dy_arr_ptr->data + dy_arr_ptr->size * element_size;
    memcpy(destination, value, element_size);
    dy_arr_ptr->size++;
}

// Get the value at the specified index
void* get(DynamicArray *dy_arr_ptr, int index) {
    checkPointerAndIndex(dy_arr_ptr, index);

    size_t element_size = getDataTypeSize(dy_arr_ptr->type);
    void *value_ptr = (char *)dy_arr_ptr->data + index * element_size;
    return value_ptr;
}

// Set the value at the specified index
void set(DynamicArray *dy_arr_ptr, int index, void *value) {
    checkPointerAndIndex(dy_arr_ptr, index);

    size_t element_size = getDataTypeSize(dy_arr_ptr->type);
    void *destination = (char *)dy_arr_ptr->data + index * element_size;
    memcpy(destination, value, element_size);
}

// Get the current size of the dynamic array
size_t size(DynamicArray *dy_arr_ptr) {
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

// Print the content of the dynamic array
void print(DynamicArray *dy_arr_ptr) {
    if (dy_arr_ptr == NULL) {
        fprintf(stderr, "Dynamic array pointer is NULL.\n");
        exit(EXIT_FAILURE);
    }

    size_t element_size = getDataTypeSize(dy_arr_ptr->type);
    printf("Dynamic Array Content:\n");

    for (size_t i = 0; i < dy_arr_ptr->size; ++i) {
        void *value_ptr = (char *)dy_arr_ptr->data + i * element_size;

        switch (dy_arr_ptr->type) {
            case INT:
                printf("%d ", *(int *)value_ptr);
                break;
            case FLOAT:
                printf("%f ", *(float *)value_ptr);
                break;
            case DOUBLE:
                printf("%lf ", *(double *)value_ptr);
                break;
            case CHAR:
                printf("%c ", *(char *)value_ptr);
                break;
            // Add cases for other data types if needed
        }
    }
    printf("\n");
}

// Function to free memory of a dynamic array
void freeDynamicArray(DynamicArray *dy_arr_ptr) {
    destroy(dy_arr_ptr);
}

int main() {
    DynamicArray *intArray = initialize(INITIAL_CAPACITY, INT);
    DynamicArray *floatArray = initialize(INITIAL_CAPACITY, FLOAT);
    DynamicArray *doubleArray = initialize(INITIAL_CAPACITY, DOUBLE);
    DynamicArray *charArray = initialize(INITIAL_CAPACITY, CHAR);

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

    printf("Printing dynamic arrays:\n");
    print(intArray);
    print(floatArray);
    print(doubleArray);
    print(charArray);

    freeDynamicArray(intArray);
    freeDynamicArray(floatArray);
    freeDynamicArray(doubleArray);
    freeDynamicArray(charArray);

    return 0;
}
