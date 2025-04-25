/*
*  게임공학과 / 2023180011 / 김윤재
*/
#include <stdio.h>
#define N 5 // 배열 크기
int array[N] = {1, 2, 3, 4, 5};
// 배열을 뒤집는 재귀 함수
void reverseArray(int start, int end) {
    // 4. start > end 시 전부 교환 되었으므로 리턴
    if (start >= end) return;
    // 2. start와 end 위치의 원소 교환 (대칭)
    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;
    // 3. 재귀 호출로 다음 단계 진행 (한칸씩 안쪽으로 진행)
    reverseArray(start + 1, end - 1);
}
int main() {

    // 1. 함수 호출 (시작 인덱스, 끝 인덱스)
    reverseArray(0, N - 1);
    // 5. 뒤집힌 배열 출력
    printf("뒤집힌 배열의 원소 : ");
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}