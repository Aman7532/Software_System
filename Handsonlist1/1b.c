// Aman Agarwal
// MT2024017

/*
hard link (link system call)
*/

#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    // hardLink
    // argv[1] -> File path
    // argv[2] -> Hard Link File path
    int status = link(argv[1], argv[2]);
    if (status == -1)
    {
        printf("Error");
    }
    else
    {
        printf("Success");
    }
    return 0;
}

// output
// Success
