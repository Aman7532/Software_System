// AMAN AGARWAL
// MT2024017

// Write a program to create three child processes. The parent should wait for a particular child (use `waitpid` system call).

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    pid_t childA, childB, childC, terminatedChild;
    int waitStatus;

    if ((childA = fork()) == 0)
    {
        // Child A
        printf("Child A created...\n");
        printf("Putting child A to sleep for 5 seconds\n");
        sleep(5);
        printf("Child A is now awake!\n");
        _exit(0);
    }
    else
    {
        if ((childB = fork()) == 0)
        {
            // Child B
            printf("Child B created...\n");
            printf("Putting child B to sleep for 10 seconds\n");
            sleep(10);
            printf("Child B is now awake!\n");
            _exit(0);
        }
        else
        {
            if ((childC = fork()) == 0)
            {
                // Child C
                printf("Child C created...\n");
                printf("Putting child C to sleep for 15 seconds\n");
                sleep(15);
                printf("Child C is now awake!\n");
                _exit(0);
            }
            else
            {
                // Parent
                terminatedChild = waitpid(childC, &waitStatus, 0);

                if (terminatedChild == childC)
                {
                    if (WIFEXITED(waitStatus))
                        printf("Child C has terminated with exit status = %d\n", WEXITSTATUS(waitStatus));
                    else
                        printf("Child C has terminated abnormally\n");
                }
            }
        }
    }

    return 0;
}
/*
Child A created...
Putting child A to sleep for 5 seconds
Child B created...
Putting child B to sleep for 10 seconds
Child C created...
Putting child C to sleep for 15 seconds
Child A is now awake!
Child B is now awake!
Child C is now awake!
Child C has terminated with exit status = 0
*/