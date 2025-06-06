//
// Created by 김윤재 on 2025. 4. 27..
//


#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;


// 오류 함수
void error(char *message) {
    fprintf(stderr , "%s\n", message);
    exit(1);
}

void init(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

// 원형큐 출력 함수
void queue_print(QueueType *q) {
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element val) {
    if (is_full(q)) {
        error("큐 꽉참");
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = val;
}

element dequeue(QueueType *q) {
    if (is_empty((q))) {
        error("큐 비었음");
    }

    q->front = (q->front+1 % MAX_QUEUE_SIZE);
    return q->data[q->front];
}

int main(void) {
    QueueType queue;
    int element;
    init(&queue);
    printf("--데이터 추가 단계--\n");
    while (!is_full(&queue))
    {
        printf("정수를 입력하시오: ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("큐는 포화상태입니다.\n\n");
    printf("--데이터 삭제 단계--\n");
    while (!is_empty(&queue))
    {
        element = dequeue(&queue);
        printf("꺼내진 정수: %d \n", element);
        queue_print(&queue);
    }
    printf("큐는 공백상태입니다.\n");
    return 0;
}