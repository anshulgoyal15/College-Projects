#include<stdio.h>

struct process
{
    int pid, arrival_time, burst_time, waitT, turnaround_time, remaining_time ;
};

void swap(struct process* a, struct process* b)
{
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct process p[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(p[j].arrival_time>p[j+1].arrival_time)
                swap(&p[j], &p[j+1]);
        }
    }
}

int main()
{
    int i=0, n=0, clock=0, TQ= 2, count;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    count = n;
    struct process p[n];
    int idle[n];
    printf("\n\n");

    for(i=0; i<n; i++)
    {
        printf("Enter process id: ");
        scanf("%d", &p[i].pid);

        printf("Enter arrival time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Enter execution time: ");
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time= p[i].burst_time;

        printf("\n\n");
    }

    sort(p, n);

    //printf("PID   AT    ET    WT    turnaround_time \n\n");
    i=0;
    clock = p[0].arrival_time;
    while(count>0)
    {
        if(i==n || p[i].arrival_time>clock)
            i=0;

        if(p[i].remaining_time>TQ)
        {
            p[i].remaining_time-=TQ;
            clock+=TQ;
        }
        else if(p[i].remaining_time<=TQ && p[i].remaining_time!=0)
        {
            clock+= p[i].remaining_time;
            p[i].turnaround_time = clock - p[i].arrival_time;
            p[i].waitT = p[i].turnaround_time - p[i].burst_time;
            p[i].remaining_time = 0;
            count--;
            printf("%d\t%d\t%d\t%d\n", clock, p[i].pid, p[i].waitT, p[i].turnaround_time);
        }
        i++;
    }
    return 0;
}
