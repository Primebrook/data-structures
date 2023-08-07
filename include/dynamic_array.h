#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    int *data;
} DynamicArray;

#define GROWTH_FACTOR                                                          \
    1.6 // https://github.com/facebook/folly/blob/main/folly/docs/FBVector.md

DynamicArray initialize(int *initial_values, size_t initial_size);
void set_at(DynamicArray *dy_arr, size_t pos, int value);
int get_at(DynamicArray *dy_arr, size_t pos);
void iter_seq(DynamicArray *dy_arr);
void insert_at(DynamicArray *dy_arr, size_t pos, int value);
void resize(DynamicArray *dy_arr);
void delete_last(DynamicArray *dy_arr);
