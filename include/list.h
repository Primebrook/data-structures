#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

typedef struct {
    Node *head;
} List;

List *list_initialize();
void list_set_at(List *list, size_t pos, int value);
