// Aman Agarwal
// MT2024017
//  Question : Write a program to implement semaphore to protect any critical section - Protect multiple pseudo resources (may be two) using counting semaphore

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char *filename = "./sample-files/lorem-ipsum.txt";

    int fileDescriptor;
    ssize_t readBytes;
    char data[1000];

    key_t semKey;
    int semIdentifier;
    int semctlStatus;
    int semopStatus;

    fileDescriptor = open(filename, O_RDONLY);
    if (fileDescriptor == -1)
    {
        perror("Error while creating / opening the ticket file!");
        _exit(0);
    }

    union semun
    {
        int val;
    } semSet;

    semKey = ftok(".", 331);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semIdentifier = semget(semKey, 1, 0);
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700);
        if (semIdentifier == -1)
        {
            perror("Error while creating semaphore!");
            _exit(1);
        }

        semSet.val = 2;
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error while initializing the semaphore!");
            _exit(1);
        }
    }

    struct sembuf semOp;
    semOp.sem_num = 0;
    semOp.sem_flg = IPC_NOWAIT;

    printf("Press enter to obtain lock for the critical section!\n");
    getchar();

    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }

    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");

    readBytes = read(fileDescriptor, &data, 1000);
    if (readBytes == -1)
    {
        perror("Error while reading from sample file!");
        _exit(0);
    }
    else if (readBytes == 0)
        printf("No data exists!\n");
    else
        printf("Sample data: \n%s\n", data);

    printf("\nPress enter key to exit critical section!\n");
    getchar();

    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }

    close(fileDescriptor);
}

// Output:
// Obtained lock on critical section!
// Sample data:
// Hello
