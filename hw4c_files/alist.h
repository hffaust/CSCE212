#ifndef ALIST_H
#define ALIST_H 1

#include "bool.h"

#define DEFAULT_LEN 10

typedef struct alist alist_t;
/** A `generic' array list */
struct alist {
    void **arr;
    int size;
    int len;
};

/** Allocate a new list.
 *
 * @return An empty list of length DEFAULT_LEN and size 0.
 *
 */
alist_t* alalloc(void);

/** Append an item to the list.
 *
 * If more space is needed, resizes to (old_size + 1) * 2.
 *
 * @param lst   The list acting as a stack.
 * @param item  A pointer to the item to push.
 *
 */
void  push(alist_t *lst, void* item);

/** Delete an item from the end of the list.
 *
 * Halves the length of the array if size == length / 4.
 *
 * @param lst  The list acting as a stack.
 *
 * @return     A pointer to the popped item.
 *
 */
void* pop(alist_t *lst);

/** Returns an item matching a given criterion, if one exists.
 *
 * Searches lst for the first item where applying `sel' to
 * that item yields true.
 *
 * @param lst  The list to search.
 * @param sel  The `selection' function.
 *
 * @return The first item that yields true if `sel' is applied to it
 *         (searching from the bottom of the stack). Otherwise, NULL.
 */
void* find(alist_t *lst, bool (*sel)(void*));

/** Maps a function pointwise over a list.
 *
 * e.g. map(square, [1, 2, 3, 4]) = [1, 4, 9, 16]
 *
 * Note that this mutates the original list, it does not return a
 * copy.
 *
 * @param lst  The list to map over.
 * @param func The function to apply to each element.
 *
 */
void map(alist_t *lst, void* (*func)(void*));

#endif
