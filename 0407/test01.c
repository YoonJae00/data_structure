//
// Created by 김윤재 on 2025. 4. 7..
//


#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5 // 스택 사이즈
typedef int element; // 데이터의 자료형
element stack[MAX_STACK_SIZE]; // 1차원 배열
int top = -1;

// 공백 상태 검출 함수
int is_empty()
{
    return (top == -1);
}
// 포화 상태 검출 함수
int is_full()
{
    return (top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(element item)
{
    if (is_full()) {
        fprintf(stderr , "스택 포화 에러\n");
        return;
    }
    else stack[++top] = item;
}
// 삭제 함수
element pop()
{
    if (is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return stack[top--];
}

int main(void)
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    for (int i=0; i<top; i++) {
        printf("스택 %d 번째 : %d\n", i ,stack[i]);
    }
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}
