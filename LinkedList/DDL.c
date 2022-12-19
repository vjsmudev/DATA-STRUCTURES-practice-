#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next,*prev;
} NODE;

void insertAtBeg(NODE** head, int ele){
    NODE* newnode =(NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = (*head);
    newnode->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = newnode;
    (*head) = newnode;
}

void insertAtEnd(NODE** head, int ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    NODE* last = (*head);
    newnode->next = NULL;
    if((*head) == NULL){
        newnode->prev = NULL;
        (*head) = newnode;
        return;
    } 
    while(last->next != NULL){
        last = last->next;
        last->next = newnode;
        newnode->prev = last;
        return;
    }
}

void deleteNode(NODE** head_ref, NODE* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;
 
    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;
 
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}

void display(NODE* temp){
    NODE* last;
    printf("Traversal in forward direction:\n");
    while(temp != NULL){
        printf("%d",temp->data);
        last = temp;
        last = last->next;
    }
    printf("Traversal in reverse direction\n");
    while(last != NULL){
        printf("%d", last->data);
        last = last->prev;
    }
}

int main(){
    NODE* head = NULL;
    insertAtBeg(&head,1);
    insertAtBeg(&head,8);
    insertAtEnd(&head,2);
    insertAtEnd(&head,4);
    insertAtBeg(&head,3);
    display(head);
    deleteNode(&head,head);
    deleteNode(&head,head->next);
    deleteNode(&head,head->next);
    display(head);
    return 0;
}
