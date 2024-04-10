/*
 * Understanding and Using C Pointers
 *
 * Chapter 3: Pointers and Functions
 *
 * pointer_to_pointer
 * When a pointer is passed to a function it is passed by value.
 * If we want to modify the original pointer and not just the copy
 * we need to pass it as a pointer to a pointer.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * We pass a pointer to a pointer
 * First pointer "points" to the arrays first element
 * memory space, second pointer will contain the
 * memory address the first one.
 */
void allocateArr(int **arr, int size, int value);

int main(void)
{

    int *arr = NULL;
    allocateArr(&arr, 5, 10);

    for (int i = 0; i < 5; i++)
        fprintf(stdout, "arr[%d]: %d\n", i, arr[i]);

    free(arr);

    return EXIT_SUCCESS;
}

/*
 * We first allocate memory and then initialize it.
 * The address of this allocated memory is intended
 * to be assigned to a pointer to an int.
 * To modify this pointer in the calling function,
 * we need to pass the pointer's address.
 * Thus, the parameter is declared as a:
 * pointer to a pointer to an int.
 */
void allocateArr(int **arr, int size, int value)
{
    /*
     * calloc: assign memory address and the assigned memory
     * is assigned to arr
     */
    *arr = (int*)calloc(size, sizeof(int));
    if (*arr != NULL)
    {
        for (int i = 0; i < size; i++)
            *(*arr + i) = value * (i + 1); /* we dereference to the first pointer, which is a pointer to int */
        /* Due to pointer arithmetic, and arr of ints, have size of 4 per slot, if we add a value, it will move forward a slot */

        fprintf(stdout, "Print values from function\n");
        for (int i = 0; i < size; i++)
            fprintf(stdout, "arr[%d]: %d\n", i, *(*arr + i));
    }
    else
    {
        fprintf(stderr, "arr is NULL\n");
        exit(1);
    }
}
/*
 * First dereference of a pointer to a pointer to an int
 * will refer to the pointer to int.
 */
