#ifndef LLIST_H
#define LLIST_H 1

typedef struct llist llist_t;
/** A linked list.  */
struct llist {
    int val;
    llist_t *next;
};

typedef struct proof proof_t;
/** A return value, with a proof.
 * This will be used to show that your function used the correct
 * algorithm.
 */
struct proof {
    int return_val;
    int *proof;
};

/** Allocate a new list.
 * @return An node containing `val' and pointing to NULL.
 */
llist_t *llalloc(int val);

/** Copy a linked list.
 *
 */
llist_t *copy(llist_t *lst);

/** Generates a linked list from an array.
 *
 * e.g. copy({1, 3, 5}) = [1, 3, 5]
 *
 * @param arr  The array to convert
 * @param size The size of the array
 *
 */
llist_t *convert(unsigned int *arr, unsigned int size);

/** Detects a cycle in a linearly-linked structure.
 *
 * Uses the Tortoise & Hare algorithm.
 *
 * In addition to its normal return value, this function also returns
 * the first location that the tortoise & hare meet.
 *
 * @param lst
 *
 * @return If a cycle exists, then the index of the start of the
 *         cycle. Otherwise, -1.
 *
 */
proof_t *tort_hare(llist_t *lst);

/** Detects a cycle in a linearly-linked structure.
 *
 * Uses the reverse-links algorithm.
 *
 * In addition to its normal return value, this function also returns
 * the first `num' numbers encountered in an array
 *
 * e.g. for the following structure, which we assign to `lst':
 *
 *   1 -> 2 -> 3 -> 4
 *        ^_________|
 *
 * then the result would be:
 *
 *   { return_val = 1;
 *     proof = {1, 2, 3, 4, 2};
 *   }
 *
 * @param lst
 * @param num The number of values to save in the 'proof' array.
 *
 * @return If a cycle exists, then the index of the start of the
 *         cycle. Otherwise, -1.
 *
 */
proof_t *rev_cycle(llist_t *lst, int num);

#endif
