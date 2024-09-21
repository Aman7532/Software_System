// Aman Agarwal
// MT2024017
//  Question : Write a separate program (for each time domain) to set a interval timer in 10s and 10ms - `ITIMER_PROF`

#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void main(int argc, char *argv[])
{
    struct itimerval timer;
    int timerStatus;

    if (argc != 2)
    {
        printf("Pass 1 for 10s timer or 2 for 10ms timer\n");
        _exit(0);
    }

    switch (argv[1][0])
    {
    case '1':
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
        break;

    case '2':
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
        break;

    default:
        printf("Invalid option. Use 1 for 10s or 2 for 10ms.\n");
        _exit(0);
    }

    timerStatus = setitimer(ITIMER_PROF, &timer, NULL);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    while (1)
        ;
}

/* Output:
   Timer set for 10 seconds.
   Timer set for 10 milliseconds.
*/
