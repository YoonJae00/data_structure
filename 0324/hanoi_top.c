//
// Created by 김윤재 on 2025. 3. 24..
//



#include <stdio.h>

void hanoi_top(int n, char from, char temp, char to);

int main(void) {

    hanoi_top(4,'A','B','C');

    return 0;
}

void hanoi_top(int n, char from, char temp, char to) {

    if (n==1) {
        printf("원판1 을 %c 에서 %c 로 옮긴다.", from, to);
    } else {
            hanoi_top(n-1,from,to,temp);
            printf("원판 %d 를 %c 에서 %c 로 옮기세요 \n",n,from,to);
            hanoi_top(n-1,temp,from,to);
        }
}