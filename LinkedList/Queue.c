#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next; 
} NODE;

typedef struct{
    NODE* front;
    NODE* rear;
} QUEUE;

QUEUE* init(){
    QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
    q->front = q->rear = NULL;
    return q;
}

NODE* createNode(int ele){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->next = NULL;
    return newnode;

}

void enqueue(QUEUE* q, int ele){
    NODE* temp = createNode(ele);
    if (q->front == NULL && q->rear == NULL){
       q->rear = q->front = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

void dequeue(QUEUE* q){
    if(q->front == NULL)
        return;
    NODE* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
}

void display(QUEUE* q) {
	if(q->front == NULL) {
		printf("Queue is Empty!!!\n");
		return;
	}
    NODE* temp = q->front;
	while(temp != NULL) {
		printf(" %d " , temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
    QUEUE* q = init();
    int ch,ele;
    int flag = 1;
    printf("Available operations:\n");
    printf("\n1.Insert\n2.Dequeue\n3.Display\n");
    while(flag){
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        if(ch == 1){
            printf("Enter the element:\n");
            scanf("%d",&ele);
            enqueue(q,ele);
        }
        else if(ch == 2){
            dequeue(q);
        }
        else if(ch == 3){
            printf("Displaying the the queue\n");
            display(q);
        }
        else{
            printf("Renter choice\n");
        }
    }
    free(q);
    return 0;
}
