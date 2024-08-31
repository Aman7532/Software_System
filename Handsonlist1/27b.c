// AMAN AGARWAL
// MT2024017

/*
write a program to execute ls -Rl by the following system calls
b. execlp
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *path = "ls";
    execlp(path, path, "-Rl", NULL);

    // execlp only returns on error
    perror("execlp failed");
    return 1;
}
