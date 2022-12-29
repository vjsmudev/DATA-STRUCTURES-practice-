#include<stdio.h>
#include<stdlib.h>

//list must contain one element 
//endPtr is pointer to the largest element in the array 
//target value of the element being sought
//if found locnPtr points to the target element
int binSearch(int arr[], int* endptr, int key, int** locnPtr){
    int* firstptr, *midptr, *lastptr;
    firstptr = arr;
    lastptr = endptr;
    while(firstptr <= lastptr){
        midptr = firstptr + (lastptr - firstptr)/2;
        if(key > *midptr)
            firstptr = midptr + 1;
            else if(key < *midptr)
                lastptr = midptr - 1;
            else
                firstptr = lastptr + 1;
    }
    *locnPtr = midptr;
    return (key == *midptr);
}

int main(){
    int n;
    int* endptr;
    int* locnptr;
    int key;
    int flag = 1;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    endptr = arr + n;
    printf("Enter key to search in the array:\n");
    scanf("%d", &key);
    if(flag){
        printf("Value %d found at index %d\n", key);
    }
    else{
        printf("Value %d not found in array\n",key);
    }
    return 0;
}


