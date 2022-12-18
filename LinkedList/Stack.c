#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data;
    struct node* next;
} NODE;

NODE* init(int ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    return newnode;
}

void printList(NODE* temp){
    while (temp != NULL){
        printf(" %d ",temp->data);
        temp = temp->next;
    }
}
//Checks if the topmost element is NULL
int isEmpty(NODE* top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(NODE* top){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if(temp == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//Similar to insertAtfront function
void push(NODE* top, int ele){
    if(top == NULL){
        printf("Stack overflown\n");
    }
    else{
        NODE* newnode = init(ele);
        newnode->next = top;
        top = newnode;
    }
}

void pop(NODE* top){
    NODE* temp = top;
    if(top == 0){
        printf("Stack is empty\n");
    }
    else{
        printf("%d",top->data);
        top = top->next;
        free(temp);
    }
}

int main(){
    NODE* top = NULL;
    int n;
    int ele;
    printf("Enter the size of the linked list:\n");
    scanf("%d",&n);
    printf("Enter the elements to push to the stack:\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&ele);
        push(top,ele);
    }
    printf("Displaying the linked list:\n");
    printList(top);

    pop(top);
    
    printf("Displaying the linked list after popping:\n");
    printList(top);
    return 0;
}
