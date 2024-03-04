/*
 * Understanding and Using C Pointers
 *
 * Chapter 2 - Dynamic Memory Management in C
 *
 * garbage_collector.c
 * Free dynamically allocated memory using non-standard
 * approaches
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * malloc and free functions provide a way of manually
 * allocating and deallocating memory.
 * This approach can however bring some issues such as
 * performance, threading problems, achieving good
 * locality and cleaning up memory gracefully.
 */

/* garbage collection consists on the automatic
 * deallocation of memory, when it is no longer needed.
 *
 * An approach to achieve this was created by Bjarne Stroustrup:
 * Resource Acquisition is Initialization (RAII) was originally
 * invented for C++, but there have been several attempts to
 * recreate it for C.
 * The GNU extensio uses a macro called RAII_VARIABLE, it declares
 * a variable and associates with the variable:
 * - A type
 * - A function to execute when the variable is created
 * - A function to execute when the variable goes out of scope
 */

#define RAII_VARIABLE(vartype,varname,initval,dtor)  \
    void _dtor_ ## varname (vartype * v) { dtor(*v); } \
    vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)

int main (void)
{
    RAII_VARIABLE(char *name, name, (char*)malloc(32), free);
    strcpy(name, "RAII EXAMPLE");
    fprintf(stdout, "%s\n", name);

    return EXIT_SUCCESS;
}
