#include <stdio.h>
#include <stdlib.h>

/**
 * \file   pass_by_val.c
 * \brief  An illustration that C is pass by value ONLY
 * \author Daniel Pade
 * \date   2014
 */

typedef struct integer_in_a_box box_t;

void change_by_val( box_t a_box_val );
void change_by_ref( box_t *a_box_ref );

struct integer_in_a_box {
    int the_int;
};

int main()
{
    box_t the_val_box;
    box_t the_ref_box;
    the_val_box.the_int = 1;
    the_ref_box.the_int = 1;

    printf("original by val: %d\n", the_val_box.the_int);
    printf("original by ref: %d\n", the_ref_box.the_int);

    printf("\n");
    change_by_val(  the_val_box );
    change_by_ref( &the_ref_box );

    printf("changed by val? %d\n", the_val_box.the_int);
    printf("changed by ref? %d\n", the_ref_box.the_int);
    return 0;
}

void change_by_val( box_t a_box_val )
{
    // a_box_val is a copy of the original parameter

    // i.e. a COPY of the box

    // no matter how you do it
    a_box_val.the_int = 10;

    box_t *a_box_ref = &a_box_val;
    // it won't change the original
    a_box_ref->the_int = 10;
}

void change_by_ref( box_t *a_box_ref )
{
    // a_box_ref is still a copy of the original parameter

    // but that means we have a copy of the POINTER to the original box!
    a_box_ref->the_int = 10;

    // this also works (note the loose binding of the deref operator)
    // (*a_box_ref).the_int = 10;
}
