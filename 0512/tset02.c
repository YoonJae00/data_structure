//
// Created by 김윤재 on 2025. 5. 12..
//

// 연결 리스트 스택

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
    element data;
    struct StackNode *link;
} StackNode;

typedef struct {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *L) {
    L->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s) {
    return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType *s) {
    return 0; // 포화 안됨
}

void push(LinkedStackType *s, element val) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp -> data = val;
    temp -> link = s->top;
    s->top = temp;
}

void print_stack(LinkedStackType *s) {
    for (StackNode *p = s->top; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

element pop(LinkedStackType *s) {
    if (is_empty(s)) {
        exit(1);
    }

    StackNode *temp = s->top;
    int data = temp->data;
    s->top = s->top->link;
    free(temp);
    return data;
}

int main(void) {
    LinkedStackType s;
    init(&s);
    push(&s, 1); print_stack(&s);
    push(&s, 2); print_stack(&s);
    push(&s, 3); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    pop(&s); print_stack(&s);
    return 0;
}
