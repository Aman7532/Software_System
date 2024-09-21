// Aman Agarwal
// MT2024017
//  Question : Write a program to send and receive data from parent to child vice versa. Use two way communication.

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int childToParentfd[2], parentToChildfd[2]; // fd[0] -> read, fd[1] -> write
    int childToParentPipeStatus;
    int parentToChildPipeStatus;
    int readBytes, writeBytes;
    char *writeBuffer, readBuffer[100];

    pid_t childPid;

    childToParentPipeStatus = pipe(childToParentfd);
    parentToChildPipeStatus = pipe(parentToChildfd);

    if (childToParentPipeStatus == -1 || parentToChildPipeStatus == -1)
        perror("Error while creating the pipe!");
    else
    {
        childPid = fork();

        if (childPid == -1)
            perror("Error while forking child!");
        else if (childPid == 0)
        {
            // Child process
            close(parentToChildfd[1]); // Close write fd for parent to child
            close(childToParentfd[0]); // Close read fd for child to parent

            // Sending data to parent
            writeBuffer = "Hi mom! It's me!";
            writeBytes = write(childToParentfd[1], writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
                perror("Error while writing to child to parent pipe!");

            // Reading from parent
            readBytes = read(parentToChildfd[0], readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
                perror("Error while reading from parent to child pipe!");
            else
            {
                readBuffer[readBytes] = '\0'; // Null-terminate the string
                printf("The parent said: %s\n", readBuffer);
            }
        }
        else
        {
            close(parentToChildfd[0]); // Close read fd for parent to child
            close(childToParentfd[1]); // Close write fd for child to parent

            // Sending data to child
            writeBuffer = "Hi child! It's me, mom!";
            writeBytes = write(parentToChildfd[1], writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
                perror("Error while writing to parent to child pipe!");

            // Reading from child
            readBytes = read(childToParentfd[0], readBuffer, sizeof(readBuffer));
            if (readBytes == -1)
                perror("Error while reading from child to parent pipe!");
            else
            {
                readBuffer[readBytes] = '\0'; // Null-terminate the string
                printf("The child said: %s\n", readBuffer);
            }
        }
    }
}

/*
Output:
The parent said: Hi child
The child said: Hi mom!
*/
