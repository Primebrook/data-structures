#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    int *data;
} DynamicArray;

DynamicArray initialize(size_t initial_capacity);
