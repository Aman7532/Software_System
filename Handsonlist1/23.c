// AMAN AGARWAL
// MT2024017

// Write a program to create a Zombie state of the running program

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t childPid;

    if ((childPid = fork()) != 0)
    {
        printf("Parent PID: %d\n", getpid());
        printf("Putting parent to sleep for 100 seconds!\n");
        sleep(100);
        printf("Parent is now awake!\n");
    }
    else
    {
        printf("Child PID: %d\n", getpid());
        printf("Exiting child!\n");
        _exit(0); // Terminate the child process immediately
    }

    return 0;
}
/*
Parent PID: 76338
Putting parent to sleep for 100 seconds!
Child PID: 76339
Exiting child!
*/

/*
After 100s
Parent is now awake!
*/