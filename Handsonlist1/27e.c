// AMAN AGARWAL
// MT2024017

/*
write a program to execute ls -Rl by the following system calls
d. execvp
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *path = "ls";
    char *argv[] = {path, "-Rl", NULL};
    execvp(path, argv);

    // execvp only returns on error
    perror("execvp failed");
    return 1;
}
