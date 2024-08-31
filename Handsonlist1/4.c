// Aman Agarwal
// MT2024017

// Write a program to open an existing file with read write mode. Try O_EXCL flag also.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main(int argc, char *argv[])
{

    char *filename = argv[1];
    // filename="a.txt"
    int status = open(filename, O_RDWR);

    if (status == -1)
        perror("Error");
    else
        printf("Success");
}

// success