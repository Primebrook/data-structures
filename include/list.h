#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

typedef struct {
    Node *head;
} List;

List *linked_list_initialize();
