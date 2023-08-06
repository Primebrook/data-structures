#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    int *data;
} DynamicArray;

DynamicArray initialize(size_t initial_capacity, size_t initial_size);
void set_at(DynamicArray *dy_arr, size_t pos, int value);
int get_at(DynamicArray *dy_arr, size_t pos);
