/*
* 게임공학과, 2023180011, 김윤재
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 후위표기식 매커니즘
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

// 후위 표기 계산
int eval(char exp[]) {
    Stack s;
    init(&s);
    char ch;
    int value, op1, op2;
    int len = strlen(exp);

    for (int i=0; i<len; i++) {
        ch = exp[i]; // 글자 하나 꺼내기
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { // 피연산자(숫자) 일시
            value = ch - '0'; // 문자형 숫자 아스키로 변환
            push(&s,value); // 스택에 푸쉬
        } else {
            op2 = pop(&s); // 글자 1 꺼내기
            op1 = pop(&s); // 글자 2 꺼내기
            switch (ch) { //연산을 수행하고 스택에 저장
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }

    return pop(&s);
}


int main(void) {
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    return 0;
}
