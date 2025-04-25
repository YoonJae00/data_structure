//
// Created by 김윤재 on 2025. 4. 19..
//

#include <stdio.h>
#define MAX_TERM 101
typedef struct {
    int row;
    int col;
    int val;
} element;

typedef struct {
    element data[MAX_TERM];
    int rows; // 전체 행 갯수
    int cols; // 전체 열 갯수
    int terms; // 실제로 값이 있는 항의 갯수
} Sparse_matrix;

Sparse_matrix matrix_transformer(Sparse_matrix a) {

    Sparse_matrix b;
    // 행 -> 열  // 열 -> 행 으로 바꾸기
    // 값은 data 안에 들어있음
    int bindex; // 행렬 b에서 현재 저장 위치
    b.rows = a.rows;
    b.cols = a.cols;
    b.terms = a.terms;

    if (a.terms > 0) {
        bindex = 0;
        for (int c = 0; c < a.cols; c++) {
            for (int i = 0; i < a.terms; i++) {
                if (a.data[i].col == c) {
                    b.data[bindex].row = a.data[i].col;
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].val = a.data[i].val;
                    bindex++;
                }
            }
        }
    }

    return b;
}

void matrix_print(Sparse_matrix a) {
    printf("====================\n");
    for (int i = 0; i<a.terms; i++) {
        printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].val);
    }
    printf("====================\n");
}

int main(int argc, char *argv[]) {

    Sparse_matrix m = {
        { { 0, 3, 7 },{ 1, 0, 9 },{ 1, 5, 8 },{ 3, 0, 6 },{ 3, 1, 5 },{ 4, 5, 1 },{ 5, 2, 2 } },
        6,
        6,
        7
        };
    Sparse_matrix result;
    result = matrix_transformer(m);
    matrix_print(result);
    return 0;
}
