/*
* 게임공학과, 2023180011, 김윤재
*/

#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 6

typedef struct {          // 좌표 한 칸
    short r;
    short c;
} element;

typedef struct {          // 스택
    element data[MAZE_SIZE * MAZE_SIZE];
    int top;
} Stack;

// 스택 초기화
void init(Stack *s) {
    s->top = -1;
}

// 비어있는지 확인
int is_empty(Stack *s) {
    return s->top == -1;
}

// 꽉차있는지 확인
int is_full(Stack *s) {
    return s->top == (MAZE_SIZE * MAZE_SIZE) - 1;
}

// 스택 top 인덱스에 푸쉬
void push(Stack *s, element c) {
    if (is_full(s) == 1) {
        printf("꽉참");
    } else {
        s->data[++s->top] = c;
    }
}

// 스택 하나 제거
element pop(Stack *s)
{
    if (is_empty(s)) {
        fprintf(stderr , "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

// 미로 출력 함수
void print_maze(char mz[MAZE_SIZE][MAZE_SIZE]) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c", mz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 범위/벽 체크 후 push
void push_loc(Stack *s, int r, int c, char maze[MAZE_SIZE][MAZE_SIZE]) {
    // 범위 검사
    if (r < 0) return;          // 위로 벗어남
    if (r >= MAZE_SIZE) return; // 아래로 벗어남
    if (c < 0) return;          // 왼쪽으로 벗어남
    if (c >= MAZE_SIZE) return; // 오른쪽으로 벗어남

    // 벽이면 못 감 길,출구면 push
    if (maze[r][c] == '0' || maze[r][c] == 'x') {
        element pos;
        pos.r = r;   // 행 좌표 저장
        pos.c = c;   // 열 좌표 저장
        push(s, pos);
    }
}

int main(void) {
    char maze[MAZE_SIZE][MAZE_SIZE] = {
        { '1','1','1','1','1','1' },
        { 'e','0','1','0','0','1' },
        { '1','0','0','0','1','1' },
        { '1','0','1','0','1','1' },
        { '1','0','1','0','0','x' },
        { '1','1','1','1','1','1' }
    };

    Stack s;
    init(&s);

    element here  = {1, 0};

    while (maze[here.r][here.c] != 'x') { // x 도달 할때까지 반복
        int r = here.r, c = here.c; // 현재위치

        maze[r][c] = '.';          // 방문 표시
        print_maze(maze);

        // 상하좌우 push
        push_loc(&s, r - 1, c, maze);
        push_loc(&s, r + 1, c, maze);
        push_loc(&s, r, c - 1, maze);
        push_loc(&s, r, c + 1, maze);

        if (is_empty(&s)) {        // 더 이상 갈 곳이 없으면 실패
            puts("실패");
            return 0;
        }
        here = pop(&s);            // 다음 위치
    }

    puts("성공");
    return 0;
}