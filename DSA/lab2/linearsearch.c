// ANSH RAJ
// 21BKT0116

#include <stdio.h>
int main(){
    int size;
    printf("enter the size :");
    int arr[size];
    scanf("%d",&size);
    printf("\nenter the elements :");
    for (int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the element to search");
    int key;
    scanf("%d",&key);
    for (int i=0;i<size;i++){
        if (arr[i]==key){
            printf("element %d found at index %d",key,i);
            break;
        }
        else{
            if (i==5){
                printf("search unsuccessful");
            }
        }
    }
return 0;}
