// AMAN AGARWAL
// MT2024017

// Write a program to display the environmental variable of the user (use environ).

#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
    printf("%s\n", *environ);
    environ += 51;
    printf("%s\n", *environ);

    return 0;
}

// char *environ[] = {"US=John", "Name=Jane", "US=Admin", NULL};

/*
US=John
US=Admin
*/