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

Node *node_initialize(int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Failed to allocate memory for node.");
        exit(EXIT_FAILURE);
    };
    node->value = value;
    node->next = NULL;
    return node;
};

void list_push(Node *list, int value) {
    Node *node = list;
    while (node->next != NULL) {
        node = node->next;
    };
    Node *new_node = node_initialize(value);
    node->next = new_node;
};

size_t list_length(Node *list) {
    Node *node = list;
    size_t len = 0;
    while (node != NULL) {
        node = node->next;
        len++;
    };
    return len;
};

void list_free(Node *list) {
    Node *node = list;
    while (node != NULL) {
        Node *next_node = node->next;
        free(node);
        node = next_node;
    };
};
