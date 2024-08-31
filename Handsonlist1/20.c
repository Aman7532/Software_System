// AMAN AGARWAL
// MT2024017

// Find out the priority of your running program. Modify the priority with nice command

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int priority, newp;
    if (argc != 2)
    {
        printf("Please pass the integer value to be added to the current nice value\n");
        return 1;
    }
    else
    {
        newp = atoi(argv[1]);
        priority = nice(0); // Get the current priority
        printf("Current priority: %d\n", priority);
        priority = nice(newp); // Set new priority by adding `newp`
        printf("New priority: %d\n", priority);
    }
    return 0;
}
/*
Current priority: 0
New priority: 5
*/