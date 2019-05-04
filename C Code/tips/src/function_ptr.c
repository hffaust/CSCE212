#include <stdio.h>
#include <stdlib.h>

/**
 * \file   function_ptr.c
 * \brief  A brief lesson on function pointers
 * \author Daniel Pade
 * \date   2014
 *
 * A sum is a function that generally takes another function as an argument:
 *
 * n
 * Σ f(i)
 * i
 *
 * in this case, the summation should take an inital value i, a final value n,
 * and a function that operates on those values.
 * e.g. An average of all squares from 0 to 10 can be written as:
 *
 * int i = 0;
 * int n = 10;
 * int N = (n + 1) - i // number of iterations
 * int avg = sum(i,n,square) / N;
 *
 * for square a function
 */

int sum( int, int, int (*func)(int) );
int square( int );
int rev_order_sort( const void*, const void* );

int main()
{
    // avg from 0 to 100 of squares:
    int sqr_avg = sum( 1, 10, &square ) / 10;

    printf( "average of the squares %d\n", sqr_avg );

#ifndef __clang__ // if we're not using clang, we're probably using gcc

    // lambda functions are not part of the C standard, but gcc supports them.
    // Still, you must give them a name
    int (*identity)(int); // function pointer declaration
    identity = ( { int ident (int x) { return x; } &ident; } );

    int reg_avg = sum( 1, 10, identity ) / 10;

    printf( "square of the averages %d\n", reg_avg * reg_avg );
    printf( "variance %d\n", sqr_avg - reg_avg * reg_avg );

#endif

    printf("\n");
    // the standard library function qsort uses function pointers to determine
    // order:
    int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
    qsort( array, 10, sizeof(int), rev_order_sort );
    int i;
    for ( i = 0; i < 10; i++ ) printf( "%d ", array[i] );
    printf("\n");
}

int sum( int i, int n, int (*func)(int) )
{
    int sum = 0;
    int iter = 0;
    for ( iter = i; iter <= n; iter++ ) {
        sum += func(iter);
    }
    return sum;
}

int square( int x )
{
    return x * x;
}

int rev_order_sort( const void* a, const void* b )
{
    int *ai = (int*)a;
    int *bi = (int*)b;
    return ( *ai < *bi ) ? *ai : *bi;
}
