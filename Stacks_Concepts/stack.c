/*Implement a menu driven program to define a stack of characters. Include push,
pop and display functions. Also include functions for checking error conditions
such as underflow and overflow (ref. figure 1) by defining isEmpty and isFull
functions. Use these function in push, pop and display functions appropriately. Use
type defined structure to define a STACK containing a character array and an
integer top. Do not use global variables*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
    int top;
    char* arr;
} STACK;

STACK* init(){
    STACK* s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    s->arr = (char*)malloc(MAX*sizeof(char));
    return s;
}

int isFull(STACK* s){
    return s->top == MAX - 1;
}

int isEmpty(STACK* s){
    return s->top == -1;
}

void push(STACK* s, char ele){
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
        printf(" %c ",s->arr[i]);
    }  
}

int main(){
    STACK* s = init();
    int ch,ele;
    int flag = 1;
    printf("List of operations:\n1.push\n2.pop\n3.display\n4.exit\n");
    while(flag){
        printf("Enter choice:\n");
        scanf("%d",&ch);
        if(ch == 1){
            printf("Enter a element to push in the stack:\n");
            scanf(" %c",&ele);
            push(s,ele);
            printf("%c pushed to the stack\n",ele);
        }
        else if(ch == 2){
            ele = pop(s);
            printf("%c popped from the stack\n", ele);
        }
        else if(ch == 3){
            printf("Displaying the elements in the stack:\n");
            display(s);
        }
        else{
            flag = 0;
        }
    }
    return 0;
}
