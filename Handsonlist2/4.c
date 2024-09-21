// Aman Agarwal
// MT2024017
//  Question : Write a program to measure how much time is taken to execute 100 `getppid()` system call. Use time stamp counter.

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

void main()
{
    int start, end, pid;
    int iter = 0;

    start = __rdtsc();
    while (iter < 100)
    {
        pid = getpid();
        iter++;
    }
    end = __rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken : %d ns \n", (int)((end - start) / 2.4));
}

/* Output:
   PID: 1234
   Time taken : 420 ns
*/
