#include <stdio.h>
int main(){
    int arr[5] = {34,65,43,76,10},location;
    printf("enter the location to delete: ");
    scanf("%d",&location);
//here, location is the location and not the index
// the index of location is location-1
    for (int i=location;i<=4;i++){
        arr[i-1] = arr[i];
    }
// now, to print the array
    for (int j=0;j<=3;j++){
        printf("%d ",arr[j]);
    }
    printf("\n");
return 0;}