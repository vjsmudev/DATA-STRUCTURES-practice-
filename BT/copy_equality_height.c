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

//Recursive copy
NODE* copy(NODE* root){
    if(root == NULL){
        return NULL;
    }
// Create a new node and copy the data from the root node
    NODE* newnode  = createNode(root->data); 
    newnode->left = copy(root->left);
    newnode->right = copy(root->right);
    return newnode;
}

// Recursive function to test for equality of two binary trees
int isEqual(NODE* root1, NODE* root2){
    // If both trees are empty, they are equal
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    // If either tree is empty, they are not equal
    if(root1->data != root2->data){
        return 0;
    }
    return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right); 
}
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

int height(NODE* root){
    if(root == NULL){
        return 0;
    }
    return (1+ max(height(root->left), height(root->right)));
}

int main(){
    NODE* root = createTree();
    NODE* cpy = copy(root);

    if(isEqual(root,cpy)){
        printf("The tree are equal\n");
    }
    else{
        printf("The tree's are not equal");
    }

    printf("The height of the tree is: %d\n",height(root));
    return 0;
}
