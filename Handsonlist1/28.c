// AMAN AGARWAL
// MT2024017

// Write a program to get maximum and minimum real time priority.

#include <stdio.h>
#include <sched.h>

int main()
{
    printf("Maximum and minimum priorities for SCHED_FIFO:\n");
    printf("Max: %d, Min: %d\n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));

    printf("Maximum and minimum priorities for SCHED_RR:\n");
    printf("Max: %d, Min: %d\n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));

    printf("Maximum and minimum priorities for SCHED_OTHER:\n");
    printf("Max: %d, Min: %d\n", sched_get_priority_max(SCHED_OTHER), sched_get_priority_min(SCHED_OTHER));

    return 0;
}
/*
Maximum and minimum priorities for SCHED_FIFO:
Max: 47, Min: 15
Maximum and minimum priorities for SCHED_RR:
Max: 47, Min: 15
Maximum and minimum priorities for SCHED_OTHER:
Max: 47, Min: 15
*/