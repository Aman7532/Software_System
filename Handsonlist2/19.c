// Aman Agarwal
// MT2024017
//  Question: Create a FIFO file by `mkfifo` library function and `mknod` system call

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char *mkfifoName = "./mymkfifo";    // File name of FIFO file created using `mkfifo`
    char *mknodName = "./mymknod-fifo"; // File name of FIFO file created using `mknod`

    int mkfifo_status, mknod_status; // 0 -> Success, -1 -> Error

    // Using `mkfifo` library function
    mkfifo_status = mkfifo(mkfifoName, S_IRWXU);

    if (mkfifo_status == -1)
        perror("Error while creating FIFO file with mkfifo!");
    else
        printf("Successfully created FIFO file with mkfifo. Check using `ll` or `ls -l` command!\n");

    // Using `mknod` system call
    mknod_status = mknod(mknodName, S_IFIFO | S_IRWXU, 0);

    if (mknod_status == -1)
        perror("Error while creating FIFO file with mknod!");
    else
        printf("Successfully created FIFO file with mknod. Check using `ll` or `ls -l` command!\n");
}

/*
Output:
Successfully created FIFO file with mkfifo. Check using `ll` or `ls -l` command!
Successfully created FIFO file with mknod. Check using `ll` or `ls -l` command!
*/
