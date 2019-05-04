#include <stdarg.h>
#include <stdio.h>

int findAverage(int, ...);

int main()
{
    printf( "%d\n", findAverage(3, 1,2,3) );
    printf( "%d\n", findAverage(5, 1,2,3,4,5) );
    return 0;
}

int findAverage(int count, ...)
{
    va_list list;
    va_start(list, count);

    int sum = 0;
    int arg_index;
    for ( arg_index = 0; arg_index < count; arg_index++ ) {
        sum += va_arg(list, int);
    }

    va_end(list);

    return sum / count;
}
