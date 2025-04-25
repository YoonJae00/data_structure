//
// Created by 김윤재 on 2025. 4. 18..
//


#include <stdio.h>
#include <string.h>
#define MAX_DEGREE 101

// 다항식 덧셈 프로그램 만들어보기
#define plus_minus(p,q) (p>q) ? p : q

typedef struct {
    int degree; // 최대 차수
    float coef[MAX_DEGREE]; // 차수
} polynomial;

void print_poly(polynomial c)
{
    int first = 1; // 첫 번째 항에 대해서만 +를 출력하지 않기 위한 flag
    for (int i = c.degree; i >= 0; i--) {
        if (c.coef[i] != 0) {
            if (!first) {
                printf(" + ");
            }
            printf("%3.1fx^%d", c.coef[i], i);
            first = 0; // 첫 번째 항 이후부터는 +를 출력
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
    polynomial b = { 4,{ 7, 0, 5, 0, 1 } };

    polynomial c;

    c.degree = plus_minus(a.degree,b.degree);

    for (int i=0; i<c.degree + 1; i++) {
        float a_coef = (i <= a.degree) ? a.coef[i] : 0;
        float b_coef = (i <= b.degree) ? b.coef[i] : 0;
        c.coef[i] = a_coef + b_coef;
    }

    print_poly(c);

    return 0;
}

