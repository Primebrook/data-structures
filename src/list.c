#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List *linked_list_initialize() {
    List *list = malloc(sizeof(int));
    return list;
};
