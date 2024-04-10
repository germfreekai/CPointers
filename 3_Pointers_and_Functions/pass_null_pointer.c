/*
 * Understanding and Using C Pointers
 *
 * Chapter 3: Pointers and Functions
 *
 * pass_null_pointer
 * Explain why it is a good idea to check for NULL
 * before using a passed pointer
 */

#include <stdio.h>
#include <stdlib.h>

void allocateArr(int *arr, int size, int value);

/*
 * It is a good idea to check that a passed argument
 * is not NULL before using it
 */
int main(void)
{
    //int *arr = (int*)calloc(5, sizeof(int));
    int *arr = NULL;
    allocateArr(arr, 5, 10);

    for (int i = 0; i < 5; i++)
        fprintf(stdout, "arr[%d]: %d\n", i, arr[i]);

    free(arr);
    return EXIT_SUCCESS;
}

void allocateArr(int *arr, int size, int value)
{
    if (arr)
    {
        for (int i = 0; i < size; i++)
            arr[i] = value * i;
    }
    else
    {
        fprintf(stderr, "ARR is NULL\n");
        exit(1);
    }
}
