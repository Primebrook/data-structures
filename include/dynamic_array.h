#include <stdio.h>
#include <stdlib.h>

typedef enum {
	INT,
	FLOAT,
	DOUBLE,
	CHAR
} DataType;

typedef struct {
    size_t size;
    size_t capacity;
    void *data;
	DataType type;	
} DynamicArray;

size_t getDataTypeSize(DataType type) {
	switch (type) {
		case INT:
			return sizeof(int);
		case FLOAT:
			return sizeof(float);
		case DOUBLE:
			return sizeof(double);
		case CHAR:
			return sizeof(char);
	};
	fprintf(stderr, "Not a valid type!");
	exit(EXIT_FAILURE);
};
#define GROWTH_FACTOR 1.6 // https://github.com/facebook/folly/blob/main/folly/docs/FBVector.md

DynamicArray initialize(void *initial_values, size_t initial_size, DataType type);
void set_at(DynamicArray *dy_arr, size_t pos, void* value);
void* get_at(DynamicArray *dy_arr, size_t pos);
void iter_seq(DynamicArray *dy_arr);
void insert_at(DynamicArray *dy_arr, size_t pos, void* value);
void resize(DynamicArray *dy_arr);
void delete_last(DynamicArray *dy_arr);
void delete_first(DynamicArray *dy_arr);
void delete_at(DynamicArray *dy_arr, size_t pos);


