/*
* 게임공학과, 2023180011, 김윤재
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 정수 순서 뒤집기
#define MAX_STACK_SIZE 100

typedef struct {
    char data[MAX_STACK_SIZE];
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
    return s->top == MAX_STACK_SIZE - 1;
}

// 스택 top 인덱스에 푸쉬
void push(Stack *s, char c) {
    if (is_full(s) == 1) {
        printf("꽉참");
    } else {
        s->data[++s->top] = c;
    }
}


// 스택 하나 제거
char pop(Stack *s)
{
    if (is_empty(s)) {
        fprintf(stderr , "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}


int main(void) {
    Stack s;
    init(&s);

    int n;
    printf("정수 배열의 크기: ");
    scanf("%d", &n);

    int x;
    printf("정수를 입력하세요 : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        // 입력된 원소를 스택에 push
        push(&s, x);
    }

    // 스택에서 꺼내면서 출력 → 입력 순서의 역순
    printf("반전된 정수 배열: ");
    while (!is_empty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");

    return 0;
}
