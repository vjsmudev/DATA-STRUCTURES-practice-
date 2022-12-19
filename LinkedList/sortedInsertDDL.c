#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next,*prev;
} NODE;

NODE* createNode(int ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void sortedInsert(NODE** head, NODE* newnode){
    NODE* curr;
    if(*head == NULL)
        *head = newnode;
// if the node is to be inserted at the beginning
//of the doubly linked list
    else if((*head)->data == newnode->data){
        newnode->next = *head;
        newnode->next->prev = newnode;
        *head = newnode;
    }
    else{
        curr = *head;
         // locate the node after which the new node
        // is to be inserted
        while(curr->next != NULL &&  curr->next->data < newnode->data)
            curr = curr->next;
        newnode->next  = curr->next;
        // if the new node is not inserted
        // at the end of the list
        if(curr->next != NULL)
            newnode->next->prev = newnode;
       
        curr->next = newnode;
        newnode->prev = curr;
    }
}

void printList(NODE* head){
  while (head != NULL){
    printf("%d ", head->data);
    head = head->next;
  }
}

// Driver program to test above functions
int main(){
  // Start with an empty doubly linked list
  NODE* head = NULL;
  NODE* newnode = createNode(8);
  sortedInsert(&head,newnode);
  
  newnode = createNode(5);
  sortedInsert(&head,newnode);

    newnode = createNode(3);
  sortedInsert(&head,newnode);


  newnode = createNode(10);
  sortedInsert(&head,newnode);

  newnode = createNode(12);
  sortedInsert(&head,newnode);

    newnode = createNode(9);
  sortedInsert(&head,newnode);

  printf("Doubly linked list:\n");
  printList(head);

  return 0;
}
