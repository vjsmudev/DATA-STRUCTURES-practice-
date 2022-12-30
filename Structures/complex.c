/*Implement Complex numbers using structures. Write functions to add, multiply,
subtract two complex numbers.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    float real;
    float imaginary;
} COMPLEX;

COMPLEX add(COMPLEX a, COMPLEX b){
    COMPLEX c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary  + b.imaginary;
    return c;
}

COMPLEX sub(COMPLEX a, COMPLEX b){
    COMPLEX c;
    c.real = a.real - b.real;
    c.imaginary = a.imaginary - b.imaginary;
    return c;
}

COMPLEX product(COMPLEX a,COMPLEX b){
    COMPLEX c;
    c.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    c.imaginary = (a.imaginary * b.real) - (a.real * b.imaginary);
    return c;
}

int main(){
    COMPLEX a;
    COMPLEX b;
    COMPLEX c;
    printf("Enter the real and imaginary part\n");
    printf("Enter the first imaginary number(in x + iy) format:\n");
    scanf("%f %f",&a.real,&a.imaginary);

    printf("Enter the second imaginary number(in x + iy) format:\n");
    scanf("%f %f",&b.real,&b.imaginary);

    c = add(a,b);
    printf("\nResult after adding\n");
    printf("%f + i%f",c.real,c.imaginary);

    c = sub(a,b);
    printf("\nResult after subtracting:\n");
    printf("%f - i%f",c.real,c.imaginary);

    c = product(a,b);
    printf("Result after multiplying:\n");
    printf("\nReal part:%f \n Imaginary part:%f ",c.real,c.imaginary);

    return 0;
}
