//
// Created by 김윤재 on 2025. 5. 14..
//


#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode *phead) { // 초기화
    phead->llink = phead; // 왼쪽 링크 헤드에 붙임
    phead->rlink = phead; // 마찬가지
}

void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d| |-> ", p->data);
    }
    printf("\n");
}

void d_insert(DListNode *before, element data) {

    DListNode *newNode = (DListNode *)malloc(sizeof(element));
    newNode->data = data;
    newNode->llink = before;
    newNode->rlink = before->rlink;
    before->rlink->llink = newNode;
    before->rlink = newNode;
    // newNode->llink->rlink = before->rlink;
}

void d_remove(DListNode* head, DListNode* removed_node) {
    if (removed_node == head) return;
    removed_node->llink->rlink = removed_node->rlink;
    removed_node->rlink->llink = removed_node->llink;

    free(removed_node);
}

int main(void) {

    return 0;
}
