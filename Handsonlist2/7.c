// Aman Agarwal
// MT2024017
//  Question : Write a simple program to print the created thread IDs.

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *sampleFunction(void *data)
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
    return NULL; // Added return statement for thread function
}

void main()
{
    pthread_t threadID;

    // Create thread
    if (pthread_create(&threadID, NULL, sampleFunction, NULL))
        perror("Error while creating thread");

    pthread_join(threadID, NULL); // Added join to wait for thread completion
}

/* Output:
   Running in thread with thread ID: 139657294924032
*/
