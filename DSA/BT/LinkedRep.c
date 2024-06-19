#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


int main(){

    struct node* p = createNode(5);
    struct node* p1 = createNode(7);
    struct node* p2 = createNode(11);

    p->left = p1;
    p->right = p2;

    return 0;
}