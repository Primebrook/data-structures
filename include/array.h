typedef struct {
    int size;
    int capacity;
    int *data;
} DynamicArray;

DynamicArray *initialize(int initial_capacity);
DynamicArray *insert(DynamicArray *dy_arr, int pos, int value);
// etc etc
