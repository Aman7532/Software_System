// AMAN AGARWAL
// MT2024017

/*
Write a program to execute an executable program.
a. use some executable program
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

    execv(argv[1], &argv[1]);

    // execv only returns on error
    perror("execv failed");
    return 1;
}
/*
execv failed: No such file or directory
*/