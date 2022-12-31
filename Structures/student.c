#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[100];
    int rno;
    float cgpa;
} STUDENT;

void read(STUDENT* std){    
    printf("Enter the name of the student:\n");
    scanf("%s",std->name);
    printf("Enter the roll number of the student:\n");
    scanf("%d",&std->rno);
    printf("Enter the CGPA of the student:\n");
    scanf("%f",&std->cgpa);
}

void display(STUDENT* std){
    printf("Displaying the credentials of the student:\n");
    printf("\nName: %s\n",std->name);
    printf("\nRoll no: %d\n", std->rno);
    printf("\nCGPA: %f\n", std->cgpa);
}

void sort(STUDENT* std, int n){
    STUDENT temp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i; j < n; j++){
            if(std[i].rno > std[j].rno){
                temp = std[i];
                std[i] = std[j];
                std[j] = temp;
            }       
        }   
    }
}
    
int main(){
    int n;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    STUDENT std[n];
    printf("Enter the credentials of each students\n");
    
    for(int i = 0;i < n;i++){
        read(&std[i]);
    }
    
    for(int i = 0;i < n;i++){
        display(&std[i]);
    }   
    
    sort(std,n);
    printf("Sorting the data according to the roll number\n");

    for(int i = 0;i < n;i++){
        display(&std[i]);
    }   
    
    return 0;
}
