// Aman Agarwal
// MT2024017
//  Question : Write a separate program using sigaction system call to catch `SIGINT` signal

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGINT (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status;
    struct sigaction action;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);
}

/*
Output:
Caught signal SIGINT (2)
*/
