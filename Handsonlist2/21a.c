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

    fifoOneFD = open(fifoOneName, O_WRONLY);
    if (fifoOneFD == -1)
    {
        perror("Error while opening fifoOne");
        _exit(0);
    }

    fifoTwoFD = open(fifoTwoName, O_RDONLY);
    if (fifoTwoFD == -1) // Fixed: should check fifoTwoFD
    {
        perror("Error while opening fifoTwo");
        _exit(0);
    }

    writeBytes = write(fifoOneFD, "From 21a to 21b", 15);
    if (writeBytes == -1)
        perror("Error while writing to FIFO fifoOne!");

    close(fifoOneFD);

    readBytes = read(fifoTwoFD, data, sizeof(data));
    if (readBytes == -1)
    {
        perror("Error while reading from FIFO fifoTwo!");
        _exit(0);
    }

    data[readBytes] = '\0'; // Null-terminate the received string
    printf("Data from FIFO: %s\n", data);

    close(fifoTwoFD);
}

/*
Output:
Data from FIFO: From 21b to 21a
*/
