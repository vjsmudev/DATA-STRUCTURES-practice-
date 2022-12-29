/*Write a function Smallest to find the smallest element in an array using pointer.
Create a dynamically allocated array and read the values from keyboard in main.
Display the result in the main function.*/

#include<stdio.h>
#include<stdlib.h>

int smallest(int* arr ,int n){
   int* ptr = arr;
   int smallest = *ptr;
   for (int i = 1; i < n; i++){
        if (*(ptr+i) < smallest){
            smallest = *(ptr + i);
        }
   }
    return smallest;
}

int main(){
    int* arr;
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    arr = (int*)malloc(sizeof(int) * n);
    printf("Enter the elements in the array:\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    int small = smallest(arr,n);
    printf("The smallest element in the array is: %d\n",small);
    free(arr);
    return 0;   
}
