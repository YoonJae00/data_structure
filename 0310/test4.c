#include <stdio.h>

// 배열 포인터 관계

int main(void){

    int num[3];

    num[0] = 10;
    num[1] = 20;
    num[2] = 30;

    printf("%d\n", num);

    printf("%d, %d \n", *num, num+0);
    printf("%d, %d \n", *(num+1), num+1);
    printf("%d, %d \n", *(num+2), num+2); // 4바이트씩 이동 왜? int 형이기 때문에

    return 0;
}