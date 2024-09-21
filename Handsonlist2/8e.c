// Aman Agarwal
// MT2024017
//  Question : Write a separate program using signal system call to catch `SIGALRM` (use `setitimer` system call)

#include <sys/time.h>
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
    int timerStatus;
    __sighandler_t signalStatus;

    struct itimerval timer;

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    timerStatus = setitimer(ITIMER_REAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

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
