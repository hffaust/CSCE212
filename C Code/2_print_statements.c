#include <stdio.h>

int main(int argc, char **argv) {
    int an_int = 10;
    char *some_string = "Hello World!";
    /* print format code */
    printf("%d Between %d\n", an_int, an_int);
    /* BAD: "10" + "5" */

    float some_double = 5.25;
    /* printf codes */
    printf("f: %f\n", some_double);
    printf("g: %g\n", some_double);
    printf(".3f: %.3f\n", some_double);

    printf("x: %x\n", some_double);

    printf("s: %s\n", some_string);

    printf("%d", 3^2);

    return 0;
}
