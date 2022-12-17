#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node *left,*right;
} NODE;

NODE* createNode(int ele){
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

NODE* createTree(){
    int ele;
    NODE* newnode;
    printf("Enter root data (-1 to stop):\n");
    scanf("%d",&ele);
    if(ele == -1){
        newnode = NULL;
    }
    newnode = createNode(ele);
    printf("Enter the data for lchild of %d (-1 to stop):\n",ele);
    newnode->left = createTree();
    printf("Enter the data for rchild of %d (-1 to stop):\n",ele);
    newnode->right = createTree();
    return newnode;
}

void insertNode(NODE* root,int ele, char* direction){
     // If the tree is empty, create a new node and set it as the root
     if (root == NULL){
        root = createNode(ele);
        return;
     }

     // Find the correct position to insert the new node
    if(strcmp(direction,"left") == 0){
         // Insert the node into the left subtree
         if(root->left == NULL){
            root->left = createNode(ele);
         }
         else{
            printf("The left child of the current node is not empty. Enter a direction insert the node:\n");
            scanf("%s",direction);
            insertNode(root->left,ele,direction);
        }
    }
    else if (strcmp(direction,"right")){
        // Insert the node into the left subtree
        if(root->right == NULL){
            root->right = createNode(ele);
        }
            else{
                printf("The right child of the current node is not empty. Enter a direction to insert the node:\n");
                scanf("%s",direction);
                insertNode(root->right,ele,direction);
            }
        }
            else{
                printf("Invalid direction.Enter either left or right to insert the node:\n");
                scanf("%s",direction);
                insertNode(root,ele,direction);
            }
}

int main(){
    NODE* root = NULL;
    int ele;
    char direction[10];
    printf("Enter the data for root node:\n");
    scanf("%d",&ele);
    root = createNode(ele);
    while (1){
        printf("Enter the data for the newnode:\n");
        scanf("%d",&ele);
        printf("Enter the direction to insert the newnode(left or right):\n");
        scanf("%s",direction);
        insertNode(root,ele,direction);
    }
    return 0;
}
