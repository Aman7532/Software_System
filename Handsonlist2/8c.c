// Aman Agarwal
// MT2024017
//  Question : Write a separate program using signal system call to catch `SIGFPE`

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("Signal SIGFPE has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    signalStatus = signal(SIGFPE, callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGFPE); // Send a signal associated with floating point error
}

/* Output:
   Signal SIGFPE has been caught!
*/
