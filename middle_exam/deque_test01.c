//
// Created by 김윤재 on 2025. 4. 27..
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_DEQUEUE_SIZE 5
typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_DEQUEUE_SIZE];
}DeQueue;

// 오류 함수
void error(char *message) {
    fprintf(stderr , "%s\n", message);
    exit(1);
}

void init(DeQueue *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(DeQueue *q) {
    return q->front == q->rear;
}

int is_full(DeQueue *q) {
    return (q->rear +1) % MAX_DEQUEUE_SIZE == q->front;
}

void deque_print(DeQueue *q){
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_DEQUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void add_rear(DeQueue *q, element val) {
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_DEQUEUE_SIZE;
    q->data[q->rear] = val;
}

void add_front(DeQueue *q, element val) {
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->front = (q->front - 1 + MAX_DEQUEUE_SIZE) % MAX_DEQUEUE_SIZE;
    q->data[(q->front + 1) % MAX_DEQUEUE_SIZE] = val;
}

element delete_rear(DeQueue *q) {
    if (is_empty(q)) {
        error("큐가 공백임");
    }

    q->rear = (q->rear - 1 + MAX_DEQUEUE_SIZE) % MAX_DEQUEUE_SIZE;
    return q->data[q->rear];
}

element delete_front(DeQueue *q) {
    if (is_empty(q)) {
        error("큐가 공백임");
    }

    q->front = (q->front +1) % MAX_DEQUEUE_SIZE;
    return q->data[q->front];
}

element get_front(DeQueue *q) {
    if (is_empty(q)) {
        error("큐가 공백임");
    }
    return q->data[(q->front+1) % MAX_DEQUEUE_SIZE];
}

element get_rear(DeQueue *q) {
    if (is_empty(q)) {
        error("큐가 공백임");
    }
    return q->data[q->rear];
}

int main(void) {
    DeQueue queue;
    init(&queue);
    for (int i = 0; i < 3; i++) {
        add_front(&queue, i);
        deque_print(&queue);
    }
    for (int i = 0; i < 3; i++) {
        delete_rear(&queue);
        deque_print(&queue);
    }
    return 0;
}
