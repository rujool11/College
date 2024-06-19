#include <stdio.h>
#include <stdlib.h>
int processes[] = {1,2,3,4,5};
int burstTimes[] = {10,5,8,8,6};
int const n = sizeof(processes)/sizeof(processes[0]);

void findwaitime(int wait[n]){
    int i;
    wait[0] = 0;
    for (i=1;i<n;i++){
        wait[i] = burstTimes[i-1] + wait[i-1];
    }
}

void findturnaroundtime(int turnaround[n],int wait[n]){
    int i;
    for (i=0;i<n;i++){
        turnaround[i] = burstTimes[i] + wait[i];
    }
}

void fcfs(){
    int wait[n],turnaround[n];
    int totalwait = 0,totalturnaround = 0;
    int i;
    
    findwaitime(wait);
    findturnaroundtime(turnaround,wait);
    
    printf("Processes  BurstTime  WaitTime  TurnAroundTime\n");
    for (i=0;i<n;i++){
        totalwait += wait[i];
        totalturnaround  += turnaround[i];
        printf("  %d",(i+1));
        printf("            %d",burstTimes[i]);
        printf("            %d",wait[i]);
        printf("            %d\n",turnaround[i]);
    }
    
    float s = (float)totalwait/(float)n;
    float t = (float)totalturnaround/(float)n;
    
    printf("Avg waiting time : %f\n",s);
    printf("Avg turn around time : %f\n",t);
    
}

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sjf(){
    int wait[n],tat[n];
    int i,j,index,total,totalwait,totalturnaround,temp;
    float avgwt,avgtat;
    for (i=0;i<n;i++){
        index = i;
        for (j=i+1;j<n;j++){
            if (burstTimes[j]<burstTimes[index]){
                index = j;
                temp = burstTimes[i];
                burstTimes[i] = burstTimes[index];
                burstTimes[index] = temp;
                temp = processes[i];
                processes[i] = processes[index];
                processes[index] = temp;
            }
        }
    }
    for (i=1;i<n;i++){
        wait[0] = 0;
        wait[i] = 0;
        for (j=0;j<i;j++){wait[i] += burstTimes[j];
            total += wait[i];
        }
        
    }
    total = 0;
    avgwt = (float)total/(float)n;
    for (i=0;i<n;i++){
    tat[i] = burstTimes[i] + wait[i];
    total+=tat[i];
    }
    printf("Processes  BurstTime  WaitTime  TurnAroundTime\n");
    for (i=0;i<n;i++){
        totalwait += wait[i];
        totalturnaround  += tat[i];
        printf("  %d",(i+1));
        printf("            %d",burstTimes[i]);
        printf("            %d",wait[i]);
        printf("        %d\n",tat[i]);
    }
    
        
    float s = (float)totalwait/(float)n;
    float t = (float)totalturnaround/(float)n;
    
    printf("Avg waiting time : %f\n",s);
    printf("Avg turn around time : %f\n\n",t);
    
}

int main(){
    printf("21BCT0263 Rujool Patil\n");
    printf("both outputs are for randomly chosen sample burst times and processes\n");
    printf("fcfs output: \n");
    fcfs();
    printf("sjf output : \n");
    sjf();
}