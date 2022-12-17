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

NODE* createTree(){
    int ele;
    NODE* newnode;
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

// Function to traverse the tree in preorder
// and check if the given node exists in it
int Search(NODE* root,int ele) {
    static int t=0;
    if(root){
        if(root->data==ele){
            t++;
            return t;
        }
        if (t==0) Search(root->left,ele);
        if (t==0) Search(root->left,ele);
    }
}

int main(){
    NODE* root = NULL;
    printf("Creating the binary tree\n");
    root = createTree();
    int key;
    printf("Enter the value to search:\n");
    scanf("%d",&key);
    int find;
    if(Search(root,key)){
         printf("key exists");
    }
    else
        printf("key doesnt exist");
    return 0;
}
