/*
 * Understanding and Using C Pointers
 *
 * Chapter 2 - Dynamic Memory Management in C
 *
 */

/*
 * How to store a simple integer
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    /* The size of an integer although typically
     * can be 4, may change among systems and
     * compilers, for this reason it a better
     * practice to use sizeof(data_type);
     * The malloc function single argument specifies
     * the number of bytes to allocate.
     */
    int *pi = (int*) malloc(sizeof(int));
    *pi = 5;
    printf("*pi: %d\n", *pi);
    free(pi);

    /* A common mistake involving dereference
     * operator is as follows:
     *  int *pi;
     *  *pi = (int*) malloc(sizeof(int));
     * The problem with the LHS is that we are
     * dereferencing the pointer, thus, assigning
     * the address returned by malloc to the
     * address stored in pi, which might be invalid
     * if it is the first time we make an assignment.
     * The correct approach:
     *  pi = (int*) malloc(sizeof(int));
     * Then the assignment will take place to the
     * pointer itself.
     */

    return EXIT_SUCCESS;
}
