//
// Created by 김윤재 on 2025. 5. 12..
//


#include <stdio.h>
#include <stdlib.h>


// 연결 큐
typedef int element;
typedef struct {
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} LinkedQueueType;

void init(LinkedQueueType *s) {
    s->rear = 0;
    s->front = 0;
}

int is_empty(LinkedQueueType *s) {
    return s->front == s->rear;
}

void enqueue(LinkedQueueType *s, element val) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(s));
    temp->data = val;
    temp->link = NULL;

    if (is_empty(s)) {
        s->front = temp;
        s->rear = temp;
    } else {

    }
}


int main(void) {

    return 0;
}
