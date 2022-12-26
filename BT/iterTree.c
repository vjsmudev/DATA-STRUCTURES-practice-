#include<stdio.h>
#include<stdlib.h>

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

void inorder(NODE* root){

    if(root != NULL){
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}


void preorder(NODE* root){
    if(root != NULL){
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
    }
}


void createTree(NODE** root, int ele){
    NODE* newnode = createNode(ele);
    if(*root == NULL){
        //set newnode as root
        *root = newnode;
        return;
    }
    NODE* curr = *root;
    while (1){
        // If the data of the new node is less than the data of the current node,
    // go to the left child
        if(ele <  curr->data){
            // If the left child is empty, insert the new node here
            if(curr->left == NULL){
                curr->left = newnode;
                return;
            }
            curr = curr->left;
        }
            // If the data of the new node is greater than or equal to the data of the current node,
    // go to the right child
        else{
            if (curr->right == NULL){
                curr->right = newnode;
                return; 
            }
            curr = curr->right;
        }
    }
}

int main(){
    NODE* root = NULL;
    int data;
    while(1){
    printf("Enter the data for the root node of the binary tree(Enter -1 to stop): \n");
    scanf("%d",&data);
    createTree(&root,data);
    if(data == -1){
        break;
    }
}
    printf("\nPreorder traversal:\n");
    preorder(root);

    printf("\nInorder traversal:\n");
    inorder(root);

    
    printf("\nPostorder traversal:\n");
    postorder(root);
    
    return 0;
}
