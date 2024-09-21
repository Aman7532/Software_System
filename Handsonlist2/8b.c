// Aman Agarwal
// MT2024017
//  Question : Write a separate program using signal system call to catch `SIGINT`

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("\nSignal SIGINT has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    signalStatus = signal(SIGINT, callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        while (1)
            ;
}

/* Output:
   Signal SIGINT has been caught!
*/
