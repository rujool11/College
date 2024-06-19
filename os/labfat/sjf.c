#include <stdio.h>
#include <stdbool.h>
int wt[50];
int bt[50] = {5, 2, 3, 6};
int proc[50] = {1, 2, 3, 4};
int n = 4;
int tat[50];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



void findwait()
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void findtat()
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
}

void sjf()
{
    printf("Pid\t\tBT\t\tTAT\t\tWT\n");
    int index;
    for (int i = 0; i < n; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[index])
            {
                swap(&bt[index], &bt[j]);
                swap(&proc[index], &proc[j]);
            }
        }
    }
    findwait();
    findtat();
    for (int i = 0; i < n; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (proc[j] < proc[index])
            {
                swap(&proc[index], &proc[j]);
                swap(&bt[index], &bt[j]);
                swap(&wt[index], &wt[j]);
                swap(&tat[index], &tat[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i], bt[i], tat[i], wt[i]);
    }
}

int main()
{
    sjf();
    return 0;
}