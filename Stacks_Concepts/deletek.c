/*Given an array arr with n elements and a number k, k<n. The task is to delete k
elements which are smaller than next element (i.e., we delete arr[i] if arr[i] <
arr[i+1]) or become smaller than next because next element is deleted. Example:
Input: arr[] = {20, 10, 25, 30, 40}, k = 2
Output: 25 30 40
Explanation: First we delete 10 because it follows arr[i] < arr[i+1]. Then we delete 20
because 25 is moved next to it and it also starts following the condition.*/

/*1.Create an empty stack 
2.push arr[0] and initialise count = 0
3.Traverse loop from 1 to n and check if stack top < arr[i]:
-if the condition is true, pop the element from the stack and increment count 
-if count == k then stop the loop and 
then store the value of the stack in another array*/

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

int peek(STACK* s){
    if(isEmpty(s)){
        return 0;
    }
    else{
        return s->arr[s->top];
    }
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

void delElements(int* arr, int n, int k){
    STACK* s= init();
    for (int i = 0; i < n; i++){
        while (!isEmpty(s) && k > 0 && s->arr[s->top] < arr[i]){
            pop(s);
            k--;
        }
        push(s,arr[i]);
    }
    while (!isEmpty(s) && k > 0){
        pop(s);
        k--;
    }
    printf("Output:\n");
    display(s);
}
    
int main(){
    int n,k;
    int arr[50];
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the %d elements in the array:\n",n);
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value of k:\n");
    scanf("%d",&k);
    delElements(arr,n,k);
    return 0;
}