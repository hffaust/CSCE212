#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "llist.h"
#include "bool.h"

#define LIST_SIZE 10

typedef unsigned int uint;

llist_t *loop(uint size);
llist_t *no_loop(uint size);
bool verify_convert(uint *shuff, llist_t *lst, uint size);

void print_list(llist_t *lst);
void print_arr(uint*, uint);

uint *shuffled(uint size);

uint  (*valid_rand)(void);
uint* rand_arr(int size);
void  init_rand(void);

int NUM_ERRORS = 0;

int main() {
    init_rand();
    uint size = LIST_SIZE;

    llist_t *head = loop(size);

    uint proof_len = random() % (size + 1) + 1;
    printf("proof length: %2d\n", proof_len);

    printf("\n");

    proof_t *th = tort_hare(head);
    if (th->proof != NULL) {
        printf("=Tort/Hare=\n  Proof: %d\n  Cycle: %d\n", *((int*) th->proof), th->return_val);
    } else {
        printf("=Tort/Hare=\n  Proof:  X\n  Cycle: %d\n", th->return_val);
    }

    proof_t *rev = rev_cycle(head, proof_len);
    if (rev->proof != NULL) {
        printf("=Rev Links=\n  Proof: ");
        print_arr(rev->proof, proof_len);
        printf("\n");
        printf("  Cycle: %d\n", rev->return_val);
    } else {
        printf("=Tort/Hare=\n  Proof:  X\n  Cycle: %d\n", rev->return_val);
    }


    //return 0;
}

/** Constructs a looped linked list, where the loop is NOT solely on
 * the last element.
 */
llist_t *loop(uint size) {
    uint *shuff = rand_arr(size);
    uint last_val = shuff[size - 1];
    uint sec_last_val = shuff[size - 2];

    printf("shuffled: ");
    print_arr(shuff, size);
    printf("\n");
    llist_t *lst = convert(shuff, size);
    uint rand_val = last_val;
    while (rand_val == last_val || rand_val == sec_last_val) {
        rand_val = random() % size;
    }
    llist_t *ixth;
    llist_t *last;
    if (verify_convert(shuff, lst, size)) {
        for(last = lst; last->next != NULL; last = last->next) {
            if (last->val == rand_val) {
                ixth = last;
            }
        }
        last->next = ixth;
    } else {
        fprintf(stderr, "Convert failed, cannot continue.\n");
        exit(1);
    }
    printf("loop:         %2d\n", ixth->val);
    return lst;
}

llist_t *no_loop(uint size) {
    uint *shuff = rand_arr(size);
    llist_t *lst = convert(shuff, size);
    verify_convert(shuff, lst, size);
    return convert(shuff, size);
}

bool verify_convert(uint *shuff, llist_t *lst, uint size) {
    uint i;
    for (i = 0; i < size; i++, lst = lst->next) {
        if (shuff[i] != lst->val) {
            fprintf(stderr, "ERROR: converted list doesnt match original array at index %d.\n", i);
            NUM_ERRORS++;
            return false;
        }
    }
    return true;
}

void init_rand() {
    struct timespec ts;
    if (timespec_get(&ts, TIME_UTC) == 0) {
        /* Handle error */
        valid_rand = rand;
    } else {
        valid_rand = random;
        uint seed = ts.tv_nsec ^ ts.tv_sec;
        printf("seed: %u\n", seed);
        srandom(seed);  /* Seed the PRNG */
    }
}

uint* rand_arr(int size) {
    uint *arr = malloc(sizeof(uint) * size);
    { // Generate {1..size}
        int i;
        for (i = 0; i < size; i++) {
            arr[i] = i;
        }
    }
    {
        uint i;
        for (i = size - 1; i > 1; i--) {
            uint j = random() % i;
            arr[i] = arr[j] ^ arr[i];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
        }
    }
    return arr;
}

void print_arr(uint *arr, uint len) {
    int i;
    printf("{");
    for (i = 0; i < len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d", arr[i]);
    printf("}");
}

void print_list(llist_t *lst) {
    printf("[");
    for (; lst->next != NULL; lst=lst->next) { printf("%d, ", lst->val); }
    printf("%d]\n", lst->val);
}

