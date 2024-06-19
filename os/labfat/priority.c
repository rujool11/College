#include <stdio.h>
#include <stdbool.h>
int p[50] = {2,6,3,1};
int proc[50] = {1,2,3,4};
int bt[50] = {3,7,2,4};
int wt[50];
int tat[50];
int n = 4;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void findwait(){
    wt[0] = 0;
    for (int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
}

void findtat(){
    for (int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
    }
}

void priority(){
    int index;
    for (int i=0;i<n;i++){
        index = i;
        for (int j=i+1;j<n;j++){
            if (p[j]<p[index]){
                swap(&proc[index],&proc[j]);
                swap(&bt[index],&bt[j]);
            }
        }
    }
    findwait();
    findtat();
    for (int i=0;i<n;i++){
        index = i;
        for (int j=i+1;j<n;j++){
            if (proc[j]<proc[index]){
                swap(&proc[index],&proc[j]);
                swap(&bt[index],&bt[j]);
                swap(&wt[index],&wt[j]);
                swap(&tat[index],&tat[j]);
            }
        }
    }

    printf("Pid\t\tBT\t\tTAT\t\tWT\n");
    for (int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",proc[i],bt[i],tat[i],wt[i]);
    }
}

int main(){
    priority();
    return 0;
}