// Aman Agarwal
// MT2024017

/*
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = open("/Users/aman/Desktop/Handsonlist1/17.txt", O_RDWR);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    struct flock l = {F_WRLCK, SEEK_SET, 0, 0, 0};
    if (fcntl(fd, F_SETLKW, &l) == -1)
    {
        perror("Error locking file");
        close(fd);
        return 1;
    }
    printf("File is locked\n");

    char buf[10];
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    if (n == -1)
    {
        perror("Error reading from file");
        l.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &l);
        close(fd);
        return 1;
    }

    buf[n] = '\0'; // Null-terminate the buffer

    int buf_int = atoi(buf);                   // Convert buffer to integer
    buf_int += 1;                              // Increment the number
    snprintf(buf, sizeof(buf), "%d", buf_int); // Convert integer back to string

    lseek(fd, 0, SEEK_SET); // Reset file offset to the beginning
    if (write(fd, buf, strlen(buf)) == -1)
    {
        perror("Error writing to file");
        l.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &l);
        close(fd);
        return 1;
    }

    printf("%d\n", buf_int);

    getchar(); // Wait for user input before unlocking

    l.l_type = F_UNLCK; // Unlock the file
    if (fcntl(fd, F_SETLKW, &l) == -1)
    {
        perror("Error unlocking file");
        close(fd);
        return 1;
    }
    printf("File is unlocked\n");

    close(fd);
    return 0;
}
/*
File is unlocked
*/
