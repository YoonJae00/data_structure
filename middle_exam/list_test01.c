//
// Created by 김윤재 on 2025. 4. 28..
//

#define MAX_LIST_SIZE 200
#include <stdlib.h>
#include <stdio.h>
typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
}ArrayList;

void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

int is_empty(ArrayList *L) {
    return L->size == 0;
}

int is_full(ArrayList *L) {
    return L->size == MAX_LIST_SIZE;
}

void init(ArrayList *L) {
    L->size = 0;
}

element get_entry(ArrayList *L, int index) {
    if (index < 0 || L->size >= index) {
        error("위치 오류");
    }
    return L->array[index];
}

// 리스트 출력
void print_list(ArrayList *L) {
    int i;
    for (i = 0; i<L->size; i++)
        printf("%d->", L->array[i]);
    printf("\n");
}

void insert(ArrayList *L, int index, element val) {
    if (is_full(L) || L->size < index || index < 0) {
        error("잘못된 변수");
    }
    for (int i = (L->size - 1); i>=index; i--) {
        L->array[i+1] = L->array[i];
    }
    L->array[index] = val;
    L->size++;
}

void insert_last(ArrayList *L, element val) {
    if (L->size >= MAX_LIST_SIZE) {
        error("꽉참");
    }
    L->array[L->size] = val;

    L->size++;
}

element delete(ArrayList *L, int index) {
    if (index < 0 || L->size < index) {
        error("위치오류");
    }
    element item = L->array[index];
    for (int i = index; i<=L->size; i++) {
        L->array[i] = L->array[i + 1];
    }
    L->size--;
    return item;
}

int main(void) {
    // ArrayListType를 정적으로 생성하고 ArrayListType를
    // 가리키는 포인터를 함수의 매개변수로 전달한다.
    ArrayList list;
    init(&list);
    insert(&list, 0, 10); print_list(&list); // 0번째 위치에 10 추가
    insert(&list, 0, 20); print_list(&list); // 0번째 위치에 20 추가
    insert(&list, 0, 30); print_list(&list); // 0번째 위치에 30 추가
    insert_last(&list, 40); print_list(&list); // 맨 끝에 40 추가
    delete(&list, 0); print_list(&list); // 0번째 항목 삭제
    return 0;
}