// AMAN AGARWAL
// MT2024017

/*
Write a program, call fork and print the parent and child process id.
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    printf("Parent process ID = %d\n", getpid());
    int pid = fork();
    if (pid != 0)
        printf("Child process ID = %d\n", pid);
    return 0;
}
/*
Parent process ID = 12345
Child process ID = 12346
*/