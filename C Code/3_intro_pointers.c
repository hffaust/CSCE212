#include <stdio.h>

int main() {
    int some_int = 10;
    /* Star means pointer to object
     * (part of the type) */

    /* Ampersand means reference to some_int
     * (part of the varname) */
    int *ptr_to_int = &some_int;

    printf("%x %d\n", ptr_to_int, some_int);

    /* Dereference */
    /* Star means dereference
     * (part of the varname) */
    printf("%x %d\n", ptr_to_int, *ptr_to_int);
    return 0;
}
