#include<stdio.h>
#include<stdlib.h>

void doubleval(int* a){
    *a *= 2;
}

int* square(int val){
    static int res;
    res = val*val;
    return &res;
}

int main(){
    int b = 5;
    int* ptr = &b;
    doubleval(ptr);
    printf("Value of b is: %d\n",b);
    int* res_ptr = square(b);
    printf("The square of x: %d\n",*res_ptr);
    int **ans = &res_ptr;
    printf("The square of x: %d\n",**ans);
    return 0;
}

