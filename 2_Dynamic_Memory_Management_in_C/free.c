/*
 * Understanding and Using C Pointers
 *
 * Chapter 2 - Dynamic Memory Management in C
 *
 * free.c
 * Free dynamically allocated memory and some
 * practices
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int num;
    int *pi = (int*)malloc(sizeof(int));
    *pi = 5;  // Assing the memory pi points to to value 5
    // dereference pi
    
    // pi = &num; When freed this would result on a invalid heap memory
    // thus free operation would have an 'undefined' behavior

    fprintf(stdout, "num > ");
    scanf("%d", &num);

    fprintf(stdout, "Memory address of num: %p\nValue of num: %d\n", &num, num);
    fprintf(stdout, "Memory address of pi: %p\nMemory pi points to: %p\nValue of memory pi points to: %d\n", &pi, pi, *pi);

    /*
     * 'free' statement frees allocated memory with
     * malloc like functions, and gives it back to heap
     * memory for other use
     */
    free(pi);
    /*
     * A common practice is to assign NULL to a freed pointer
     * to explicitly designate it as invalid
     */
    pi = NULL;

    return EXIT_SUCCESS;
}
