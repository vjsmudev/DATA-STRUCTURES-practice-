//Determine whether a given string is palindrome or not using stack.
/*1.Find the length of the string say len. Now, find the mid as mid = len / 2.
2.Push all the elements till mid into the stack i.e. str[0…mid-1].
3.If the length of the string is odd then neglect the middle character.
4.Till the end of the string, keep popping elements from the stack and compare them with the current character i.e. string[i].
5.If there is a mismatch then the string is not a palindrome. If all the elements match then the string is a palindrome.*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct{
    char* arr;
    int top;
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

char pop(STACK* s){
    if(isEmpty(s))
        return -1;
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

int isPalindrome(char str[]){
    int length = strlen(str);
    STACK* s = init();
    int mid = length/2;
    int  i;
    for (i = 0; i < mid; i++){
        push(s,str[i]);
    }

    if(length % 2 != 0){
        i++;
    }

    while (str[i] = '\0'){
        char ele = pop(s);
        if (ele != str[i]){
            return 0;
        }
        i++;
    }
    return 1;
}

int main(){
    STACK* s = init();
    char str[50];
    printf("Enter string:\n");
    scanf("%s",str);
    if(isPalindrome(str)){
        printf("String is a palindrome\n");
    }
    else
        printf("String is not a palindrome\n");
    return 0;
}
