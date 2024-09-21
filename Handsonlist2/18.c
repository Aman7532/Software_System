// Aman Agarwal
// MT2024017
//  Question : Write a program to find out total number of directories on the `pwd`. Execute `ls -l | grep ^d | wc`. Use only `dup2`.

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

void main()
{
    int pipeCmdOneToTwo[2], pipeCmdTwoToThree[2]; // fd[0] -> read, fd[1] -> write
    int pipeOneStatus, pipeTwoStatus;

    pid_t childOne, childTwo;

    pipeOneStatus = pipe(pipeCmdOneToTwo);
    pipeTwoStatus = pipe(pipeCmdTwoToThree);

    if (pipeOneStatus == -1 || pipeTwoStatus == -1)
        perror("Error while creating the pipes!");
    else
    {
        childOne = fork();

        if (childOne == -1)
            perror("Error while creating first child!");
        else if (childOne == 0)
        {
            // Child One will enter this branch
            close(pipeCmdOneToTwo[1]);   // Close the write end of the first pipe
            close(pipeCmdTwoToThree[0]); // Close the read end of the second pipe

            dup2(pipeCmdOneToTwo[0], STDIN_FILENO); // Reassign stdin
            close(pipeCmdOneToTwo[0]);              // Close the original read end

            execl("/usr/bin/wc", "wc", NULL);
            perror("Error executing wc"); // Handle execl failure
        }
        else
        {
            // Parent will enter this branch
            childTwo = fork();

            if (childTwo == -1)
                perror("Error while creating second child!");
            else if (childTwo == 0)
            {
                // Child Two will enter this branch
                close(pipeCmdOneToTwo[1]);   // Close the write end of the first pipe
                close(pipeCmdTwoToThree[1]); // Close the write end of the second pipe

                dup2(pipeCmdOneToTwo[0], STDIN_FILENO); // Reassign stdin
                close(pipeCmdOneToTwo[0]);              // Close the original read end

                dup2(pipeCmdTwoToThree[1], STDOUT_FILENO); // Reassign stdout
                close(pipeCmdTwoToThree[0]);               // Close the read end

                execl("/usr/bin/grep", "grep", "^d", NULL);
                perror("Error executing grep"); // Handle execl failure
            }
            else
            {
                // Parent will enter this branch
                close(pipeCmdOneToTwo[0]);   // Close the read end of the first pipe
                close(pipeCmdTwoToThree[1]); // Close the write end of the second pipe

                dup2(pipeCmdOneToTwo[1], STDOUT_FILENO); // Reassign stdout
                close(pipeCmdOneToTwo[1]);               // Close the original write end

                execl("/usr/bin/ls", "ls", "-l", NULL);
                perror("Error executing ls"); // Handle execl failure
            }
        }
    }
}

/*
Output:
- This program counts and displays the total number of directories in the current working directory.
*/
