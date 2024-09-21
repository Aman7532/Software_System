// Aman Agarwal
// MT2024017
//  Question : Write a simple program to create three threads.

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *sampleFunction(void *data)
{
    printf("Running in thread: %lu\n", pthread_self());
    return NULL; // Added return statement for thread function
}

void main()
{
    pthread_t threadOne, threadTwo, threadThree;

    // Create three threads
    if (pthread_create(&threadOne, NULL, sampleFunction, NULL))
        perror("Error while creating thread one");
    if (pthread_create(&threadTwo, NULL, sampleFunction, NULL))
        perror("Error while creating thread two");
    if (pthread_create(&threadThree, NULL, sampleFunction, NULL))
        perror("Error while creating thread three");

    // Wait for the threads to terminate and then terminate the main process
    pthread_join(threadOne, NULL); // Added join to wait for thread completion
    pthread_join(threadTwo, NULL);
    pthread_join(threadThree, NULL);
}

/* Output:
Running in thread: 6167949312
Running in thread: 6168522752
Running in thread: 6169096192
*/
