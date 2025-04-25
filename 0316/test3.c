//
// Created by 김윤재 on 2025. 3. 17..
//


#include <stdio.h>

void swap(int *a,int *b) {
    int temp = *a;
    printf("%d a의 값 ", *a);
    printf("%d a의 값 ", &a);
    printf("%d b의 값 ", *b);
    printf("%d temp의 값 ", temp);
    *a = *b;
    *b = temp;
}


int main(void) {

    // 두 개의 정수를 입력받아 포인터를 사용하여 값을 교환(swap) 하는 프로그램을 작성하세요.

    printf("두개 정수 입력 받으시오\n");

    int a;
    int b;

    printf("%d 번째 정수 :", 1 );
    scanf("%d",&a);
    printf("%d 번째 정수 : ", 2 );
    scanf("%d",&b);

    swap(&a,&b);


    printf("1 번째 정수 : ");
    printf("%d \n",a);
    printf("2 번째 정수 : ");
    printf("%d \n",b);


    return 0;
}