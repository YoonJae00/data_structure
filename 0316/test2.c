//
// Created by 김윤재 on 2025. 3. 16..
//

#include <stdio.h>

int main(void) {
    // 사용자로부터 5개의 정수를 입력받아 배열에 저장한 후, 입력받은 숫자 중 최댓값과 최솟값을 출력하는 프로그램을 작성하세요.

    int arr[5];

    printf("정수 5개를 입력하세요 \n");
    for (int i = 0; i < 5; i++) {
        printf("%d 번째 정수를 입력하세요\n" , i+1);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    // 배열 순회하며 최댓값, 최솟값 갱신
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }


    // 결과 출력
    printf("최댓값: %d\n", max);
    printf("최솟값: %d\n", min);


    return 0;
}