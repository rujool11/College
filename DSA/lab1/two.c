//factorial of a number
#include <stdio.h>
int main(){
    int num;
    printf("enter the number : ");
    scanf("%d",&num);
    int fact=1;
    for (int i=1;i<=num;i++){
        fact*=i;
    }
    printf("the facortial is %d",fact);
    return 0;
}