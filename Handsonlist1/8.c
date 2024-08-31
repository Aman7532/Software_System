// Aman Agarwal
// MT2024017

// Write a program to open a file in read only mode, read line by line and display each line as it is read.Close the file when end of file is reached.

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error while opening file");
        return 1;
    }

    char content[1024];
    int i = 0;

    while (read(fd1, &content[i], 1) > 0)
    {
        if (content[i] == '\n')
        {
            content[i] = '\0'; // Null-terminate the string
            printf("%s\n", content);
            memset(content, 0, sizeof(content));
            i = 0;
        }
        else
        {
            i++;
        }
    }

    close(fd1);
    return 0;
}
/* Hello World
Welcome to C Programming
*/
