//
// Created by 김윤재 on 2025. 5. 7..
//


#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int coef; // 계수
    int expon; // 차수
    struct ListNode *link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 리스트 헤더 타입
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

// 오류 함수
void error(char *message) {
    fprintf(stderr , "%s\n", message);
    exit(1);
}

ListType* create() {
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
    ListNode* temp =
    (ListNode *)malloc(sizeof(ListNode));
    if (temp == NULL) error("메모리 할당 에러");
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;
    if (plist->tail == NULL) {
        plist->head = plist->tail = temp;
    }
    else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;
    int sum;
    while (a && b) {
        if (a->expon == b->expon) { // a의 차수 == b의 차수
            sum = a->coef + b->coef;
            if (sum != 0) insert_last(plist3, sum, a->expon);
            a = a->link; b = b->link;
        }
        else if (a->expon > b->expon) { // a의 차수 > b의 차수
            insert_last(plist3, a->coef, a->expon);
            a = a->link;
        }
        else { // a의 차수 < b의 차수
            insert_last(plist3, b->coef, b->expon);
            b = b->link;
        }
    }
    // a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두
    // 결과 다항식으로 복사
    for (; a != NULL; a = a->link)
        insert_last(plist3, a->coef, a->expon);
    for (; b != NULL; b = b->link)
        insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist) {
    ListNode* p = plist->head;
    printf("polynomial = ");
    for (; p; p = p->link) {
        printf("%d^%d + ", p->coef, p->expon);
    }
    printf("\n");
}


int main(void) {
    ListType *list1, *list2, *list3;
    // 연결 리스트 헤더 생성
    list1 = create();
    list2 = create();
    list3 = create();
    // 다항식 1을 생성
    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);
    // 다항식 2를 생성
    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);
    poly_print(list1);
    poly_print(list2);
    // 다항식 3 = 다항식 1 + 다항식 2
    poly_add(list1, list2, list3);
    poly_print(list3);
    free(list1); free(list2); free(list3);
}