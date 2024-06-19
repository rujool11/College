#include <stdio.h>
void swap(int*a,int *b){
    int temp = *a;
    *a= *b;
    *b = temp;
}
int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for (int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<size-1;i++){
        int min = i;
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[min]){
                min = j;}
        }
        swap(&arr[min],&arr[i]);    
    }
    printf("%d\n",size);
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
return 0;}
