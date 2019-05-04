#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int val;
    node *next;
};

node* next(node*);
node* stage_one(node*);
node* stage_two(node*, node*);

int main() {
    node n0;
    node n1;
    node n2;
    node n3;
    node n4;
    node n5;
    node n6;
    node n7;
    node n8;
    node n9;
    n0.val = 0;
    n1.val = 1;
    n2.val = 2;
    n3.val = 3;
    n4.val = 4;
    n5.val = 5;
    n6.val = 6;
    n7.val = 7;
    n8.val = 8;
    n9.val = 9;
    n0.next = &n7;
    n1.next = &n8;
    n2.next = &n9;
    n3.next = &n3;
    n4.next = &n2;
    n5.next = &n6;
    n6.next = &n6;
    n7.next = &n1;
    n8.next = &n4;
    n9.next = &n4;
    printf("%x\n", n0.next);
    printf("%x\n", n1.next);

    node *meet = stage_one(&n0);
    node *begin;
    if (meet == NULL) {
        begin = NULL;
    } else {
        begin = stage_two(&n0, meet);
    }

    if (meet == NULL) {
        printf("No cycle\n");

    } else {
        printf("%d, %d\n", meet->val, begin->val);
    }
}

/**
 * The next function for a particular struture.
 *
 * @param arr A pointer to the structure
 * @param ix  The value for which to find 'next'
 * @return The next value.
 */
node* next(node *the_node) {
    if (the_node == NULL) {
        return NULL;
    }
    return the_node->next;
}

/**
 * Implements the first stage of tortoise & hare.
 *
 * @return -1 if no cycle found, or the index of the meeting pointers
 *         if a cycle is found.
 */
node* stage_one(node *head) {
    node *tort = head;
    node *hare = head;

    do {
        tort = next(tort);
        if (tort == NULL) {break;}

        hare = next(hare);
        if (hare == NULL) {tort = hare; break;}
        hare = next(hare);
        if (hare == NULL) {tort = hare; break;}
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
node* stage_two(node *head, node *meet) {
    node *tort1 = head;
    node *tort2 = meet;
    while (tort1 != tort2) {
        tort1 = next(tort1);
        tort2 = next(tort2);
    }
    return tort1;
}
