#include<stdio.h>

int main(void) {
    int dan;

    int i = 1;

    printf("단을 입력하세요: ");
    scanf("%d", &dan);

    printf(" %d 단을 출력합니다.", dan);
    while (i <= 9) {
        printf("%d * %d = %d\n", dan, i, dan * i);
        i++;
    }

    return 0;
}
