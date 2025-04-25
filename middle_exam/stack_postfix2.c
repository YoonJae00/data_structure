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

// 연산자 우선순위 반환
int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

// 후위표기식으로 변환
void infix_to_postfix(const char *exp, char *output) {
    // 연산자 저장용 스택 초기화
    Stack s;
    init(&s);
    int k = 0;
    int len = strlen(exp);
    for (int i = 0; i < len; i++) {
        char ch = exp[i];
        if ((ch >= '0' && ch <= '9')) { // 피연산자(숫자)인 경우 바로 output 에 쌓음
            output[k++] = ch;
        } else if (ch == '(') { // 여는 괄호면 스택 사입
            push(&s, ch);
        } else if (ch == ')') {
            // 닫는 괄호 일시 여는 괄호가 나올 때까지 스택에서 연산자 꺼냄
            while (!is_empty(&s) && s.data[s.top] != '(') {
                output[k++] = pop(&s);
            }
            // 여는 괄호 제거
            pop(&s);
        } else {
            // 연산자인 경우 스택 top의 연산자와 우선순위 비교
            while (!is_empty(&s) && precedence(s.data[s.top]) >= precedence(ch)) {
                output[k++] = pop(&s);
                // 우선순위 높거나 같은 연산자 먼저 출력
            }
            // 현재 연산자 스택에 push
            push(&s, ch);
        }
    }
    // 남아있는 모든 연산자 출력
    while (!is_empty(&s)) {
        output[k++] = pop(&s);
    }
}

int main(void) {
    char infix[] = "(2+3)*4+9";
    char postfix[MAX_STACK_SIZE];
    infix_to_postfix(infix, postfix);
    printf("중위표기식: %s\n", infix);
    printf("후위표기식: %s\n", postfix);
    return 0;
}
