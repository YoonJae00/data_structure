//
// Created by 김윤재 on 2025. 4. 19..
//


#include <stdio.h>
#include <stdlib.h>
#define MAX_TERM 101
// (계수, 차수) 형식으로 배열에 저장
// (예) 10x^5+6x+3 -> ((10,5), (6,1), (3,0))
typedef struct {
    float coef; // 계수
    int expon; // 차수
} Term;

Term terms[MAX_TERM] =  { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} };

int avail=6;

char compare(int a, int b) {
    if (a > b) {
        return '>';
    } else if (a < b) {
        return '<';
    } else {
        return '=';
    }
};

void attach(float coef, int expon) {
    if ( avail > MAX_TERM) {
        printf("항의 개수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef=coef;
    terms[avail++].expon=expon;
}

// C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
    float tempcoef;
    *Cs = avail;
    while ( As < Ae && Bs < Be) {
        switch (compare(terms[As].expon,terms[Bs].expon)) {
            case '>' :
                attach(terms[As].coef, terms[As].expon);
                As++; Ae++;
                break;
            case '<' :
                attach(terms[Bs].coef, terms[Be].expon);
                Bs++; Be++;
                break;
            case '=' :
                attach(terms[As].coef+terms[Bs].coef, terms[As].expon + terms[Bs].expon);
                As++; Ae++; Bs++; Be++;
                break;
        }
    }

}


void print_poly(int s, int e) {
    for (int i = s; i < e; i++)
        printf("%3.1fx^%d +", terms[i].coef, terms[i].expon);
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main(int argc, char *argv[]) {

    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("-----------------------------------------------------------------------------\n");
    print_poly(Cs, Ce);


    return 0;
}
