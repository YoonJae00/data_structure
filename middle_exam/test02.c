//
// Created by 김윤재 on 2025. 4. 18..
//

#include <stdio.h>
#include <time.h>  // 시간 측정용

// int fib(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     return fib(n - 1) + fib(n - 2);
// }

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int pp = 0;
    int p = 1;
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = p + pp;
        pp = p;
        p = result;
    }
    return result;
}


int main() {
    clock_t start, end;
    double time_spent;

    start = clock(); // 시작 시간

    int a = fib(30);

    end = clock(); // 종료 시간

    time_spent = (double)(end - start) / CLOCKS_PER_SEC * 1000; // 밀리초(ms)로 변환

    printf("fib(20) = %d\n", a);
    printf("소요 시간: %.3f ms\n", time_spent);

    return 0;
}