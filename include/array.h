typedef struct {
    int size;
    int capacity;
    int *data;
} DynamicArray;

DynamicArray *initialize(int initial_capacity, int initial_size);
DynamicArray *insert(DynamicArray *dy_arr, int pos, int value);
int resize(DynamicArray *dy_arr, int new_capacity);
// etc etc
