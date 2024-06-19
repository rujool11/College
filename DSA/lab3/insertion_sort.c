#include <stdio.h>
int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for (int k=0;k<size;k++){
        printf("%d ",arr[k]);
    }
} 