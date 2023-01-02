/*Create a structure STUDENT consisting of variables of structures:
i. DOB {day, month (use pointer ), year},
ii. STU_INFO {reg_no, name(use pointer), address},
iii. COLLEGE {college_name (use pointer), university_name}
where structure types from i to iii are declared outside the STUDENT independently.
Show how to read and display member variables of DOB type if pointer variable is
created for DOB inside STUDENT and STUDENT variable is also a pointer variable.
The program should read and display the values of all members of STUDENT structure*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int day;
    int* month;
    int year;
} DOB;

typedef struct{
    int regno;
    char* name;
    char address[100];
} STU_INFO;

typedef struct{
    char* college_name;
    char university_name[100];
} COLLEGE;

typedef struct{
    DOB *date;
    STU_INFO info;
    COLLEGE clg;
} STUDENT;

void read(STUDENT* std, int n){
    printf("Enter the credentials of the students\n");
    for (int i = 0; i < n; i++){
        printf("Enter the name of the student:\n");
        scanf("%s",(std+i)->info.name);
        
        printf("Enter the registeration number:\n");
        scanf("%d",&(std+i)->info.regno);
        
        printf("Enter the residential address:\n");
        scanf("%s",(std+i)->info.address);

        printf("Enter DOB(dd/mm/yyyy):\n");
        scanf("%d %d %d",&(std+i)->date->day,&(std+i)->date->month,&(std+i)->date->year);

        printf("Enter the college name:\n");
        scanf("%s",(std+i)->clg.college_name);

        printf("Enter the university name:\n");
        scanf("%s",(std+i)->clg.university_name);
    }
}

void display(STUDENT* std, int n){
    for (int i = 0; i < n; i++){
        printf("Name: %s\n",(std+i)->info.name);
        printf("Registeration Number: %d\n",(std+i)->info.regno);
        printf("DOB(dd/mm/yyyy): %d / %d / %d /n",(std+i)->date->day,(std+i)->date->month,(std+i)->date->year);
        printf("Address: %s\n",(std+i)->info.address);
        printf("College name: %s\n",(std+i)->clg.college_name);
        printf("University name: %s\n",(std+i)->clg.university_name);   
    }
}

int main(){
    int n;
    printf("Enter the number of students:\n");
    scanf("%d",&n);
    
    STUDENT* std = (STUDENT*)malloc(n*sizeof(STUDENT));
    for(int i = 0;i < n;i++){
        (std+i)->date = (DOB*)malloc(n*sizeof(DOB));
        (std+i)->date->month = (int*)malloc(n*sizeof(int));
        (std + i)->info.name = (char*)malloc(n*sizeof(char));
        (std + i)->clg.college_name = (char*)malloc(n*sizeof(char));
    }

    read(std,n);
    printf("Displaying student information:\n");
    display(std,n);
    return 0;
}