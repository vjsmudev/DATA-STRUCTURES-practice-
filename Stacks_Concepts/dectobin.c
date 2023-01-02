//Convert a given decimal number to binary using stack
/*For the dectobin() function
1.create an empty stack
2.push the decimal number by repeatedly dividing by 2
3.display the stack contents*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
    int top;
    int* arr;
} STACK;

STACK* init(){
    STACK* s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    s->arr = (int*)malloc(MAX*sizeof(int));
    return s;
}

int isFull(STACK* s){
    return s->top == MAX - 1;
}

int isEmpty(STACK* s){
    return s->top == -1;
}

void push(STACK* s, int ele){
    if(isFull(s)){
        return; 
    }
    else{
        s->arr[++(s->top)] = ele;
    }
}

int pop(STACK* s){
    if(isEmpty(s))
        return 0;
    else 
        return s->arr[(s->top)--];
}

void display(STACK* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--){
        printf(" %d ",s->arr[i]);
    }  
}

void dectobin(int n){
    STACK* s = init();
    while (n > 0){
        push(s, n % 2);
        n = n/2;
    }
    printf("Binary equivalent of n: ");
    display(s);
}

int main(){
    int n;
    printf("Enter the decimal number:\n");
    scanf("%d", &n);
    dectobin(n);
    return 0;
}