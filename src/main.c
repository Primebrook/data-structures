#include "test_array.h"
#include <stdio.h>

int main() {
    test_initialize();
    test_insert();
    printf("\n\nAll tests \033[0;32mPASSED.\033[0m\n");
    return 0;
}
