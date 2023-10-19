/*
 * Understanding and Using C Pointers
 * 
 * Chapter 1: Introduction
 * Pointer Operators -> Pointer Arithmetic
 *
 */

/*
 * Common data sizes
 * 
 * Data    |  Size in bytes
 * ------------------------
 * byte    |       1
 * char    |       1
 * short   |       2
 * int     |       4
 * long    |       8
 * float   |       4
 * double  |       8
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
     * Adding and integer to a pointer
     * When we add an integer to a pointer, the
     * amount added is the product of the integer
     * times the number of bytes of the underlying
     * data type. Pointers are declared with data
     * types so that these sorts of arthmetic
     * operations are possible.
     */

    /*
     * Assume vectos memory starts at: 100
     *             100  104  108
     */
    int vector[] = {28,  41,  7};
    int *pi = vector;  // pi memory = 100

    printf("+--------------+\n");
    printf("  Integer add   \n");
    printf("+--------------+\n");
    
    printf("Value at memory space: %p -> %d\n", pi, *pi);  // Print memory space: 100
    pi++;  // pi memory = 100 + (1 * 4) = 104
    
    printf("Value at memory space: %p -> %d\n", pi, *pi);  // Print memory space: 104
    pi++;  // pi memory = 104 + (1 * 4) = 108
    
    printf("Value at memory space: %p -> %d\n", pi, *pi);  // Print memory space: 108
    pi++;  // pi memory = 108 + (1 * 4) = 112
    
    printf("+--------------+\n");
    printf("   Short add    \n");
    printf("+--------------+\n");

    short s;
    short *ps = &s;

    printf("Memory space before add: %p\n", ps);
    ps++;
    printf("Memory space after add: %p\n", ps);
    
    printf("+--------------+\n");
    printf("    Char add    \n");
    printf("+--------------+\n");

    char c;
    char *pc = &c;

    printf("Memory space before add: %p\n", pc);
    pc++;
    printf("Memory space after add: %p\n", pc);

    /*
     * Same behavior observed with substracting an
     * integer from a pointer, but from top to bottom.
     */

    /*
     * Subtracting two pointer.
     * When one pointer is subtracted from another, we get
     * the difference between their addresses. (Array pos)
     * ptrdiff_t data type is returned when subtracting the
     * difference between two pointers, this is a portable
     * way to express it.
     */

    printf("+--------------+\n");
    printf("  Pointer diff  \n");
    printf("+--------------+\n");
    
    int *p0 = vector;      // Memory 100 -> 28
    int *p1 = vector + 1;  // Memory 104 -> 41
    int *p2 = vector + 2;  // Memory 108 -> 7

    printf("Memory space p0: %p -> value: %d\n", p0, *p0);
    printf("Memory space p1: %p -> value: %d\n", p1, *p1);
    printf("Memory space p2: %p -> value: %d\n", p2, *p2);

    printf("p2 - p0: %d\n", p2 - p0);
    printf("p1 - p0: %d\n", p1 - p0);
    printf("p0 - p1: %d\n", p0 - p1);

    /*
     * This is not the same as getting the difference
     * among the values stored at that memory address.
     * This is called dereference operator.
     */
    printf("*po - *p1: %d\n", *p0 - *p1);

    return EXIT_SUCCESS;
}
