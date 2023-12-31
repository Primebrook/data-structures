#include "test_list.h"
#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_list_initialize() {
    Node *list = list_initialize();
    assert(list != NULL);

    free(list);
    puts("test_list_initialize \033[0;32mPASSED.\033[0m");
};

void test_list_push_1() {
    Node *list = list_initialize();
    list_push(list, 5);
    assert((list->next)->value == 5);
    list_free(list);
    puts("test_list_push_1 \033[0;32mPASSED.\033[0m");
};

void test_list_push_2() {
    Node *list = list_initialize();
    list_push(list, 5);
    list_push(list, 105);
    assert(((list->next)->next)->value == 105);
    list_free(list);
    puts("test_list_push_2 \033[0;32mPASSED.\033[0m");
};

void test_list_insert() {
    Node *list = list_initialize();
    list_insert(list, 1, 22);
    assert((list->next)->value == 22);
    assert((list->next)->next == NULL);
    list_free(list);
    puts("test_list_insert \033[0;32mPASSED.\033[0m");
};

void test_list_set_at_1() {
    Node *list = list_initialize();
    list_set_at(list, 0, 22);
    assert(list->value == 22);
    assert(list->next == NULL);
    list_free(list);
    puts("test_list_set_at_1 \033[0;32mPASSED.\033[0m");
};

void test_list_set_at_2() {
    Node *list = list_initialize();
    list_push(list, 100);
    list_set_at(list, 1, 465);
    assert((list->next)->value == 465);
    assert((list->next)->next == NULL);
    list_free(list);
    puts("test_list_set_at_2 \033[0;32mPASSED.\033[0m");
};

void test_list_get_at_1() {
    Node *list = list_initialize();
    int value_0 = list_get_at(list, 0);
    assert(value_0 == 0);
    list_free(list);
    puts("test_list_get_at_1 \033[0;32mPASSED.\033[0m");
};

void test_list_get_at_2() {
    Node *list = list_initialize();
    list_push(list, 124214);
    list_push(list, 568);
    int value_1 = list_get_at(list, 1);
    int value_2 = list_get_at(list, 2);
    assert(value_1 == 124214);
    assert(value_2 == 568);
    list_free(list);
    puts("test_list_get_at_2 \033[0;32mPASSED.\033[0m");
};

void test_list_length_1() {
    Node *list = list_initialize();
    size_t len = list_length(list);
    assert(len == 1);
    free(list);
    puts("test_list_length_1 \033[0;32mPASSED.\033[0m");
};

void test_list() {
    test_list_initialize();
    test_list_length_1();
    test_list_push_1();
    test_list_push_2();
    test_list_insert();
    test_list_set_at_1();
    test_list_set_at_2();
    test_list_get_at_1();
    test_list_get_at_2();
};
