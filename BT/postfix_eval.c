/*
1.Scan the expression from left to right.
2.Create a node for each symbol encountered.
3.If the symbol is an operand, push the corresponding node on to the stack.
4.If the symbol is an operator, pop top node from stack and attach it to the right of the node with the operator. 
Next pop present top node and attach it to the left of node with the operator. Push the operator node to the stack.
5.Repeat the process for each symbol in postfix expression. Finally address of root node of expression tree is on top of stack.   
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20

typedef struct node{
    char data;
    struct node* left,*right;
} NODE;

typedef struct{
    NODE* arr[MAX];
    int top;
} STACK;

NODE* createNode(char ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

STACK* init(){
    STACK* s = (STACK*)malloc(sizeof(STACK));
    s->top = -1;
    return s;
}

void push(STACK *s,NODE* ele){
    if(s->top == MAX - 1){
        printf("Stack is full");
    }
    else{
        s->arr[++(s->top)] = ele;
    }
}

NODE* pop(STACK* s){
    if(s->top == -1){
        printf("Stack is empty\n");
    }
    return s->arr[s->top--];
}

int isEmpty(STACK* s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

int isFull(STACK* s){
    if(s->top == MAX - 1){
        return 1;
    }
    return 0;
}

int checkOperator(char ele){
    switch (ele){
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return 1;
    default:
        return 0;
    }
}

NODE* createExpression(char* postfix){
    NODE* root = NULL;
    NODE* temp;
    STACK* s = init();
    char symbol;
    int i = 0;
    while (postfix[i]){
        symbol = postfix[i];

        if(checkOperator(symbol)){
            temp = createNode(symbol);
            temp->right = pop(s);
            temp->left = pop(s);
            push(s,temp);
        }
        else
            push(s,createNode(symbol));
        
        i++;
    }
    temp = pop(s);
    free(s);
    return temp;
}

//evaluating expression tree using recursion
int eval(NODE* root){
	switch(root->data)
	{
		case '+':return eval(root->left)+ eval(root->right);
		case '-' :return eval(root->left)- eval(root->right);
		case '/':return eval(root->left)/ eval(root->right);
		case '*' :return eval(root->left)* eval(root->right);
		case '^':return pow(eval(root->left),eval(root->right));
		default :return(root->data - '0'); 
	}
}

int main(){
    char postfix[50];
    printf("Enter a postfix expression:\n");
    scanf("%s",postfix);

    printf("Expression tree for postfix expression:\n");
    NODE* root = createExpression(postfix);
    
    int res = eval(root);
    printf("The result is:%d\n",res);
    return 0;
}
