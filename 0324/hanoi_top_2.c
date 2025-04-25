//
// Created by 김윤재 on 2025. 3. 24..
//


#include <stdio.h>

void hanoi_top(int n, char from, char temp, char to);

int main(void) {

    hanoi_top(3,'A','B','C');

    return 0;
}


void hanoi_top(int n, char from, char temp, char to) {

    if (n==1) {
        printf("원판 1 를 %c 에서 %c 로 옮깁니다 \n",from,to);
    } else {
        hanoi_top(n-1,from,to,temp); // 스택에 쌓음
        printf("원판 %d 를 %c 에서 %c 로 옮깁니다. \n",n,from,to); // 결정
        hanoi_top(n-1,temp,from,to); // 나머지 과제 수행 스택
    }
}