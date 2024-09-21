// Aman Agarwal
// MT2024017
//  Question : Write a program to execute `ls -l | wc`. Use `fcntl`

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

void main()
{
    int pipefd[2];
    int pipeStatus;
    pid_t childPid;

    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating the pipe!");
    else
    {
        childPid = fork();

        if (childPid == -1)
            perror("Error while forking child!");
        else if (childPid == 0)
        {
            // Child process
            close(STDIN_FILENO);
            fcntl(pipefd[0], F_DUPFD, STDIN_FILENO); // Reassign STDIN to pipefd[0]
            close(pipefd[1]);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            // Parent process
            close(STDOUT_FILENO);
            fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO); // Reassign STDOUT to pipefd[1]
            close(pipefd[0]);
            execl("/usr/bin/ls", "ls", "-l", NULL);
        }
    }
}

/*
Output:
- Output of `ls -l` piped to `wc`, displaying the line count, word count, and byte count.
*/
