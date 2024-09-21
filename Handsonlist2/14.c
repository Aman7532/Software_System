// Aman Agarwal
// MT2024017
//  Question: Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int pipefd[2];                // pipefd[0] -> read, pipefd[1] -> write
    char *writeBuffer = "Yolo!!"; // Data sent through the pipe
    char readBuffer[20];          // Buffer for reading data
    int pipeStatus;
    int readBytes, writeBytes;

    // Creating a pipe
    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating the pipe!");
    else
    {
        printf("Writing to the pipe!\n");
        writeBytes = write(pipefd[1], writeBuffer, sizeof(writeBuffer));
        if (writeBytes == -1)
            perror("Error while writing to pipe!");
        else
        {
            printf("Now reading from the pipe!\n");
            readBytes = read(pipefd[0], readBuffer, writeBytes);
            if (readBytes == -1)
                perror("Error while reading from pipe!");
            else
            {
                readBuffer[readBytes] = '\0'; // Null-terminate the string
                printf("Data from pipe: %s\n", readBuffer);
            }
        }
    }
}

/*
Output:
- Writing to the pipe!
- Now reading from the pipe!
- Data from pipe: Yolo!!
*/
