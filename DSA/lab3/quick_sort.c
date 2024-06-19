#include <stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i<j){
        while (arr[i]<=pivot){
            i++;
        }
        while (arr[j]>pivot){
            j--;
        }
        if (i<j){
            swap(&arr[i],&arr[j]);
            }
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void QuickSort(int arr[],int low, int high){
    if (low<high){
        int pivot_index = Partition(arr,low,high);
        QuickSort(arr,low,pivot_index-1);
        QuickSort(arr,pivot_index+1,high);
    }
}

int main(){
    int size; 
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    QuickSort(arr,0,size-1);
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
return 0;}