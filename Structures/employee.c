/*Samuel wants to store the data of his employees, which includes the following
fields: (i) Name of the employee (ii) Date of birth which is a collection of {day,
month, year} (iii) Address which is a collection of {house number, zip code and
state}. Write a 'C' program to read and display the data of N employees using
pointers to array of structures.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int day;
    int month;
    int year;
} DATE;

typedef struct{
    int hseno;
    int zip;
    char state[100];
} ADDRESS;

typedef struct{
    char name[100];
    DATE dob;
    ADDRESS adr;
} EMPLOYEE;

void read(EMPLOYEE* emp, int n){
    for (int i = 0; i < n; i++){

        printf("Enter the name of the employee:\n");
        scanf("%s",((emp + i)->name));

        printf("Enter the DOB:\n");
        scanf("%d %d %d",&((emp + i)->dob.day),&((emp + i)->dob.month),&((emp + i)->dob.year));
        
        printf("Enter the house number:\n");
        scanf("%d",&((emp + i)->adr.hseno));

        printf("Enter the zip code:\n");
        scanf("%d",&((emp + i)->adr.zip));

        printf("Enter the state:\n");
        scanf("%s",((emp + i)->adr.state));
    }
}

void display(EMPLOYEE* emp, int n){
    for(int i = 0; i < n;i++){
        printf("Displaying the employee data\n");
        printf("Name:%s\n DOB:%d %d %d\n Address:\n House Number:%d\n Zip Code:%d\n State: %s\n",((emp + i)->name),((emp + i)->dob.day),((emp + i)->dob.month),((emp + i)->dob.year),((emp + i)->adr.hseno),((emp + i)->adr.zip),((emp + i)->adr.state));
    }
}

int main(){
    int n;
    printf("Enter the number of employees:\n");
    scanf("%d",&n);
    EMPLOYEE emp;
    read(&emp,n);
    display(&emp,n);
    return 0;
}

