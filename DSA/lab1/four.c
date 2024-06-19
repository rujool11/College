#include <stdio.h>
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main(){
    int a,b;
    printf("enter the two numbers");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
    printf("\nthe swapped numbers are %d and %d",a,b);
    return 0;
}
