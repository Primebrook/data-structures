#include "test_dynamic_array.h"
#include "test_list.h"
#include <stdio.h>

int main() {
    test_dynamic_array();
    test_list();
    printf("\n\nAll tests \033[0;32mPASSED.\033[0m\n");
    return 0;
}
