#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    int *data;
} DynamicArray;

DynamicArray *initialize(size_t initial_capacity, size_t initial_size);
DynamicArray *insert(DynamicArray *dy_arr, size_t pos, int value);
void resize(DynamicArray *dy_arr, size_t new_capacity);
// etc etc
