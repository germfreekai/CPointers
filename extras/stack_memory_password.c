/*
 * Understanding and Using C Pointers
 *
 * stack_memory_password.c
 * This is an extra example to show how stack memory
 * buffer overflow could be dangerous, will add some
 * compilation protection flags afterwards
 *
 * You can add compilation flags to protect stack
 * from clashing and overflows as follows:
 * $ gcc -o a a.c -fstack-protector-strong -fstack-clash-protection
 * This will add what is also known as 'stack canary' protection.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /* we add the NULL char terminator space */
    char stored_psswd[7] = "mytest";
    
    char user_name[7];
    char user_psswd[7];

    /* memory representation (moreless)
     * [user_psswd] [user_name] [stored_psswd]
     *
     * Note: Stack is "grow up" so something like this
     * [stored_passwd]
     * [user_name]
     * [user_psswd]
     *
     * Hence when we overflow user_name we will write
     * into stored_passwd
     */
    
    /*
     * Note that the order of declared variables also
     * plays a role. When the stack frame is created
     * the parameters are pushed onto the frame in
     * the opposite order of their declaration
     * followed by the local variables.
     */
    fprintf(stdout, "stored: %s\n", stored_psswd);

    fprintf(stdout, "user name > ");
    scanf("%s", user_name);
    
    fprintf(stdout, "user psswd > ");
    scanf("%s", user_psswd);

    fprintf(stdout, "asked user name: %s\n", user_name);
    fprintf(stdout, "asked psswd: %s\n", user_psswd);

    fprintf(stdout, "stored: %s\n", stored_psswd);
    if (!strcmp(stored_psswd, user_psswd))
        fprintf(stdout, "LOGGED-IN\n");
    else
        fprintf(stderr, "WRONG-PASSWORD\n");

    return EXIT_SUCCESS;
}
