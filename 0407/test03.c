//
// Created by 김윤재 on 2025. 4. 7..
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100 // 스택 사이즈

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s -> top == -1);
}

int is_full(StackType *s) {
    return (s -> top == MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr , "스택 포화 에러\n");
        return;
    } else {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr , "스택 공백 에러\n");
        exit(1);
    } else {
        return s->data[(s->top)--];
    }
}

int check_matching(const char *in) {
    StackType s;
    char ch, open_ch;

    int i,n = strlen(in);
    init_stack(&s);

    for (i = 0; i<n; i++) {
        ch = in[i];
        switch (ch) {
            case '[' :
            case '{' :
            case '(' :
                push(&s, ch);
                break;
            case ']' :
            case '}' :
            case ')' :
                if (is_empty(&s)) return 0;
                else {
                    open_ch = pop(&s);
                    if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}')) {
                        return 0;
                    }
                }
        }
    }
    if (!is_empty(&s)) return 0;
    return 1;
}

int main(void) {
    bool a = true;
    while (a) {
        char input[MAX_STACK_SIZE];
        printf("괄호 문자열을 입력하세요: ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            a = false;
            continue;
        }
        if (check_matching(input))
            printf("올바른 괄호입니다.\n");
        else
            printf("잘못된 괄호입니다.\n");

    }
    return 0;
}