// Aman Agarwal
// MT2024017

// Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

#include <stdio.h>
#include <unistd.h>
int main()
{
    char input_buffer[50];
    // 0 is file descriptor
    //  n is size of input
    int n = read(0, input_buffer, 50);
    write(1, input_buffer, n);
    // 1 is file descriptor
}

// Output
// aa
// aa