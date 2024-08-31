// Aman Agarwal
// MT2024017

// Write a program to copy file1 into file2 ($cp file1 file2).

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <source file> <destination file>\n", argv[0]);
        return 1;
    }

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        printf("Error while opening source file\n");
        return 1;
    }

    int fd2 = open(argv[2], O_WRONLY | O_CREAT, S_IRWXU);
    if (fd2 == -1)
    {
        printf("Error while opening or creating destination file\n");
        close(fd1);
        return 1;
    }

    char content;
    while (read(fd1, &content, 1) > 0)
    {
        write(fd2, &content, 1);
    }

    printf("file copied\n");
    close(fd1);
    close(fd2);
    return 0;
}
// file copied
