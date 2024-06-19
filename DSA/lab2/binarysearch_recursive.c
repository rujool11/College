#include <stdio.h>
#include <math.h>
int BinarySearch(int z[],int key,int low,int high){
    int mid = floor((low + high )/2);
    if (low<=high){
        if (z[mid]==key){
            return mid;
        }
        else if (z[mid]<key){
             return BinarySearch(z,key,mid+1,high);
        }
        else if(z[mid]>key) {
            return BinarySearch(z,key,low,mid-1);
        }
    }
return -1;} //default return value, will return if element not fonnd in array
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int location,element;
    printf("enter the element to find: ");
    scanf("%d",&element);
    location = BinarySearch(arr,element,0,9) + 1;  //since location = index + 1 (taken here)
    printf("the element is found at %d \n",location);
    return 0;
}