/*
 * Understanding and Using C Pointers
 * 
 * Chapter 2 - Dynamic Memory Management in C
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    // Name plus the \0 char
    char *name = (char*) malloc(strlen("Susan")+1);
    strcpy(name, "Susan");
    while (*name != 0)
    {
        printf("%c", *name);
        name++;
    }

    /* We are printing the name char by char
     * moving the pointer forward to the next
     * char's memory address, thus, at the
     * end name is left pointing to the
     * string's NUL termination character
     * and the allocated memory's starting
     * address has been lost
     */
    return EXIT_SUCCESS;
}
