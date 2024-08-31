// AMAN AGARWAL
// MT2024017

/*
Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/

#include <stdio.h>
#include <unistd.h>

// Using timestamp counter
unsigned long long rdtsc()
{
    unsigned int low, high;
    __asm__ __volatile__(
        "rdtsc"                 // Read Time Stamp Counter
        : "=a"(low), "=d"(high) // Output operands
        :                       // No input operands
        : "memory"              // Clobbered registers
    );
    return ((unsigned long long)high << 32) | low; // Combine high and low parts
}

int main()
{
    unsigned long long start, end;

    start = rdtsc();

    printf("Process ID: %d\n", getpid());

    end = rdtsc();

    printf("Difference is: %llu\n", end - start);
    return 0;
}

/*
Process ID: 12345
Difference is: 12345678
*/