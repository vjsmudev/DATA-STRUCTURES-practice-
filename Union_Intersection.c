/*Perform UNION and INTERSECTION set operations on singly linked lists with
and without header node.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

void insertAtBeg(node **head, int ele){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = ele;
    newnode->next = (*head);
    (*head) = newnode;
}

int isPresent(node *temp, int ele){
    node *t = temp;
    while(t != NULL){
        if(t->data == ele)
            return 1;
        t = t->next;
    }
    return 0;
}

void printList(node *n){
    while(n != NULL){
        printf("%d->",n->data);
        n = n->next;
    }
}

node* getUnion(node *head1,node *head2){
    node *result = NULL;
    node *t1 = head1;
    node *t2 = head2;
    while(t1 != NULL){
        insertAtBeg(&result, t1->data);
        t1 = t1->next;
    }

    while(t2!=NULL){
        if(!isPresent(result, t2->data))
            insertAtBeg(&result,t2->data);
        t2 = t2->next;
    }
    return result;
}

node *getIntersection(node *head1,node *head2){
    node* result = NULL;
    node* t1 = head1;
    while(t1 != NULL){
        if(isPresent(head2, t1->data))
            insertAtBeg(&result,t1->data);
        t1 = t1->next;
    }
    return result;
}

int main(){
    node *intersection = NULL;
    node *unin = NULL;
    node *List1;
    node *List2;
    List1 = List2 = NULL;
    int i,n,m,temp;
    
    printf("Enter the size of the first linked list:\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i = 0;i < n;i++){
        scanf("%d",&temp);
        insertAtBeg(&List1,temp);
    }
     printf("Displaying list 1:\n");
     printList(List1);

    printf("\nEnter the size of the second linked list:\n");
    scanf("%d",&m);
    printf("Enter %d elements\n",m);
    for(i = 0;i < m;i++){
        scanf("%d",&temp);
        insertAtBeg(&List2,temp);
    }
    printf("Displaying list 2:\n");
    printList(List2);

    unin = getUnion(List1,List2);
    intersection = getIntersection(List1,List2);

    printf("\nLinked List with Union of List1 and List2:\n");
    printList(unin);
    printf("\nLinked List with Intersection of List1 and List2:\n");
    printList(intersection);
    return 0;
}
