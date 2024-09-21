// Aman Agarwal
// MT2024017
//  Question: Write two programs so that both can communicate by FIFO - Use two way communications.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "./21-global.h" // Import for FIFO file name & `init` function

void main()
{
    int readBytes, writeBytes;
    int fifoOneFD, fifoTwoFD;
    char data[100];

    init();

    fifoOneFD = open(fifoOneName, O_RDONLY);
    if (fifoOneFD == -1)
    {
        perror("Error while opening fifoOne");
        _exit(0);
    }

    fifoTwoFD = open(fifoTwoName, O_WRONLY);
    if (fifoTwoFD == -1) // Fixed: should check fifoTwoFD
    {
        perror("Error while opening fifoTwo");
        _exit(0);
    }

    readBytes = read(fifoOneFD, data, sizeof(data));
    if (readBytes == -1)
    {
        perror("Error while reading from FIFO fifoOne!");
        _exit(0);
    }

    data[readBytes] = '\0'; // Null-terminate the received string
    printf("Data from FIFO: %s\n", data);

    writeBytes = write(fifoTwoFD, "From 21b to 21a", 15);
    if (writeBytes == -1)
        perror("Error while writing to FIFO fifoTwo!");

    close(fifoOneFD);
    close(fifoTwoFD);
}

/*
Output:
Data from FIFO: From 21a to 21b
*/
