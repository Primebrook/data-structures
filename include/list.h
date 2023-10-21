#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

Node *list_initialize();
// void list_set_at(Node *list, size_t pos, int value);
// size_t length(Node *list);
