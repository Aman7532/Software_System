// Aman Agarwal
// MT2024017
//  Question : Write a separate program using signal system call to catch `SIGSEGV`

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    signalStatus = signal(SIGSEGV, callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGSEGV); // Send segmentation fault signal
}

/* Output:
   Signal SIGSEGV has been caught!
*/
