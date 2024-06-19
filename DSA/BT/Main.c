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

void Preorder(struct node* root){
    if (root!=NULL){
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    } 
}

void Postorder(struct node* root){
    if (root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
    }
}

void Inorder(struct node* root){
    if (root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

void isBST(struct node* root){
    static struct node* prev = NULL; //prev is used for parent node
    if (root!=NULL){
        if (!isBST(root->left)){return 0;} 
        if (prev!=NULL && root->data<=prev->data){return 0;}
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1; //empty tree is assumed as BST
    }
}

// void Postorder(struct node* root){
//     if (root!=NULL){
//         printf
//     }
// }

int main(){
    //creating the nodes
    struct node* p = createNode(6);
    struct node* p1 = createNode(4);
    struct node* p2 = createNode(7);
    struct node* p3 = createNode(3);
    struct node* p4 = createNode(5);
    // finally, tree looks like this
    //     6
    //    / \
    //   4   7
    //  / \
    // 3   5
    
    //linking the parents with the children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    Preorder(p);
    printf("\n");
    Postorder(p);
    printf("\n");
    Inorder(p);
    printf("\n");

    return 0;
}