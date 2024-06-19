#include <stdio.h>
#include <stdbool.h>

int cyls;
int head;
int reqq[50];
int treq;

bool isIn(int x, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (x == arr[i]) {
            return true;
        }
    }
    return false;
}

void SCAN() {
    int order[50];
    int count = -1;
    for (int i = head; i < cyls; i++) {
        if (isIn(i, reqq, treq)) {
            order[++count] = i;
        }
    }
    for (int i = head - 1; i >= 0; i--) {
        if (isIn(i, reqq, treq)) {
            order[++count] = i;
        }
    }
    int total = (cyls - 1 - head) + (cyls - 1 - order[count]);
    printf("SCAN order ---\n");
    for (int i = 0; i <= count; i++) {
        printf("%d ", order[i]); 
    }
    printf("\n");
    printf("Total head movement = %d\n", total);
}


void CSCAN() {
    int order[50];
    int count = -1;
    for (int i = head; i < cyls; i++) {
        if (isIn(i, reqq, treq)) {
            order[++count] = i;
        }
    }
    for (int i = 0; i < head; i++) {
        if (isIn(i, reqq, treq)) {
            order[++count] = i;
        }
    }
    int total = (cyls - 1 - head) + (cyls-1-0) + (order[count]-0);
    printf("CSCAN order ---\n");
    for (int i = 0; i <= count; i++) {
        printf("%d ", order[i]); 
    }
    printf("\n");
    printf("Total head movement = %d\n", total);
}

int largest(int* arr,int size){
    int ans = arr[0];
    for (int i=0;i<size;i++){
        if (arr[i]>ans){ans=arr[i];}
    }
    return ans;
}

void LOOK(){
    int order[50];
    int count = -1;
    for (int i = head; i < cyls; i++) {
        if (isIn(i, reqq, treq)) {
            order[++count] = i;
        }
    }
    for (int i = head - 1; i >= 0; i--) {
        if (isIn(i, reqq, treq)) {
            order[++count] = i;
        }
    }
    int total = (largest(reqq,treq) - head) + (cyls - 1 - order[count]);
    printf("LOOK order ---\n");
    for (int i = 0; i <= count; i++) {
        printf("%d ", order[i]); 
    }
    printf("\n");
    printf("Total head movement = %d\n", total);

}

int main() {
    printf("Enter the number of cylinders: ");
    scanf("%d", &cyls);
    printf("Enter the head position: ");
    scanf("%d", &head);
    printf("Enter the total number of requests: ");
    scanf("%d", &treq);
    printf("Enter the request queue:\n");
    for (int i = 0; i < treq; i++) {
        scanf("%d", &reqq[i]);
    }
    SCAN();
    CSCAN();
    LOOK();
    return 0;
}
