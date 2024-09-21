// Aman Agarwal
// MT2024017
//  Question: Write two programs so that both can communicate by FIFO - Use one way communication.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char buffer[100];             // Buffer to store received data
    int fileDescriptor;           // File descriptor of the FIFO file
    char *fifoFile = "./20-fifo"; // Path name of the FIFO file
    int readBytes;                // Number of bytes read from the FIFO file

    fileDescriptor = open(fifoFile, O_RDONLY);
    if (fileDescriptor == -1)
        perror("Error while opening FIFO file for reading");
    else
    {
        readBytes = read(fileDescriptor, buffer, sizeof(buffer));
        if (readBytes == -1)
            perror("Error while reading from the file!");
        else
        {
            buffer[readBytes] = '\0'; // Null-terminate the received string
            printf("Received: %s\n", buffer);
        }
        close(fileDescriptor);
    }
}

/*
Output:
Received: Sending data at warp speed!
*/
