#include "array.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray *initialize(int initial_capacity) {
  DynamicArray *d_arr_ptr = malloc(sizeof(DynamicArray));

  if (d_arr_ptr == NULL) {
    fprintf(stderr, "Failed to allocate memory for dynamic array.\n");
    exit(EXIT_FAILURE);
  };

  d_arr_ptr->data = (int *)malloc(initial_capacity * sizeof(int));
  if (d_arr_ptr->data == NULL) {
    free(d_arr_ptr);
    fprintf(stderr, "Failed to allocation memory for dynamic array data.\n");
    exit(EXIT_FAILURE);
  };

  d_arr_ptr->size = 0;
  d_arr_ptr->capacity = initial_capacity;
  return d_arr_ptr;
};
