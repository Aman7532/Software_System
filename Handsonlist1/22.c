// AMAN AGARWAL
// MT2024017

// Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fork();
    int fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char buf[27];
    snprintf(buf, sizeof(buf), "Written by process %d\n", getpid());
    write(fd, buf, sizeof(buf) - 1); // Exclude the null terminator

    close(fd);
    return 0;
}
/*
Written by process 12345
Written by process 12346
*/
