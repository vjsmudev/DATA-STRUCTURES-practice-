//Iterative inorder,postorder,preorder traversal
//Level order traversal

/*Algorithms for Iterative inorder,postorder,preorder traversal

Iterative inorder
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.

Iterative preorder 
1.Create an empty stack nodeStack and push root node to stack. 
2.Do the following while nodeStack is not empty. 
-Pop an item from the stack and print it. 
-Push right child of a popped item to stack 
-Push left child of a popped item to stack

Iterative postorder
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child 
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.


Level order traversal
Level-order traversal uses a queue.
Level-order scheme visits the root first, then the root’s left child, followed by the root’s right child.
All the node at a level are visited before moving down to another level
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct node{
    char data;
    struct node *right,*left;
} NODE;

typedef struct{
    NODE* arr[MAX];
    int top;
} STACK;

typedef struct{
    NODE *arr[MAX];
    int rear,front;
} QUEUE;

NODE* getnode(char ele){
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

NODE* createTree(char ele){
    if(ele == '#')
        return NULL;

    char x;
    NODE* temp = getnode(ele);
    printf("Enter the data for the left child of %c (# for exit):\n",ele);
    scanf("%c",&x);
    temp->left = createTree(x);

    printf("Enter the data for the right child of %c (# for exit):\n",ele);
    scanf("%c",&x);
    temp->right = createTree(x);

    return temp;
}

STACK* init(){
    STACK *s =(STACK*)malloc(sizeof(STACK));
    s->top = - 1;
    return s;
}

void push(STACK *s,NODE *n){
    if(s->top == MAX - 1){
        printf("stack overflow\n");
        return;
    }
    else{
        s->arr[++(s->top)] = n;
    }
}

NODE* pop(STACK *s){
    return s->arr[s->top--];
}

NODE* peek(STACK *s){
    if(s->top == -1)
        return NULL;
    else
        return s->arr[s->top];
}

int isFull(STACK* s){
    return s->top - 1;
}

int isEmpty(STACK* s){
    return s->top == -1;
}

void inorder(NODE* root){
    NODE* curr;
    int flag = 0;
    STACK *s = init();
    while (!flag){
        //move to leftmost node of bintree
        if(curr != NULL){
            push(s,curr);
            /*ptr to the tree node on the stk before traversing
            the nodes left subtree*/
            curr = curr->left;
        }
        //backtrack from empty subtree and go to stack top
        else{
            if(!isEmpty(s)){
                curr = pop(s);
                printf("%c",curr->data);
                //right subtree
                curr = curr->right;
            }
            else
                flag = 1;
        }
    }
}

void postOrder(NODE *root){
    if(root == NULL)
        return;
    
    STACK *s = (STACK*)malloc(sizeof(STACK));
    do{
        //move to the leftmost node
        while(root){
            //Push root's right child and then root stack
            if(root->right)
                push(s,root);
            push(s,root->right);
        //Set root as roots left child 
        root = root->left; 
        }
        root = pop(s);
        /*If popped item has a right child process it 
        before root*/ 
        if(root->right && peek(s) == root->right){
            pop(s); //Remove right child
            root = root->right; //change root so the next child is processed
        }
        else{
            printf("%c",root->data);
            root = NULL;
        }
    } while (!isEmpty(s)); 
}

void preorder(NODE *root){
    if(root == NULL)
        return;
    
    STACK *s = init();
    push(s,root);    
 
     /*Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */

    while(!isEmpty(s)){ 
        // Pop the top item from stack and print it
        NODE* temp = peek(s);
        printf("%c",temp->data);
        temp = pop(s);

         // Push right and left children of the popped node to stack
        if(temp->right)
            push(s,temp->right);

        if(temp->left)
            push(s,temp->left);
    }
}

QUEUE* initq(){
    QUEUE *q =(QUEUE*)malloc(sizeof(QUEUE));
    q->front = q->rear = 0;
    return q; 
}

int isEmpty(QUEUE* q){
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}

int isFull(QUEUE* q){
    if((q->rear+1) % MAX == q->front){
        return 1;
    }
    return 0;
}

void enqueue(QUEUE *q,NODE *ele){
    q->rear = (q->rear+1) % MAX;
    q->arr[q->rear] = ele;
}

NODE* dequeue(QUEUE *q){
    NODE *x;
    if(q->front == q->rear)
        x  = NULL;
    else if((q->front + 1) % MAX == q->rear){
        x  = q->arr[q->rear];
        q->front = q->rear = 0;
    } 
    else{
        q->front = (q->front + 1) % MAX;
        x = q->arr[q->front];
    }
    return x;
}

void levelOrder(NODE* root){
    if(!root){
        printf("Tree is empty\n");
        return;
    }
    QUEUE *q = initq();
    NODE *curr = NULL;
    enqueue(q,root);

    while (!isEmpty(q)){
        printf("%c ",curr->data);
        if(curr->left)
            enqueue(q, curr->left);
        if(curr->right)
            enqueue(q,curr->right);
    }
    free(q);
}

int main(){
    char data;
    printf("Enter the data for Tree in the order specified\n");
    printf("Enter the data for the root(# to stop):");
    scanf("%c",&data);
    NODE* root = createTree(data);

    printf("\nInorder traversal of the given tree: ");
    inorder(root);
    printf("\n");

    printf("\nPreorder traversal of the given tree: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal of the given tree: ");
    postOrder(root);
    printf("\n");

    printf("Levelorder Traversal of given tree: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
