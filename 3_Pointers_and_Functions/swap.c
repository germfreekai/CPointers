/*
 * Understanding and Usign C Pointers
 *
 * Chapter 3: Pointers and Functions
 *
 * swap.c
 * One of the main reasons to pass data using a pointer
 * it to allow the function to modify that data.
 */

#include <stdio.h>
#include <stdlib.h>

void swap_args(int *a, int *b);

int main(void)
{
    int a = 10;
    int b = 20;

    fprintf(stdout, "Before swap - A: %d - B: %d\n", a, b);

    swap_args(&a, &b);

    fprintf(stdout, "After swap - A: %d - B: %d\n", a, b);

    return EXIT_SUCCESS;
}

/*
 * By modifying by pointer, we can play around
 * with the data value without creating a memory
 * copy of it
 * If we were to pass by value, a copy would be
 * created and any change made on them would not
 * be reflected on the original pointer to variable.
 */
void swap_args(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
