#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int val){
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

void Inorder(struct node* root){
    if (root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

struct node* Insert(struct node* root,int value){
    if (root==NULL){return newNode(value);}
    if (value>root->data){
        root->right=Insert(root->right,value);
    }
    else if (value<root->data){
        root->left=Insert(root->left,value);
    }
    return root;
}

struct node* InorderPredecessor(struct node* root){
    root = root->left;
    while(root->right!=NULL){root = root->right;}
    return root;
}
//IOP is rightmost child of left subtree

struct node* Delete(struct node* root, int value){
    
    struct node* iPre;
    if (root==NULL){return NULL;}
    if (root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    
    if (value>root->data){
        root->right = Delete(root->right,value);}
    else if (value<root->data){
        root->left = Delete(root->left,value);}
    else{
        iPre = InorderPredecessor(root);
        root->data = iPre->data;
        root->left = Delete(root->left,iPre->data);
    }
    return root;
}



int main(){
    
    struct node* root = newNode(36);
    root=Insert(root,30);
    root=Insert(root,54);
    root=Insert(root,23);
    root=Insert(root,89);
    root=Insert(root,5);
    Inorder(root);
    printf("\n");
    root = Delete(root,5);
    root = Delete(root,89);
    root = Delete(root,23);
    Inorder(root);
    printf("\n");
    return 0;
}