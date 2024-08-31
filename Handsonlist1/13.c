// Aman Agarwal
// MT2024017

// Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    fd_set readFDSet, writeFDSet;
    struct timeval time;
    int output;

    // Initialize the file descriptor sets
    FD_ZERO(&readFDSet);
    FD_ZERO(&writeFDSet);
    FD_SET(STDIN_FILENO, &readFDSet);   // Monitor stdin for readability
    FD_SET(STDOUT_FILENO, &writeFDSet); // Monitor stdout for writability

    // Set the timeout to 10 seconds
    time.tv_sec = 10;
    time.tv_usec = 0;

    // Wait for events
    output = select(FD_SETSIZE, &readFDSet, &writeFDSet, NULL, &time);

    if (output == -1)
        perror("ERROR ");
    else if (output > 0)
        printf("The data is now available\n");
    else
        printf("No data was given for 10 seconds\n");

    return 0;
}
/*
The data is now available
*/