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

int partiton(struct process a[], int low, int high)
{
    int i = low, j = high, pivot = a[low].arrival_time;

    while(i<j)
    {
        while(a[i].arrival_time<=pivot && i<=high)
            i++;

        while(a[j].arrival_time>pivot && j>=low)
            j--;

        if(i<j)
            swap(&a[i], &a[j]);
    }
    swap(&a[low], &a[j]);
    return j;
}

void quickSort(struct process a[], int low, int high)
{
    if(low<=high)
    {
        int q = partiton(a, low, high);

        quickSort(a, low, q-1);
        quickSort(a, q+1, high);
    }
}

int main()
{
    /*
    'clock' variable keeps count of the time in which the process is finished.
    'TQ' variable is the time quantum.
    'count' variable keeps count of the remaining number of processes.
    */
    int i=0, n=0, clock=0, TQ= 2, count;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    count = n;
    struct process p[n];
    //int idle[n];
    printf("\n\n");

    for(i=0; i<n; i++)
    {
        printf("Enter process id: ");
        scanf("%d", &p[i].pid);

        printf("Enter arrival time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Enter execution/burst time: ");
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time= p[i].burst_time;

        printf("\n\n");
    }

    // Sort in ascending order according to arrival_time
    quickSort(p, 0, n-1);

    i=0;
    clock = p[0].arrival_time;
    while(count>0)
    {
        if(i==n || p[i].arrival_time>clock)
        {
            if(count==n-i)
            {
                clock = clock + (p[i].arrival_time - clock);
                //printf("%d\n", clock);
            }
            else
            {
                i=0;
            }

        }

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
