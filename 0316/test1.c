//
// Created by 김윤재 on 2025. 3. 16..
//
#include <stdio.h>


int main() {

    int dan;
    printf("구구단을 외자! 단을 입력하세요! ");
    scanf("%d", &dan);

    if ( 2<= dan && dan <= 9) {
        printf("%d 를 입력하셨습니다! \n", dan);
    } else {
        printf("잘못 입력함 프로그램 종료합니다.");
        return 0;
    }
    for (int i =0; i<9; i++) {
        printf("%d * %d = %d \n", dan, i+1, dan * (i+1));
    }

    return 0;
}