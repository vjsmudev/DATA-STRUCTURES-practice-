/*Write a function Reverse to reverse the elements of an integer array using pointer.
Access the elements of the array using dereference operator. Read the values from
the keyboard in main function. Display the result in the main function.*/

#include<stdio.h>
#include<stdlib.h>

void reverse(int *arr,int n){
    int* left = arr;
    int* right = arr + n - 1;
    for(int i = 0; i < n/2;i++){
        int temp = *left;
        *left = *right;
        *right = temp;
    }
    left++;
    right--;
}

int main(){
    int n;
    int arr[20];
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }
    reverse(arr,n);
    printf("Reversed array:\n");
     for(int i = 0;i < n;i++){
        printf(" %d ", arr[i]);
    }
}
