// AMAN AGARWAL
// MT2024017

// Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).

#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main()
{
    int pid = getpid();

    // Get the current scheduling policy of the process
    int sched_policy = sched_getscheduler(pid);
    if (sched_policy == -1)
    {
        perror("Error getting scheduling policy");
    }
    else
    {
        switch (sched_policy)
        {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
            break;
        }
    }

    int choice;
    printf("Select scheduling policy to change to:\n1: SCHED_FIFO\n2: SCHED_RR\n3: SCHED_OTHER\n");
    scanf("%d", &choice);

    struct sched_param param;
    switch (choice)
    {
    case 1:
        param.sched_priority = 99;
        sched_setscheduler(pid, SCHED_FIFO, &param);
        break;
    case 2:
        param.sched_priority = 99;
        sched_setscheduler(pid, SCHED_RR, &param);
        break;
    case 3:
        param.sched_priority = 0;
        sched_setscheduler(pid, SCHED_OTHER, &param);
        break;
    default:
        perror("Invalid choice");
        return 1;
    }

    // Print the new scheduling policy
    sched_policy = sched_getscheduler(pid);
    if (sched_policy == -1)
    {
        perror("Error getting scheduling policy");
    }
    else
    {
        switch (sched_policy)
        {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
            break;
        }
    }

    return 0;
}
