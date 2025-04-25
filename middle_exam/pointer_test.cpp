//
// Created by 김윤재 on 2025. 4. 19..
//


#include <stdio.h>

void swap(int *p, int *q) {
    int temp;
    temp  = *p;
    *p = *q;
    *q = temp;
}

void soft_swap(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}


int main(int argc, char *argv[]) {

    int a = 1;
    int b = 2;

    printf("%d || %d \n",a,b);
    swap(&a,&b);
    printf("%d || %d \n",a,b);
    soft_swap(a,b);
    printf("%d || %d",a,b);


    return 0;
}
