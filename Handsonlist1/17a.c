// Aman Agarwal
// MT2024017

/*
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    printf("Enter ticket number:\t");

    int fd = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);
    if (fd == -1)
    {
        perror("Error while opening file");
        return 1;
    }

    char buf[10];
    ssize_t n = read(STDIN_FILENO, buf, sizeof(buf) - 1);
    if (n == -1)
    {
        perror("Error while reading input");
        close(fd);
        return 1;
    }

    buf[n] = '\0'; // Null-terminate the buffer

    if (write(fd, buf, n) == -1)
    {
        perror("Error while writing to file");
        close(fd);
        return 1;
    }

    printf("Ticket number is stored in file\n");

    close(fd);
    return 0;
}
/*
10
*/