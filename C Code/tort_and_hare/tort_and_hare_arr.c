#include <stdio.h>

int next(int*, int, int);
int stage_one(int*, int);
int stage_two(int*, int, int);

int main() {
    int array[10];

    array[0] =7;
    array[1] =8;
    array[2] =9;
    array[3] =3;
    array[4] =2;
    array[5] =6;
    array[6] =6;
    array[7] =1;
    array[8] =4;
    array[9] =4;
    int meet = stage_one(array, 10);
    int begin;
    if (meet < 0) {
        begin = -1;
    } else {
        begin = stage_two(array, 10, meet);
    }

    printf("%d, %d\n", meet, begin);
}

/**
 * The next function for a particular struture.
 *
 * @param arr A pointer to the structure
 * @param ix  The value for which to find 'next'
 * @return The next value.
 */
int next(int *arr, int length, int ix) {
    if (ix >= length) {
        return -1;
    }
    return *(arr + ix);
}

/**
 * Implements the first stage of tortoise & hare.
 *
 * @return -1 if no cycle found, or the index of the meeting pointers
 *         if a cycle is found.
 */
int stage_one(int *structure, int length) {
    int tort = 0;
    int hare = 0;

    do {
        tort = next(structure, length, tort);
        if (tort < 0) {break;}

        hare = next(structure, length, hare);
        if (hare < 0) {tort = hare; break;}
        hare = next(structure, length, hare);
        if (hare < 0) {tort = hare; break;}
    } while (tort != hare);

    return tort;
}

/**
 * Finds the beginning of the cycle.
 *
 * @param structure The structure in which to find the cycle.
 * @param meet      The value found in stage one of the algorithm.
 * @return The start of the cycle.
 */
int stage_two(int *structure, int length, int meet) {
    int tort1 = 0;
    int tort2 = meet;
    while (tort1 != tort2) {
        tort1 = next(structure, length, tort1);
        tort2 = next(structure, length, tort2);
    }
    return tort1;
}
