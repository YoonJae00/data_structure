/*
 * 게임공학과, 2023180011, 김윤재
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 괄호 검사 매커니즘 만들기
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

// 괄호 검사 매커니즘
int check_matching(const char *in) {

    Stack s; // 스택 선언
    char ch, open_ch;
    int n = strlen(in); // 문자열 숫자 파악
    init(&s); // 스택 초기화

    for (int i=0; i<n; i++) { // 입력받은 문자열 갯수만큼 반복문
        ch = in[i]; // 글자 하나씩 뽑기
        switch (ch) {
            case '[' : case '{' : case '(': // case 로 뽑기
                push(&s,ch); // 스택에 푸쉬
                break;
            case ']' : case '}' : case ')': // 닫는 괄호 case
                if (is_empty(&s)) return 0; // 스택 비어있는지 확인
                else {
                    open_ch = pop(&s); // 스택에 있는 괄호 뽑기
                    if ((open_ch == '(' && ch != ')') || // 조건 검사
                        (open_ch == '[' && ch != ']') ||
                        (open_ch == '{' && ch != '}')) {
                        return 0;
                        }
                    break;
                }
        }
    }
    if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
    return 1;
}


int main(void) {
    char *p = "{ A[(i+1)]=0; }";
    char *q = "{(a+b)*k[2+3*n]}";
    char *r = "{[2+10)*u]/3]";
    if (check_matching(p) == 1)
        printf("%s 괄호검사성공\n", p);
    else
        printf("%s 괄호검사실패\n", p);

    if (check_matching(q) == 1)
        printf("%s 괄호검사성공\n", q);
    else
        printf("%s 괄호검사실패\n", q);

    if (check_matching(r) == 1)
        printf("%s 괄호검사성공\n", r);
    else
        printf("%s 괄호검사실패\n", r);

    return 0;

}
