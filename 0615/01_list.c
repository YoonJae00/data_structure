//
// Created by YoonJae on 2025-06-15.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
} ListNode;

typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

ListType *create() {
    ListType *plist = malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void insert_last(ListType *pl, int coef, int expon) {
    ListNode *temp = malloc(sizeof(ListNode));
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;

    if (pl->tail == NULL) {
        pl->head = pl->tail = temp;
    } else {
        pl->tail->link = temp;
        pl->tail = temp;
    }
    pl->size++;
}

void poly_add(ListType *list1, ListType *list2, ListType *list3) {
    ListNode *a = list1->head;
    ListNode *b = list2->head;
    int sum;

    while (a && b) {
        if (a->expon == b->expon) {
            sum = a->coef + b->coef;
            if (sum != 0) {
                insert_last(list3,sum,a->expon);
            }
            a = a->link; b = b->link;
        } else if (a->expon > b->expon) {
            insert_last(list3,a->coef,a->expon);
            a = a->link;
        } else {
            insert_last(list3,b->coef,b->expon);
            b = b->link;
        }
    }

    for (; a!=NULL; a=a->link) {
        insert_last(list3,a->coef,a->expon);
    }
    for (; b!=NULL; b=b->link) {
        insert_last(list3,b->coef,b->expon);
    }
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