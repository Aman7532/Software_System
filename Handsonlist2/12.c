// Aman Agarwal
// MT2024017
//  Question : Write a program to create an orphan process. Use `kill` system call to send `SIGKILL` signal to the parent process from the child process.

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    pid_t childPid;
    int killStatus;

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (childPid == 0)
    {
        // Child process
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        killStatus = kill(getppid(), SIGKILL);

        if (killStatus == 0)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        // Parent process
        while (1)
            ;
    }
}

/*
Output:
Child PID: 22547
Parent PID: 22546
*/
