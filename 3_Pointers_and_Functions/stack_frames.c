/*
 * Understanding and Using C Pointers
 * Chapter 3: Pointers and Functions
 *
 * stack_frames.c
 */

/*
 * Stack is an area of memory shared with the heap
 * that supports the execution of functions.
 * The program stack hols 'stack frames' which holds
 * the parameters and local variables of a function.
 * 
 * As function are called, stack frames are pushed
 * onto the stack and the stack grows 'upward', when
 * the function is terminated, the stack frame is
 * popped off the program stack. This memory is not
 * free'd and can eventually be overridden.
 */

#include <stdio.h>
#include <stdlib.h>

float average(int *arr, int size);

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};

    fprintf(stdout, "average: %0.2f\n", average(arr, 5));

    return EXIT_SUCCESS;
}

float average(int *arr, int size)
{
    int sum;
    sum = 0;

    /*
     * The gap among parameters and local variables is due
     * to other stack elements being used by the function.
     */
    fprintf(stdout, "arr memory: %p\n", &arr);
    fprintf(stdout, "size memory: %p\n", &size);
    fprintf(stdout, "sum memory: %p\n", &sum);

    /*
     * Block statements at C are treated as 'mini' functions
     * hence their local variables will be pushed and popped
     * from the stack correspondingly.
     */
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return (sum * 1.0f) / size;
}
