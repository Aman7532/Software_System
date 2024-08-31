// Aman Agarwal
// MT2024017

/*
Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    struct stat statbuf;
    int fileDescriptor = open(argv[1], O_RDONLY);

    if (fileDescriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }

    if (fstat(fileDescriptor, &statbuf) == -1)
    {
        perror("Error getting file status");
        close(fileDescriptor);
        return 1;
    }

    if (S_ISREG(statbuf.st_mode))
        write(STDOUT_FILENO, "Regular File\n", 13);
    else if (S_ISDIR(statbuf.st_mode))
        write(STDOUT_FILENO, "Directory File\n", 15);
    else if (S_ISCHR(statbuf.st_mode))
        write(STDOUT_FILENO, "Character File\n", 15);
    else if (S_ISBLK(statbuf.st_mode))
        write(STDOUT_FILENO, "Block File\n", 11);
    else if (S_ISFIFO(statbuf.st_mode))
        write(STDOUT_FILENO, "FIFO File\n", 10);
    else if (S_ISLNK(statbuf.st_mode))
        write(STDOUT_FILENO, "Symbolic Link File\n", 19);
    else if (S_ISSOCK(statbuf.st_mode))
        write(STDOUT_FILENO, "Socket\n", 7);
    else
        write(STDOUT_FILENO, "Unknown File Type\n", 18);

    close(fileDescriptor);
    return 0;
}
/*
Regular File
*/
