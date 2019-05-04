#include <stdio.h>
#include <stdlib.h>

/**
 * \file   stack_vs_heap.c
 * \brief  A lesson on the stack vs the heap
 * \author Daniel Pade
 * \date   2014
 */

typedef struct integer_in_a_box box_t;

box_t* create_heap_box();
box_t* create_stack_box();

struct integer_in_a_box {
    int the_int;
};

int main()
{
    box_t *heap_box  = create_heap_box();
    box_t *stack_box = create_stack_box();

    printf("%d\n", heap_box->the_int);  // 100
    printf("%d\n", stack_box->the_int); // Garbage!

    free(heap_box);     // always clean up after yourself
 /* free(stack_box); */ // but don't throw away what isn't yours
}

box_t* create_stack_box()
{
    box_t actual_box;

    box_t *box_ptr = &actual_box;  // Get a pointer to the LOCAL var
    box_ptr->the_int = 100;
    return box_ptr;                // Here, actual_box is now destroyed,
                                   // so we have a pointer to nothing
}

box_t* create_heap_box()
{
    box_t *box_ptr = (box_t*) malloc(sizeof(box_t));  // Get some global mem chunk
    box_ptr->the_int = 100;
    return box_ptr; // returns a pointer to some space in the heap, which
                    // we can access from anywhere
}
