#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} NODE;

NODE* init(int ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));;
    newnode->data = ele;
    return newnode;
}

void insertAtBeg(NODE** head, int ele){
    NODE* newnode = init(ele);
    newnode->next = *head;
    *head = newnode;
}

void printList(NODE* temp){
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}

int isPresent(NODE* temp,int ele){
    NODE* t = temp;
    while(t != NULL){
        if(t->data == ele)
            return 1;
        t = t->next;
    }
    return 0;
}

NODE* getIntersection(NODE* head1, NODE* head2){
    NODE* res = NULL;
    NODE* t1 = head1;
    while(t1 != NULL){
        if(isPresent(head2,t1->data))
            insertAtBeg(&res,t1->data);
        t1 = t1->next;  
    }
    return res;
}

NODE* getUnion(NODE* head1, NODE* head2){
    NODE* res = NULL;
    NODE* t1 = head1;
    NODE* t2 = head2;
    while (t1 != NULL){
        insertAtBeg(&res,t1->data);
        t1 = t1->next;
    }
    while(t2 != NULL){
        if(!isPresent(res,t2->data))
            insertAtBeg(&res,t2->data);
        t2 = t2->next;
    }
    return res; 
}

int main(){
    NODE* t1 = NULL;
    NODE* t2 = NULL;
    NODE* intersection = NULL;
    NODE* unin = NULL;
    int i,n,m,temp;
    
    printf("Enter the size of the first linked list:\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i = 0;i < n;i++){
        scanf("%d",&temp);
        insertAtBeg(&t1,temp);
    }
     printf("Displaying list 1:\n");
     printList(t1);

    printf("\nEnter the size of the second linked list:\n");
    scanf("%d",&m);
    printf("Enter %d elements\n",m);
    for(i = 0;i < m;i++){
        scanf("%d",&temp);
        insertAtBeg(&t2,temp);
    }
    printf("Displaying list 2:\n");
    printList(t2);

    unin = getUnion(t1,t2);
    intersection = getIntersection(t1,t2);

    printf("\nLinked List with Union of List1 and List2:\n");
    printList(unin);
    printf("\nLinked List with Intersection of List1 and List2:\n");
    printList(intersection);
    return 0;
}

