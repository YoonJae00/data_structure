//
// Created by 김윤재 on 2025. 3. 31..
//

#include <stdio.h>
#define MAX_DEGREE 101 // 다항식의 최대차수 + 1
#define MAX(x, y) (x, y) ? x:y

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
    polynomial C;
    int Apos = 0;
    int Bpos = 0;
    int Cpos = 0;

    int degree_a = A.degree; // A 최대 차수
    int degree_b = B.degree; // B 최대 차수

    C.degree = MAX(A.degree, B.degree);

    while (Apos <= A.degree && Bpos <= B.degree) {
        if (degree_a > degree_b) { // A 차수가 더 큰 상황
            C.coef[Apos] = A.coef[Apos];
            degree_a--;
            Apos++;
        } else if (degree_a == degree_b) {
            C.coef[Apos] = A.coef[Apos] + B.coef[Bpos];
            degree_a--; degree_b--;
            Apos++; Bpos++;
        } else {
            C.coef[Bpos] = B.coef[Bpos];
            degree_b--;
            Bpos++;
        }
    }

    return C;
}

void print_poly(polynomial p)
{
    for (int i = p.degree; i>0; i--)
        printf("%3.1fx^%d +", p.coef[p.degree - i], i);
    printf("%3.1f \n", p.coef[p.degree]);
}

int main(void)
{
    polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
    polynomial b = { 4,{ 7, 0, 5, 0, 1 } };
    polynomial c;
    print_poly(a);
    print_poly(b);
    c = poly_add1(a, b);
    printf("-----------------------------------------------------------------------------\n");
    print_poly(c);
    return 0;
}
