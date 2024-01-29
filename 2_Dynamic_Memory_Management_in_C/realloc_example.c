/*
 * Understanding and Using C Pointers
 *
 * Chapter 2 - Dynamic Memory Management in C
 *
 * realloc_example.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char *string1;
    char *string2;
    char *string3;

    string1 = (char*)malloc(16);
    strcpy(string1, "0123456789AB");  // We store less than 16

    fprintf(stdout, "[%p] %s\n", string1, string1);

    /*
     * Use realloc to specify a smaller region of memory
     */
    string2 = realloc(string1, 8);

    fprintf(stdout, "string1 [%p] %s\n", string1, string1);   
    fprintf(stdout, "string2 [%p] %s\n", string2, string2);

    /*
     * Use realloc to specify a larger region of memory
     */
    string3 = realloc(string1, 64);

    fprintf(stdout, "string1 [%p] %s\n", string1, string1);   
    fprintf(stdout, "string3 [%p] %s\n", string3, string3);
    return EXIT_SUCCESS;
}
