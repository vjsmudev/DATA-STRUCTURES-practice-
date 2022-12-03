#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next,*prev;
} NODE;


void insertAtBeg(NODE **head,int ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = *head;
    newnode->prev = NULL;
    //change prev of head node to new node 
    if(*head != NULL)
        (*head)->prev = newnode;
    //move the head to point to the new node
    *head = newnode; 
}

void insertAtEnd(NODE **head, int ele){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    NODE* last = *head;
    newnode->data = ele;
    newnode->next = NULL;
    // If the Linked List is empty, then make the new node as head
    if(*head == NULL){
        newnode->prev = NULL;
        *head = newnode;
        return;
    }

    //Traverse till the last node 
    while(last->next != NULL){
        last = last->next;
        last->next = newnode;
        newnode->prev = last;
        return;  
    }
}

void delAtBeg(NODE *head){
    NODE *temp =  head;
    if(head == NULL)
        printf("List is empty");
    else{
        temp = head;
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        free(temp);
    }
}

void delAtEnd(NODE *head){
    NODE* temp;
    if(head == NULL){
        printf("\nThe list is empty\n");
    }
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    if(head->next == NULL)
        head = NULL;
    else{
        temp->prev->next = NULL;
        free(temp);
    }
}

void delNode(NODE** head,NODE* del){
    if(*head == NULL || del == NULL)
        return;
    //deleting the head node
    if(*head == del){
        *head = del->next;
    }
    //Change next if node to be deleted is not the last node
    if(del->next != NULL){
        del->next->prev = del->prev;
    }
    //Change prev if node to be deleted is not the first node
    if(del->prev != NULL){
        del->prev->next = del->next;
    }
    free(del);
    return;
}

void display(NODE *head){
    if(head == NULL)
        printf("Linked List contains:\n");
    
    NODE *curr = head;

        while(curr != NULL){
            printf("%d",curr->data);
            curr = curr->next;
        }
    printf("\n");
}

int main(){
    int ch,ele;
    int flag = 1;
    NODE *head = NULL;
    printf("Operations:\n");
    printf("1.Insert front\n");
    printf("2.Insert end\n");
    printf("3.Del front\n");
    printf("4.Del last\n");
    printf("5.Display\n");
    printf("6.Exit\n");
    while(flag){
        printf("Enter ch:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                printf("Enter val to insert:\n");
                scanf("%d",&ele);
                insertAtBeg(&head,ele);
                break;

            case 2:
                printf("Enter val to insert:\n");
                scanf("%d",&ele);
                insertAtEnd(&head,ele);
                break;

            case 3:
                delAtBeg(head);
                break;

            case 4:
                delAtEnd(head);
                break;
            
            case 5:
                printf("Displaying:\n");
                display(head);
                break;
            
            case 6:
                flag = 0;
                break;
            
            default:
                printf("Re-enter choice");
        }
    }
    return 0;
}