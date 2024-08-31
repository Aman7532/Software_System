// AMAN AGARWAL
// MT2024017

/*
Write a program to execute an executable program.
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <program> [args...]\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    execv(path, &argv[1]);

    // execv only returns on error
    perror("execv failed");
    return 1;
}
