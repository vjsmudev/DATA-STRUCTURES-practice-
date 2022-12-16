//Creating and Traversing a Binary tree using recursion 
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createNode(int ele){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;   
}

struct node* createTree(){
    int ele;
    struct node* newnode;
    printf("Enter data(-1 to stop):\n");
    scanf("%d",&ele);
    
    if(ele == -1){
     newnode = NULL;
    }
    
    else{
        newnode = createNode(ele);
        printf("Enter the data for lchild of(-1 to stop) %d\n",ele);
        newnode->left = createTree();
        printf("Enter the data for rchild(-1 to stop) for %d:\n",ele);
        newnode->right = createTree();
    }
    return newnode;
}


void inorder(struct node* root){
    if (root != NULL){
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root != NULL){
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}

int main(){
    struct node *root = NULL;
    printf("Creating the binary tree\n");
    root = createTree();
    printf("\nInorder traversal:  \n");
    inorder(root);
    printf("\nPreorder traversal: \n");
    preorder(root);
    printf("\nPostorder traversal: \n");
    postorder(root);
    return 0;
}

