// Aman Agarwal
// MT2024017

/*
Write a program to perform mandatory locking.
a. Implement write lock
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_WRONLY);
    if (fd == -1)
    {
        perror("Error while opening file");
        return 1;
    }

    struct flock lock = {F_WRLCK, SEEK_SET, 0, 0, 0};
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("Error while locking file");
        close(fd);
        return 1;
    }

    printf("File is locked.\nPress enter to unlock file\n");
    getchar();

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("Error while unlocking file");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
/*
File is locked.
Press enter to unlock file
*/