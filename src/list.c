#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// *head = (Node){0}
Node *list_initialize() {
    Node *head = malloc(sizeof(Node));
    if (head == NULL) {
        fprintf(stderr, "Failed to allocate memory for list.");
        exit(EXIT_FAILURE);
    };
    head->value = 0;
    head->next = NULL;
    return head;
};

void list_set_at(Node *list, size_t pos, int value) {
    size_t len = length(list);
    if (len <= pos) {
        fprintf(stderr, "_");
        exit(EXIT_FAILURE);
    };

    list->value = value;
};

size_t length(Node *list) { return 1; };

void list_free(Node *list) {
    Node *node = list;
    while (node != NULL) {
        Node *next_node = node->next;
        free(node);
        node = next_node;
    };
};
