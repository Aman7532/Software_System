// Aman Agarwal
// MT2024017

// Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void main()
{
    while (1)
    {
        creat("./sample-files/file_1", O_CREAT);
        creat("./sample-files/file_2", O_CREAT);
        creat("./sample-files/file_3", O_CREAT);
        creat("./sample-files/file_4", O_CREAT);
        creat("./sample-files/file_5", O_CREAT);
    }
}

// OUTPUT
// FILES CREATED