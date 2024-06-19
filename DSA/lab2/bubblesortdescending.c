#include <stdio.h>
int main(){
    int arr[5] = {5,4,1,2,3},i,j; 
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            if (arr[j]<arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
        }
        }
    }
    for (int k=0;k<5;k++){
        printf("%d ",arr[k]);
    }
    printf("\n");
return 0;}