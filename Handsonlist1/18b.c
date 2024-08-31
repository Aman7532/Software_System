// Aman Agarwal
// MT2024017

/*
. Write a program to perform Record locking.
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd = open("/Users/aman/Desktop/Handsonlist1/18.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    struct flock rdlock = {F_RDLCK, SEEK_SET, 0, 34, getpid()};
    int id;

    printf("Enter record id: ");
    if (scanf("%d", &id) != 1)
    {
        perror("Error reading input");
        close(fd);
        return 1;
    }

    switch (id)
    {
    case 1:
        rdlock.l_start = 0;
        break;
    case 2:
        rdlock.l_start = 17;
        break;
    case 3:
        rdlock.l_start = 34;
        break;
    default:
        printf("Invalid choice of record!\n");
        close(fd);
        return 1;
    }

    if (fcntl(fd, F_SETLKW, &rdlock) == -1)
    {
        perror("Error locking file");
        close(fd);
        return 1;
    }

    printf("Record %d locked. Press Enter to unlock it...\n", id);
    getchar(); // Consume newline from previous input
    getchar(); // Wait for user input

    rdlock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &rdlock) == -1)
    {
        perror("Error unlocking file");
        close(fd);
        return 1;
    }

    printf("Record is unlocked\n");
    close(fd);
    return 0;
}
