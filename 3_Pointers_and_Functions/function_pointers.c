/*
 * Understanding and Using C Pointers
 * Chapter 3: Pointers and Functions
 *
 * Functions Pointers.
 *
 * Basically we declare a variable to hold the memory
 * space of a function, which allows us to pass the
 * function itself as an argument to other functions.
 *
 * It is a good practice to declare a typdef for this
 * function pointer. By standard we prefix 'fptr' to
 * any function pointer variable we create.
 */

/*
 * Syntax:
 *
 * void (*foo)( );
 *  |      |   |
 *  |      |   |
 *  |      |   --- parameters
 *  |      |
 *  |      ------- function pointer's variable name
 *  |
 *  -------------- return type
 */

#include <stdio.h>
#include <stdlib.h>

typedef int (*fptrOperation)(int, int);

int add(int a, int b);
int sub(int a, int b);
int compute(fptrOperation operation, int a, int b);
/*
 * To return a function pointer we need to declare the return
 * type as a function pointer.
 */
fptrOperation selectoperation(char opcode);
int evaluate(char opcode, int a, int b);

int main(void)
{
    int a;
    int b;

    fprintf(stdout, "Enter values\n");
    scanf("%d %d", &a, &b);

    fprintf(stdout, "Sum: %d\n", compute(add, a, b));
    fprintf(stdout, "Sub: %d\n", compute(sub, a, b));

    fprintf(stdout, "Sum: %d\n", evaluate('+', a, b));
    fprintf(stdout, "Sub: %d\n", evaluate('-', a, b));

    return EXIT_SUCCESS;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int compute(fptrOperation operation, int a, int b)
{
    return operation(a, b);
}

fptrOperation selectoperation(char opcode)
{
    switch(opcode)
    {
        case '+': return add;
        case '-': return sub;
    }
}

int evaluate(char opcode, int a, int b)
{
    fptrOperation operation = selectoperation(opcode);
    return operation(a, b);
}
