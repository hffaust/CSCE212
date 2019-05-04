/**
 * \file function_declarations.c
 * \brief An overview of function declarations focusing on parameter lists
 */

void empty_list();
void void_list(void);

int main()
{
    // okay, even though the parameter list is empty
    empty_list(1,2,3,4,5);

    // compile time error, because 'void' signals that the function can take
    // no parameters
    /* void_list(1,2,3,4,5); */
    return 0;
}

void empty_list()
{
}
void void_list()
{
}
