#include <stdio.h>
int main(){
    int arr[50] = {23,45,65,87,86,433};
    int location,element; //to get the position and element from user
    printf("enter the location and element to be inserted: ");
    scanf("%d %d",&location,&element);
// now, we move each element after the position to the right and insert at the position
// the index is position-1 
    for (int i=5;i>=location-1;i--){
        arr[i+1] = arr[i];
    }
    arr[location-1] = element;
// now, to print the array
    for (int j=0;j<=6;j++){
        printf("%d ",arr[j]);
    }
    printf("\n");
return 0;}