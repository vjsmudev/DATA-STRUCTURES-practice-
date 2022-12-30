/*Implement a C program to read, display and to find the product of two matrices
using functions with suitable parameters. Note that the matrices should be created
using dynamic memory allocation functions and the elements are accessed using
array dereferencing*/

#include<stdio.h>
#include<stdlib.h>

void multiply(int** mat1,int** mat2,int** res,int r1,int c1,int r2,int c2){
    for (int i = 0; i < r1; i++){
        for(int j = 0;j < c2; j++){
            *(*(res + i)+j) = 0;
            for(int k = 0;k < c1;k++){
                *(*(res+i)+j) += *(*(mat1+i)+j) * *(*(mat2+i)+j);
            }
        }
    }
}

void read(int** mat, int r,int c){
    for(int i = 0;i < r;i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

void display(int** mat, int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf(" %d ",*(*(mat + i)+ j));
        }
        printf("\n");
    }
}



int main(){
    int r1,c1,r2,c2;
    int** mat1;
    int** mat2;
    int** mat3;
    printf("Enter the dimensions of the matrix 1:\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter the dimensions of the matrix 2:\n");
    scanf("%d %d",&r2,&c2);

    if(r1 != c2){
        printf("number of rows in mat 1 should be equal to colmns in mat2\n");
    }

    mat1 = (int**)malloc(r1 * sizeof(int*));
    for (int i = 0; i < r1; i++){
        mat1[i] = (int*)malloc(c1*sizeof(int));
    }
    mat2 = (int**)malloc(r2*sizeof(int*));
    for (int i = 0; i < r2; i++){
        mat2[i] = (int*)malloc(c2*sizeof(int));
    }
    mat3 = (int**)malloc(r1*sizeof(int*));
    for(int i = 0;i < r1;i++){
        mat3[i] = (int*)malloc(c1*sizeof(int));
    }
    printf("Enter the elements for the matrix1:\n");
    read(mat1,r1,c1);
    printf("\n");

    printf("Displaying the first matrix:\n");
    display(mat1,r1,c1);
    printf("\n");

    printf("Enter the elements for the matrix2:\n");
    read(mat2,r2,c2);
    printf("\n");

    printf("Displaying the second matrix:\n");
    display(mat2,r2,c2);
    printf("\n");

    multiply(mat1,mat2,mat3,r1,c1,r2,c2);
    printf("Displaying the resultant matrix\n");
    display(mat3,r1,c2);
    printf("\n");
    
    for(int i = 0; i < r1;i++){
        free(mat1);
        free(mat2);
        free(mat3);
    }
    return 0;
}
