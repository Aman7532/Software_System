// Aman Agarwal
// MT2024017

// Write a program to find out the opening mode of a file. Use fcntl.

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    int fmode = fcntl(fd, F_GETFL);
    if (fmode == -1)
    {
        perror("Error getting file mode");
        close(fd);
        return 1;
    }

    printf("%d\n", fmode);

    int accessMode = fmode & O_ACCMODE;
    printf("%d\n", accessMode);

    switch (accessMode)
    {
    case O_RDWR:
        printf("O_RDWR\n");
        break;
    case O_WRONLY:
        printf("O_WRONLY\n");
        break;
    case O_RDONLY:
        printf("O_RDONLY\n");
        break;
    default:
        printf("Unknown mode\n");
        break;
    }

    close(fd);
    return 0;
}
/*
0
0
O_RDONLY
*/