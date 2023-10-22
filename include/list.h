#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

Node *list_initialize();
Node *node_initialize(int value);
void list_push(Node *list, int value);
size_t list_length(Node *list);
void list_free(Node *list);
