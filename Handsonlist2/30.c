// Aman Agarwal
// MT2024017

/* Question : Write a program to create a shared memory.
    1. Write some data to the shared memory
    2. Attach with `O_RDONLY` and check whether you are able to overwrite.
    3. Detach the shared memory
    4. Remove the shared memory
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    key_t shmKey;
    int shmIdentifier;
    ssize_t shmSize = 20;
    char *shmPointer, *rdOnlyShmPointer;

    shmKey = ftok(".", 1);

    if (shmKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    shmIdentifier = shmget(shmKey, shmSize, IPC_CREAT | 0700);

    if (shmIdentifier == -1)
    {
        perror("Error while getting Shared Memory!");
        _exit(0);
    }

    // ======================== 1 ========================
    shmPointer = shmat(shmIdentifier, (void *)0, 0);

    if (shmPointer == (char *)-1)
    {
        perror("Error while attaching address space!");
        _exit(0);
    }

    printf("Press enter to write to the shared memory!\n");
    getchar();

    sprintf(shmPointer, "Yolo"); // Writing to the shared memory

    printf("Press enter to read from the shared memory!\n");
    getchar();

    printf("Data from shared memory: %s\n", shmPointer); // Reading from the shared memory
    // ===================================================

    // ======================== 2 ========================
    rdOnlyShmPointer = shmat(shmIdentifier, (void *)0, SHM_RDONLY);
    if (rdOnlyShmPointer == (char *)-1)
    {
        perror("Error while attaching address space!");
        _exit(0);
    }

    // Uncommenting the next line will cause a segmentation fault
    // sprintf(rdOnlyShmPointer, "Yolo"); // Writing to the shared memory

    printf("Press enter to read from the shared memory!\n");
    getchar();

    printf("Data from shared memory: %s\n", rdOnlyShmPointer); // Reading from the shared memory
    // ===================================================

    // ======================== 3 ========================
    printf("Detaching pointer to shared memory!\n");
    shmdt(shmPointer);
    shmdt(rdOnlyShmPointer);
    // ===================================================

    // ======================== 4 ========================
    printf("Press enter to delete the shared memory!\n");
    getchar();

    shmctl(shmIdentifier, IPC_RMID, NULL); // Delete Shared Memory
    // ===================================================
}

/*
Output:
Data from shared memory: Yolo
Data from shared memory: Yolo
Detaching pointer to shared memory!
Shared memory removed successfully.
*/
