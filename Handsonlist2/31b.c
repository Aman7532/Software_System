// Aman Agarwal
// MT2024017

// Question : Write a program to create a semaphore and initialize value to the semaphore. - Create a counting semaphore

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    key_t semKey;
    int semIdentifier;
    int semctlStatus;

    union semun
    {
        int val; // Value of the semaphore
    } semSet;

    semKey = ftok(".", 2);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semIdentifier = semget(semKey, 1, IPC_CREAT | 0777);

    if (semIdentifier == -1)
    {
        perror("Error while creating semaphore!");
        _exit(1);
    }

    semSet.val = 10; // 10 -> counting semaphore

    semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);

    if (semctlStatus == -1)
    {
        perror("Error while initializing semaphore!");
        _exit(1);
    }

    printf("Counting semaphore created and initialized to %d successfully.\n", semSet.val);
}

/*
Output:
Counting semaphore created and initialized to 10 successfully.
*/
