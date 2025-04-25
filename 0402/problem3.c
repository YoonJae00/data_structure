/*
 *  게임공학과 / 2023180011 / 김윤재
 */

#include <stdio.h>

int sumCalc(int size, int array[]) {
    if (size == 0) return 0; // 5. size 0 될 경우 재귀함수 종료
    return array[size - 1] + sumCalc(size - 1,array); // 4. 현재 요소 + 나머지 배열 합
};

int main() {

    int size;
    printf("배열의 크기를 입력하세요 : ");
    scanf("%d",&size); // 1. 배열 크기 받기

    int array[size];
    printf("배열의 원소를 입력하세요 : ");
    for (int i=0; i<size; i++) {
        scanf("%d",&array[i]);
    } // 2. 반복문을 통해 각 인덱스에 원소 삽입

    int sum = sumCalc(size, array); // 3. 함수 호출

    printf("배열의 합 : %d\n", sum);

    return 0;
}
