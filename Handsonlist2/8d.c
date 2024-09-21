// Aman Agarwal
// MT2024017
//  Question : Write a separate program using signal system call to catch `SIGALRM` (use `alarm` system call)

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void callback()
{
    printf("Signal SIGALRM has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus;

    alarm(1);

    signalStatus = signal(SIGALRM, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");
    else
        while (1)
            ;
}

/* Output:
   Signal SIGALRM has been caught!
*/
