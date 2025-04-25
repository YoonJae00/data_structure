//
// Created by 김윤재 on 2025. 4. 2..
//

#include <stdio.h>

int fib(int n) {
    if (n==0) return 0;
    if (n==1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {

    int a = fib(5);
    printf("피보나치 호출 : %d", a);

    return 0;
}