#include<stdio.h>
#include<conio.h>

struct process
{
    int pid, arrT, execT, waitT, TR;
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
            if(p[j].arrT>p[j+1].arrT)
                swap(&p[j], &p[j+1]);
        }
    }
}

int main()
{
    int i=0, n=0, clock=0, idle[n];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    printf("\n\n");

    for(i=0; i<n; i++)
    {
        printf("Enter process id: ");
        scanf("%d", &p[i].pid);

        printf("Enter arrival time: ");
        scanf("%d", &p[i].arrT);

        printf("Enter execution time: ");
        scanf("%d", &p[i].execT);

        printf("\n\n");
    }

    sort(p, n);

    printf("PID   AT    ET    WT    TR \n\n");
    for(i=0; i<n; i++)
    {
        if(p[i].arrT>=clock)
        {
            idle[i]= p[i].arrT - clock;
            clock= clock + p[i].execT + idle[i];
            p[i].waitT= 0;
        }
        else
        {
            p[i].waitT= clock - p[i].arrT;
            {
                //some actual work
            }
            clock= clock + p[i].execT;
            idle[i]= 0;
        }
        p[i].TR= clock - p[i].arrT;
        if(idle[i]>0)
            printf("\nCPU Idle for %d sec\n\n", idle[i]);
        printf(" %d%6d%6d%6d%6d\n", p[i].pid, p[i].arrT, p[i].execT, p[i].waitT, p[i].TR);
    }
    return 0;
}
