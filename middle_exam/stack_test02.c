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

// 중위표기식을 후위표기식으로 변환
void infix_to_postfix(const char *exp, char *output) {
    Stack op_stack;
    init(&op_stack);
    int k = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if ((ch >= '0' && ch <= '9')) {
            output[k++] = ch;
        } else if (ch == '(') {
            push(&op_stack, ch);
        } else if (ch == ')') {
            while (!is_empty(&op_stack) && op_stack.data[op_stack.top] != '(') {
                output[k++] = pop(&op_stack);
            }
            pop(&op_stack); // '(' 제거
        } else { // 연산자
            while (!is_empty(&op_stack) && precedence(op_stack.data[op_stack.top]) >= precedence(ch)) {
                output[k++] = pop(&op_stack);
            }
            push(&op_stack, ch);
        }
    }
    // 남은 연산자 처리
    while (!is_empty(&op_stack)) {
        output[k++] = pop(&op_stack);
    }
    output[k] = '\0';
}

int main(void) {
    char infix[] = "(2+3)*4+9";
    char postfix[MAX_STACK_SIZE];
    infix_to_postfix(infix, postfix);
    printf("중위표기식: %s\n", infix);
    printf("후위표기식: %s\n", postfix);
    return 0;
}
