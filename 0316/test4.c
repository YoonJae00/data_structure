//
// Created by 김윤재 on 2025. 3. 17..
//
#include <stdio.h>
void modifyPointer(int **pp) {
    static int x = 20;  // 정적 변수
    *pp = &x;  // pp가 가리키는 포인터를 x의 주소로 변경
}

int main() {
    int *p = NULL;  // 포인터 p 초기화
    printf("p의 값: %p\n", p);  // NULL

    modifyPointer(&p);  // p의 주소를 modifyPointer 함수에 전달

    printf("p의 값: %p\n", p);   // x의 주소
    printf("*p의 값: %d\n", *p); // 20 (x의 값)

    return 0;
}