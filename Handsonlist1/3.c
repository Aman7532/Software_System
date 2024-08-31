// Aman Agarwal
// MT2024017

// Write a program to create a file and print the file descriptor value. Use creat ( ) system call

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int status = creat(argv[1], S_IRWXU);
    if (status == -1)
        perror("Error");
    else
        printf("success");
    return 0;
}

// success