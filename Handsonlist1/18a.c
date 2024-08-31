// Aman Agarwal
// MT2024017

/*
. Write a program to perform Record locking.
a. Implement write lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct record
{
    int id;
    int ticket;
} record;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    record r1 = {1, 1};
    record r2 = {2, 2};
    record r3 = {3, 3};

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char buf[50];

    snprintf(buf, sizeof(buf), "id=%d ticket_no=%d\n", r1.id, r1.ticket);
    if (write(fd, buf, strlen(buf)) == -1)
    {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    snprintf(buf, sizeof(buf), "id=%d ticket_no=%d\n", r2.id, r2.ticket);
    if (write(fd, buf, strlen(buf)) == -1)
    {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    snprintf(buf, sizeof(buf), "id=%d ticket_no=%d\n", r3.id, r3.ticket);
    if (write(fd, buf, strlen(buf)) == -1)
    {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
