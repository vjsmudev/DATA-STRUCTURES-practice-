#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} NODE;

void removeDup(NODE *head){
    NODE *curr = head;
    NODE *nextptr;
    if(curr == NULL){
        return;
    }
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            nextptr = curr->next->next;
            free(curr->next);
            curr->next = nextptr;
        }
        else{
            curr = curr->next;
        }
    }
}

void insertAtBeg(NODE **head, int ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = *head;
    *head = newnode;
}

void display(NODE* temp){
    while(temp!=NULL){
        printf(" %d-> ",temp->data);
        temp = temp->next;
    }
}

int main(){
    NODE *head = NULL;
    int n,i,ele;
    printf("Enter the size of linked list:\n");
    scanf("%d",&n);
    printf("\nEnter %d elements in the ascending order:\n",n);
    for(i = 0 ; i < n; i++){
        scanf("%d",&ele);
        insertAtBeg(&head,ele);
    }
    printf("Displaying Linked List before deleting duplicates:\n");
    display(head);

    removeDup(head);
    printf("\nLinked list after deleting the duplicates:\n");
    display(head);
    return 0;
}

