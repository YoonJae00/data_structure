//
// Created by 김윤재 on 2025. 3. 24..
//


#include <stdio.h>
// 피보나치 수열 n 값 구하기 (중복 해결 방법)
int fib_iter(int n);

int main(void) {

    int fibNum;

    printf("피보나치 n번째 순서를 입력하세요 : ");

    scanf("%d",&fibNum);

    printf("값 %d", fib_iter(fibNum));

    return 0;
}

int fib_iter(int n) {

    if(n == 0) return 0;
    if(n == 1) return 1;

    int p = 0; // n-2
    int pp = 1; // n-1
    int result = 0;

    for (int i = 2; i <= n; i++) {
        result = p + pp; // n 값 구하기
        pp = p; // pp 를 n-1 로 이동
        p = result; // p 를 n 로 이동
    }

    return result;
}