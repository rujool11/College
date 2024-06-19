#include <stdio.h>
struct student{
    char name[20],rollNo[20],branch[20];
};

int main(){
    struct student *ptr;
    int num;
    printf("enter number of students: ");
    scanf("%d",&num);
    struct student stud[num];
    for (int i=0;i<num;i++){ 
    ptr=&stud[i];
    printf("\nenter %d student details ",i+1);
    scanf("%s %s %s",ptr->name,ptr->rollNo,ptr->branch);
    }
    for (int j=0;j<num;j++){
    printf("\nthe details of the %d student are:\nname:%s\nrollNo.:%s\nbranch:%s",j+1,ptr->name,ptr->rollNo,ptr->branch);
    }
return 0;}
