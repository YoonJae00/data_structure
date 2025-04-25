//
// Created by 김윤재 on 2025. 3. 24..
//

#include <stdio.h>


// 학번-이름.zip
//    ㄴ 보고서, 소스파일


// 재귀함수
// 분할정복 (문제의 크기는 점점 작아져야 함)
// 호출이 끝나는 종료 조건이 있어야 함


void pebo(void);
int a;

// 피보나치 수열 재귀함수로
int main() {

    pebo(1);

    return 0;
}

int pebo(int a) {

    if (a == 0) return 0;
    if (a == 1) return 1;

    return (pebo(a-1) + pebo(a-2));
}