#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

void push(struct node** head_ref, int data) {
  struct node* new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void printList(struct node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

struct node* reverseAlternateK(struct node* head, int k) {
  struct node* current = head;
  struct node* next;
  struct node* prev = NULL;
  int count = 0;
/*1) reverse first k nodes of the linked list */
  while (current != NULL && count < k) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }
/* 2) Now head points to the kth node.
    So change next  of head to (k+1)th node*/
  if (head != NULL) {
    head->next = current;
  }
/* 3) We do not want to reverse next k
       nodes. So move the current
        pointer to skip next k nodes */
  count = 0;
  while (current != NULL && count < k - 1) {
    current = current->next;
    count++;
  }
/* 4) Recursively call for the list
    starting from current->next. And make
    rest of the list as next of first node */

  if (current != NULL) {
    current->next = reverseAlternateK(current->next, k);
  }
/* 5) prev is new head of the input list */
  return prev;
}

int main() {
  struct node* head = NULL;
  int k;
   printf("Enter k: ");
   scanf("%d",&k);
   
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  push(&head, 6);
  push(&head, 7);
  push(&head, 8);
  push(&head, 9);
  push(&head, 10);

 

  printf("Original list: \n");
  printList(head);

  head = reverseAlternateK(head, k);

  printf("Modified list: \n");
  printList(head);

  return 0;
}
