// 배열명은 시작주소
#include <stdio.h>

int main(void) {

    int score[5];
    int i;
    int total = 0;

    for(i=0; i<5; i++){
        printf("성적을 입력하세요: ");
        scanf("%d", &score[i]);  // 주석 제거!
    }

    for(i=0; i<5; i++){
        total += score[i];
    }

    printf("평균: %.2lf", total/5.0);





    return 0;
}