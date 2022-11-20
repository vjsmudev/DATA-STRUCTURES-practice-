
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
        if(!isPresent(result, t2->data));
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
    node *head1 = NULL;
    node *head2 = NULL;
    node *intersection = NULL;
    node *union = NULL;
    node *List1;
    node *List2;
    List1 = List2 = NULL;
    int i,n,m;
    
    printf("Enter the size of the first linked list:\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i = 0;i < n;i++){
        scanf("%d",&head1);
        insertAtBeg(&List1,head1);
    }
     printf("Displaying list 1:\n");
     printList(List1);

    printf("Enter the size of the second linked list:\n");
    scanf("%d",&m);
    printf("Enter %d elements\n",m);
    for(i = 0;i < m;i++){
        scanf("%d",&head2);
        insertAtBeg(&List2,head2);
    }
    printf("Displaying list 2:\n");
    printList(List2);

    union = getUnion(List1,List2);
    intersection = getIntersection(List1,List2);

    printf("Linked List with Union of List1 and List2:\n");
    printList(union);
    printf("Linked List with Intersection of List1 and List2:\n");
    printList(intersection);
    return 0;
}

/*tempCodeRunnerFile.c: In function ‘main’:
tempCodeRunnerFile.c:65:11: error: expected identifier or ‘(’ before ‘union’
   65 |     node *union = NULL;
      |           ^~~~~
      |                            ^~~~~      |                            |      |                            node *
tempCodeRunnerFile.c:9:35: note: expected ‘int’ but argument is of type ‘node *’
    9 | void insertAtBeg(node **head, int ele){
      |                               ~~~~^~~
tempCodeRunnerFile.c:91:11: error: expected ‘{’ before ‘=’ token
   91 |     union = getUnion(List1,List2);
      |           ^
tempCodeRunnerFile.c:95:15: error: expected expression before  union’   95 |     printList(union);*/

