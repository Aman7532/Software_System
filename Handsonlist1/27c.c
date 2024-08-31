// AMAN AGARWAL
// MT2024017

/*
write a program to execute ls -Rl by the following system calls
c. execle
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[], char *env[])
{
    char *path = "/bin/ls";
    execle(path, path, "-Rl", "27c_example/", NULL, env);

    // execle only returns on error
    perror("execle failed");
    return 1;
}
