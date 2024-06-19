#include <stdio.h>
#include <stdbool.h>

#define P 4
#define R 3

int allocated[P][R] = {{0, 1, 0},
                       {2, 0, 0},
                       {3, 0, 2},
                       {2, 1, 1}};

int max[P][R] = {{7, 5, 3},
                 {3, 2, 2},
                 {9, 0, 2},
                 {2, 2, 2}};

int available[R] = {3,3,2};

bool flagged[P];

int safeSeq[P];
int count = -1;

bool allflagged(){
    for (int i=0;i<P;i++){
        if (!flagged[i]){return false;}
    }
    return true;
}

bool isSafe(int pid){
    for (int i=0;i<R;i++){
        if (max[pid][i]>available[i]){return false;}
    }
    return true;
}

void execute(int pid){
    for (int i=0;i<R;i++){
        available[i] += max[pid][i];
    }
    safeSeq[++count] = pid;
    flagged[pid] = true;
}

bool avl[P];

void checkAvl(){
    for (int i=0;i<P;i++){
        avl[i] = false;
    }
    for (int i=0;i<P;i++){
        if (!flagged[i] && isSafe(i)){
            avl[i] = true;
        }
    }
}

int min(bool *arr){
    for (int i=0;i<P;i++){
        if (arr[i]==true){return i;}
    }
    return -1;
}

void bankers(){

    for (int i=0;i<P;i++){
        flagged[i] = false;
    }

    int pid = 0;

    while (!allflagged()){
        checkAvl();
        pid = min(avl);
        if (min(avl)==-1){break;}
        execute(pid);
    }
    if (count!=P-1){printf("not successful\n");}
    else{
        printf("successful\n");
        for (int i=0;i<=count;i++){
            printf("P%d ",safeSeq[i]+1);
        }
        printf("\n");
    }
}

int main(){
    bankers();
    return 0;
}