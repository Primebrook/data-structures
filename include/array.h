#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 10
#define GROWTH_FACTOR 2 // The factor by which the capacity will increase

typedef enum {
    INT,
    FLOAT,
    DOUBLE,
    CHAR
} DataType;

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    DataType type;
} DynamicArray;

void handleError(const char *message);
void checkPointerAndIndex(DynamicArray *dy_arr_ptr, int index);
DynamicArray *initialize(size_t initial_capacity, DataType type);
bool resize(DynamicArray *dy_arr_ptr, size_t new_capacity);
void add(DynamicArray *dy_arr_ptr, void *value);
void* get(DynamicArray *dy_arr_ptr, int index);
void set(DynamicArray *dy_arr_ptr, int index, void *value);
size_t size(DynamicArray *dy_arr_ptr);
void clear(DynamicArray *dy_arr_ptr);
void destroy(DynamicArray *dy_arr_ptr);
void print(DynamicArray *dy_arr_ptr);
void checkPointerAndIndex(DynamicArray *dy_arr_ptr, int index);
size_t getDataTypeSize(DataType type);
void freeDynamicArray(DynamicArray *dy_arr_ptr);

#endif // ARRAY_H
