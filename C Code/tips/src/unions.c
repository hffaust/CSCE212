#include <stdio.h>

union untagged_union {
    int   an_int;
    char *a_string;
};

enum tag { INT, STRING };
struct tagged_union {
    int tag;
    union untagged_union the_union;
};

int main()
{
    union untagged_union notag;

    notag.an_int = 5;
    printf("%d\n", notag);

    notag.a_string = "a string";
    printf("%s\n", notag);

    printf("\n");

    struct tagged_union tagged;

    tagged.tag = INT;
    tagged.the_union.an_int = 5;

    if ( tagged.tag == INT ) {
        printf( "%d\n", tagged.the_union.an_int );
    } else if ( tagged.tag == STRING ) {
        printf("%s\n", tagged.the_union.a_string);
    }
}
