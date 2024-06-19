#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* reverse(struct node* head){
    struct node* curr = head;
    struct node* prev = NULL;

    while(curr!=NULL){
        struct node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void traverse(struct node* ptr){
    while (ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* insertAtStart(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node* insertAt(struct node* head,int data,int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;

    int i=0;
    while (i!=index-1){
        temp = temp->next;
        i++;
    }    

    ptr->data = data;
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}

struct node* insertAtEnd(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;

    while (temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

struct node* deleteAtStart(struct node* head){
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node* deleteAt(struct node* head,int index){
    struct node* p = head;
    struct node* q = head->next;
    // to move q to node to be deleted, and p before that
    for (int i=0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;    
}

struct node* deleteAtLast(struct node* head){
    struct node* p = head;
    struct node* q = head->next;
    while (q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node* deleteValue(struct node* head, int value){
    struct node* p = head;
    struct node* q = head->next;
    while (q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

void revPrint(struct node* node){
    if (node!=NULL){
        revPrint(node->next);
        printf("%d ",node->data);
    }
}

int main(){

    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    
    head->data = 10;
    head->next = second;

    second->data = 23;
    second->next = third;
    
    third->data = 45;
    third->next = fourth;

    fourth->data = 69;
    fourth->next = NULL;

    traverse(head);
    head = insertAtStart(head,11);
    traverse(head);
    head = insertAtEnd(head,89);
    traverse(head);
    head = insertAt(head,5,2);
    traverse(head);
    head = insertAtStart(head,68);
    head = insertAtEnd(head,29);
    traverse(head);
    head = deleteAtStart(head);
    traverse(head);
    head = deleteAtLast(head);
    traverse(head);
    head = deleteAt(head,3);
    traverse(head);
    head = deleteValue(head,69);
    traverse(head);
    head = reverse(head);
    traverse(head);
    revPrint(head);
    return 0;
}