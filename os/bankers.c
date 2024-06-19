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

int resources[R] = { 10, 5, 7 };


int available[R];

bool flagged[P];

int safeSeq[P];
int count = -1;

int min(bool* avl){
    for (int i=0;i<P;i++){
        if (avl[i] == true){
            return i;
        }
    }
    return -1;
}

int sum(int allocated[P][R],int x){
    int sum = 0;
    for (int i=0;i<P;i++){
        sum += allocated[i][x];
    }
    return sum;
}

bool allflagged(){
    for (int i=0;i<P;i++){
        if (flagged[i] == false){return false;}
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
    flagged[pid] = true;
    for (int i=0;i<R;i++){
        available[i] += max[pid][i];
    }
    return;
}

bool avl[P];

void checkAvail(){
    for (int i=0;i<P;i++){
        avl[i] = false;
    }
    for (int i=0;i<P;i++){
        if (!flagged[i] && isSafe(i)){
            avl[i] = true;
        }
    }
}

void bankers(){
    
    for (int i=0;i<P;i++){
        flagged[i] = false;
    }

    for (int i=0;i<R;i++){
        available[i] = resources[i] - sum(allocated,i);
    }

    int pid = 0;

    while (!allflagged()){
        // if (isSafe(pid) && !flagged[pid]){
        //     execute(pid);
        //     safeSeq[++count] = pid+1;
        // }
        // if (pid<P){pid++;}
        // else{
        //     pid = 0;
        // }
        checkAvail();
        for (int i=0;i<P;i++){
            printf("%d ",avl[i]);
        }
        printf("\n");
        if (min(avl) == -1){
            break;
        }
        execute(min(avl));
        safeSeq[++count] = min(avl)+1;
    }
    if (count==P-1){printf("safe sequence found\n");}
    else{
        printf("no safe sequence\n");
    }
    for (int i=0;i<P;i++){
        printf("P%d ",safeSeq[i]);
    }
    printf("\n");

}

int main(){
    bankers();
    return 0;
}