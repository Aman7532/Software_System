// Aman Agarwal
// MT2024017

// FIFO (mkfifo Library Function or mknod system call)

#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{

    // Using `mkfifo` library function

    int status = mkfifo("argv[1]", S_IRWXU);
    if (status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
    return 0;
}

// output
// Succesfully created FIFO file. Check using `ll` or `ls -l` command!
