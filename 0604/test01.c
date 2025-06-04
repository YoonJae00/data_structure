//
// Created by 김윤재 on 2025. 6. 4..
//

#include <stdlib.h>
#include <stdio.h>

typedef static ListNode{
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

ListType* create() {

}