// AMAN AGARWAL
// MT2024017

// Write a program to create an orphan process

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t childPid;

    if ((childPid = fork()) != 0)
    {
        printf("Parent PID: %d\n", getpid());
        printf("Putting parent to sleep for 15 seconds\n");
        sleep(15);
        printf("Exiting parent!\n");
        _exit(0); // Terminate the parent process
    }
    else
    {
        printf("Child PID: %d\n", getpid());
        printf("Putting child to sleep for 100 seconds!\n");
        sleep(100);
        printf("Child is now awake!\n");
    }

    return 0;
}
/*
Parent PID: 76578
Putting parent to sleep for 15 seconds
Child PID: 76579
Putting child to sleep for 100 seconds!
 */