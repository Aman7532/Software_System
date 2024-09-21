// Aman Agarwal
// MT2024017
//  Question : Write two programs: first program is waiting to catch `SIGSTOP` signal, the second program will send the signal (using `kill` system call). Find out whether the first program is able to catch the signal or not.

// This program catches the `SIGSTOP` signal

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void customHandler()
{
    printf("Received SIGSTOP signal!\n");
    _exit(0);
}

void main()
{
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);

    signal(SIGSTOP, customHandler);

    printf("Putting the process to sleep for 15s\n");
    sleep(15);
}

/*
Output:
Process ID: 22979
Putting the process to sleep for 15s
*/
