#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int isOperator(char c) {
  return ( c == '+' || c == '-' || c == '*' || c == '/');
}

// Create the expression tree from the given prefix expression
NODE* createExpressionTree(char *expression) {
    STACK* s = init();
  int length = strlen(expression);
  for (int i = length - 1; i >= 0; i--) {
    // Ignore whitespace
    if (expression[i] == ' ' || expression[i] == '\t')
      continue;

    // Create a new node for the character
    NODE* newnode = createNode(expression[i]);

    // If the character is an operator, pop two nodes from the stack and make them the left and right children of the new node
    if (isOperator(expression[i])) {
      newnode->right = pop(s);
      newnode->left = pop(s);
    }

    // Push the new node onto the stack
    push(s,newnode);
  }

  // The final node on the stack is the root of the expression tree
  return pop(s);
}

int main(){
     char prefix[50];
    printf("Enter a prefix expression:\n");
    scanf("%s",prefix);

    printf("Expression tree for prefix expression:\n");
    NODE* root = createExpressionTree(prefix);
    
    int res = eval(root);
    printf("The result is:%d\n",res);
    return 0;
}
