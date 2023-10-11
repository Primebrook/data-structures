#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List *list_initialize() {
    size_t empty_list_size = sizeof(int) + sizeof(void *);
    List *list = malloc(empty_list_size);
    Node *head = malloc(sizeof(void *));
    list->head = head;
    return list;
};

void list_set_at(List *list, size_t pos, int value) {
	// this only sets the head value irrespective of the pos param
    (list->head)->value = value;
    (list->head)->next = NULL;
};
