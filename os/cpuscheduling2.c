#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 3
int processes[n] = {1,2,3};
int burstTimes[n] = {10,5,8};
int priorityValues[n] = {2,0,1};

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void priority(){
    int i,j,a,m,t;
    int sum;
    int b[n] = {10,5,8};
    int index[n] = {1,2,3};
    int p[n] = {2,0,1};
    
    for (i=0;i<n;i++){
        a = p[i],m=i;
        for (j=i;j<n;j++){
            if (p[j]>a){
                a = p[j];
                m=j;
            }
        }
        
        swap(&p[i],&p[m]);
        swap(&b[i],&b[m]);
        swap(&index[i],&index[m]);
    }
    
    t=0;
    printf("Order of execution: \n");
    for (i=0;i<n;i++){
        printf("process %d is executed from %d to %d\n",index[i],t,t+b[i]);
        t+=b[i];
    }
    printf("\nprocess id    burstTime   wait time   turnaround time\n");
    int waittime=0;
    sum = waittime;
    for (i=0;i<n;i++){
        printf("P%d               %d          %d            %d\n",index[i],b[i],waittime,waittime+b[i]);
        sum = sum + waittime;
        waittime+=b[i];
    }
    float avgwaittime = sum*1.0/n;
    printf("avg wait time is %f\n",avgwaittime);
}

int roundrobin(){
    int total = 0,counter = 0,i;
    int x = n;
    int tempburstTimes[n] = {10,8,7};
    int bt[n] = {10,8,7};
    int at[n] = {0,1,2};
    int waittime=0,tat=0;
    int timeslot = 5;
    
    printf("process id      burst time      turnaround time   wait time\n  ");
    for (total,i=0;x!=0;){
        if (tempburstTimes[i]<=timeslot && tempburstTimes[i]>0){
            total += tempburstTimes[i];
            tempburstTimes[i] = 0;
            counter = 1;
        }
        else if (tempburstTimes[i]>0){
            tempburstTimes[i] = tempburstTimes[i] - timeslot;
            total += timeslot;
        }
        if (tempburstTimes[i]==0 && counter==1){
            x--;
            printf("process no %d\t\t%d\t %d\t\t\t%d\n",i+1,bt[i],total-at[i],total-at[i]-bt[i]);
            waittime = waittime + total - at[i] - bt[i];
            tat += total - at[i];
            counter = 0;
        }
        if (i==n-1){
            i=0;
        }
        else if (at[i+1]<=total){
            i++;
        }
        else{
            i=0;
        }
    }
    float avgwaittime = waittime*1.0/n;
    printf("avg waiting time = %f\n",avgwaittime);
}

int main(){
    printf("Rujool Patil 21BCT0263 Lab 2\n");
    printf("\nPRIORITY\n");
    priority();
    printf("\nROUND ROBIN\n");
    roundrobin();
    return 0;}