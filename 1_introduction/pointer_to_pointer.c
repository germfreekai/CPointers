/*
 * Understanding and Using C Pointers
 * 
 * Chapter 1: Introduction
 * Pointer Operators -> Pointer to Pointer
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *names[] = {
        "Rene",     // 100
        "Nicky",    // 104
        "Lois",     // 108
        "Jean",     // 112
        "Saldania"  // 116
    };

    /*
     * Names has an assigned memory space
     * for each name.
     * When declaring variables holding this
     * names, instead of creating a copy and
     * using more memory space, we will hold
     * the address of a name in the 'names'
     * array at the second array
     * Declaring this arrays as a pointer to 
     * a pointer of chars.
     */

    char **bestNames[3];
    bestNames[0] = &names[0];  // 100
    bestNames[1] = &names[1];  // 104
    bestNames[2] = &names[3];  // 112

    printf("+----------------+\n");
    printf("   names array    \n");
    printf("+----------------+\n");
    
    for (int i = 0; i < 5; i++)
        printf("names[%d] -> memory: %p -> value: %s\n",
                i, &names[i], names[i]);  // &names   -> shows memory address
                                          // names[i] -> shows value stored at memory address
    
    printf("+----------------+\n");
    printf(" best names array \n");
    printf("+----------------+\n");

    for (int i = 0; i < 3; i++)
        printf("bestNames[%d] -> memory: %p -> value: %s\n",
                i, bestNames[i], *bestNames[i]);  // bestNames[i]  -> stores a memory address wich matches to 'names[#]'
                                                  // *bestNames[i] -> shows value of which stored memory points to

    printf("+----------------+\n");
    printf(" update stored val\n");
    printf("+----------------+\n");
    /*
     * We only need to update value once
     */
    printf("Name at name index 3 -> memory: %p -> value: %s\n", &names[3], names[3]);
    printf("Name at best name index 2 which points to name[3] -> memory: %p -> value: %s\n", bestNames[2], *bestNames[2]);
    names[3] = "Roberto";  // Replace Jean with Roberto: 112
    printf("Name at name index 3 after replacement -> memory: %p -> value: %s\n", &names[3], names[3]);
    printf("Name at best name index 2 which points to name[3] -> memory: %p -> value: %s\n", bestNames[2], *bestNames[2]);
    
    return EXIT_SUCCESS;
}
