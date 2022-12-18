#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} NODE;

void insertAtfront(NODE** head, int ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = *head;
    *head = newnode;
} 

/*deletes the first occurrence of key in
   linked list */
void delete(NODE** head, int key){
    NODE* temp = *head;
    NODE* prev;
    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->data == key){
        //Change head
        *head = temp->next;
        free(temp);
        return;
    }
     // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    //If key was not present in the linked list
    prev->next = temp->next;
    free(temp);
}

void printList(NODE* temp){
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int ele;
    int n;
    int del;
    NODE* head = NULL;
    printf("Enter the size of the linked list:\n");
    scanf("%d",&n);
    printf("Enter the elements to insert into the linked list:\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&ele);
        insertAtfront(&head,ele);
    }
    printf("Displaying the linked list\n");
    printList(head);
    printf("Enter the value to delete:\n");
    scanf("%d",&del);
    delete(&head,del);
    printf("List after deleting the node\n");
    printList(head);
    return 0;
}
