// C program for implementation of FCFS
// scheduling
#include <stdio.h>
// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n,
                     int bt[], int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)

        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n,
                        int bt[], int wt[], int tat[])
{

    // bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);

    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes Burst time Waiting time Turn around time\n");

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d ", (i + 1));
        printf("%d", bt[i]);
        printf("%d", wt[i]);
        printf("%d\n", tat[i]);
    }
    int s = (float)total_wt / (float)n;
    int t = (float)total_tat / (float)n;
    printf("Average waiting time = %d", s);
    printf("\n");
    printf("Average turn around time = %d ", t);
}
// Driver code
int main()
{

    // process id's
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    // Burst time of all processes
    int burst_time[] = {10, 5, 8};
    findavgTime(processes, n, burst_time);
    return 0;
}
