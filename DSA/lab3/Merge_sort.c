#include <stdio.h>
void MergeArr(int arr[], int low, int mid, int high){
int i, j, k;
int left_temp_s = mid - low + 1;
int right_temp_s = high - mid;
int L[left_temp_s], R[right_temp_s];
for (i = 0; i < left_temp_s; i++){
L[i] = arr[low + i];}
for (j = 0; j < right_temp_s; j++){
R[j] = arr[mid + 1+ j];}
i = 0;
j = 0;
k = low;
while (i < left_temp_s && j < right_temp_s){
    if (L[i] <= R[j]){
        arr[k] = L[i];
        i++;
    } else {
        arr[k] = R[j];
        j++;
    }
    k++;
}
while (i < left_temp_s){
    arr[k] = L[i];
    i++;
    k++;
}
while (j < right_temp_s){
    arr[k] = R[j];
    j++;
    k++;
    }
}

void MergeSort(int arr[],int low, int high){
    if (low<high){
        int mid = low + (high-low)/2; 
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        MergeArr(arr,low,mid,high);
    }
}
int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d\n",size);
    MergeSort(arr,0,size-1);
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
return 0;}