// Aman Agarwal
// MT2024017
//  Question : Write a separate program using sigaction system call to catch `SIGSEGV` signal

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGSEGV (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status;
    struct sigaction action;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGSEGV, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
    {
        raise(SIGSEGV);
    }
}

/*
Output:
Caught signal SIGSEGV (11).
*/
