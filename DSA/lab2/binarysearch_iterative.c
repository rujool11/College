#include <stdio.h>
#include <math.h>
int BinarySearch(int z[],int n,int key){
    int low = 0,high = n-1;
    while(low<=high){
        int mid = floor((low+high)/2);
        if (z[mid]==key){
            return mid;
        }
        else if (z[mid]<key){
            low = mid + 1;
        }
        else if (z[mid]>key){
            high = mid - 1;
        }
    }
return -1;
}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int location,element;
    printf("enter the element to find: ");
    scanf("%d",&element);
    location = BinarySearch(arr,10,element) + 1;  //since location = index + 1 (taken here)
    printf("the element is found at %d \n",location);
    return 0;
}