// Aman Agarwal
// MT2024017
//  Question : Write a simple program to send some data from parent to the child process.

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    pid_t childPid;
    int pipefd[2]; // pipefd[0] -> read, pipefd[1] -> write
    int pipeStatus;
    int readBytes, writeBytes;

    char *writeBuffer = "Hello child! It's mom!";
    char readBuffer[50]; // Buffer for reading data

    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating pipe!");
    else
    {
        printf("Pipe created successfully\n");
        childPid = fork();
        if (childPid == -1)
            perror("Error while forking new child!");
        else if (childPid == 0)
        {
            // Child process
            readBytes = read(pipefd[0], readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
                perror("Error while reading from pipe!");
            else
            {
                readBuffer[readBytes] = '\0'; // Null-terminate the string
                printf("Data from parent: %s\n", readBuffer);
            }
        }
        else
        {
            // Parent process
            writeBytes = write(pipefd[1], writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
                perror("Error while writing to pipe!");
        }
    }
}

/*
Output:
Pipe created successfully
Data from parent: Hello chs
*/
