#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* push(int val,struct node* top){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    return top;
}

struct node* pop(struct node* top){
    printf("Removed Element : %d\n",top->data);
    struct node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void isEmpty(struct node* top){
    if (top==NULL){
        printf("Stack is Empty\n");
    }
}

void peek(struct node* top){
    printf("Top Element : %d\n",top->data);
}

void traverse(struct node* top){
    struct node* temp = top;
    while(temp!=NULL){
        printf("%d",temp->data);
        if (temp->next!=NULL){
            printf("-->");
        }
        temp=temp->next;
    }
    printf("\n");
}

int main(){

    struct node* top = NULL;
    top = push(10,top);
    top = push(20,top);
    top = push(30,top);
    top = push(40,top);
    traverse(top);
    peek(top);
    for (int i=0;i<4;i++){
        top = pop(top);
    }
    isEmpty(top);
    return 0;
}