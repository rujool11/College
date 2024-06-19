#include <stdio.h>
#include <stdbool.h>
int bt[50] = {7,1,5,6};
int wt[50];
int tat[50];
int n = 4;

void findwait(){
    wt[0]=0;
    for (int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
}

void findtat(){
    for (int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
    }
}

void sjf(){
    printf("Pid\t\tBT\t\tTAT\t\tWT\n");
    findwait();
    findtat();
    for (int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],tat[i],wt[i]); 
        
    }
}

int main(){
    sjf();
    return 0;
}