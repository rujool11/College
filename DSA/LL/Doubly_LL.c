#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void traverse(struct node* head){
    struct node* ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* insertAtStart(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    return ptr;
}

struct node* insertAt(struct node* head, int data, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    struct node* t = head->next;

    int i = 0;
    while(i!=index-1){
       temp = temp->next;
       t = t->next;
       i++; 
    }
    
    ptr->data = data;
    ptr->next = t; // ptr->next = temp->next
    t->prev = ptr;
    ptr->prev = temp;
    temp->next = ptr;
    return head;
}


struct node* insertAtEnd(struct node* head,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    ptr->data = data;
    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = NULL;
    return head;
}

struct node* deleteAtStart(struct node* head){
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head; 
}

struct node* deleteAt(struct node* head, int index){
    struct node* p = head;
    
    int i = 0;
    while(i<index){
        p = p->next;
        i++;
    }
    
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    return head;
}

struct node* deleteAtEnd(struct node* head){
    struct node* p = head;
    while (p->next!=NULL){
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
    return head;
}

void traverseFromEnd(struct node* head){
    struct node* temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
//now, temp is at the last node

    while (temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->prev = fourth;
    fifth->next = NULL;
    
    traverse(head);
    head = insertAtStart(head,5);
    traverse(head);
    head = insertAt(head,7,3);
    traverse(head);
    head = insertAtEnd(head,49);
    traverse(head);
    head = deleteAtStart(head);
    traverse(head);
    head = deleteAt(head,2);
    traverse(head);
    head = deleteAtEnd(head);
    traverse(head);
    traverseFromEnd(head);

    return 0;
}