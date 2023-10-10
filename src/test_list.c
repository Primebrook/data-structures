#include "test_list.h"
#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_list_initialize() {
    List *list = list_initialize();
    assert(list != NULL);

    free(list);
    puts("test_list_initialize \033[0;32mPASSED.\033[0m");
};

void test_list_set_at_1() {
    List *list = list_initialize();
    list_set_at(list, 0, 4564);
    assert((list->head)->value == 4564);

    free(list);
    puts("test_list_set_at_1 \033[0;32mPASSED.\033[0m");
};

void test_list() {
    test_list_initialize();
    test_list_set_at_1();
};
