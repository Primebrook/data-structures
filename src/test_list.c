#include "test_list.h"
#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_linked_list_initialize() {
    List *list = linked_list_initialize();
    assert(list != NULL);
    puts("test_linked_list_initialize \033[0;32mPASSED.\033[0m");
};

void test_linked_list() { test_linked_list_initialize(); };
