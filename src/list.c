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
    int len = length(list);
    if (len <= pos) {
        fprintf(stderr, "Failed to set value: position is greater than current "
                        "list length.\n");
        exit(EXIT_FAILURE);
    };
};

size_t length(Node *list) { return 1; };
