//
// Created by 김윤재 on 2025. 4. 19..
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_STACK_SIZE - 1;
}

void push(int n) {
    if (is_full() == 1) {
        printf("꽉참");
    } else {
        stack[++top] = n;
        printf("현재 top 위치 : %d \n", top);
    }
}

int pop() {
    if (is_empty() == 1) {
        printf("뺼게 없음");
        return 0;
    } else {
        return stack[top--];
    }
}

int peek() {
    return stack[top];
}

int main(void) {

    push(1);
    printf("%d\n", peek());
    push(2);
    push(3);
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;

    return 0;
}
