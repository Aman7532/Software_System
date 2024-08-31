// AMAN AGARWAL
// MT2024017

// Write a program to run a script at a specific time using a Daemon process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    time_t curr_time, deadline_time;
    struct tm *deadline;

    time(&curr_time); // Get current time in epoch
    deadline = localtime(&curr_time);

    // Set deadline time from command line arguments
    deadline->tm_hour = atoi(argv[1]);
    deadline->tm_min = argv[2] ? atoi(argv[2]) : 0;
    deadline->tm_sec = argv[3] ? atoi(argv[3]) : 0;

    deadline_time = mktime(deadline); // Convert deadline to epoch time

    int child_pid = fork();
    if (child_pid == 0)
    {
        // Child process becomes a daemon
        setsid();
        do
        {
            time(&curr_time); // Get current time
        } while (difftime(deadline_time, curr_time) > 0);
        // Execute command when deadline is reached
        system("echo Current user=$USER");
    }
    else
    {
        exit(0); // Terminate parent process
    }

    return 0;
}
