//
// Created by 김윤재 on 2025. 4. 14..
//

// 원형 큐

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// ===== 원형큐 코드 시작======
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // 큐 타입
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char *message) {
    fprintf(stderr , "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
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

void enqueue(QueueType *q, element item) {
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        error("큐가 비어있습니다.");
    }
    q->front = (q->front +1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int main(void)
{
    QueueType queue;
    int element;
    init_queue(&queue);
    int a;
    printf("1.--데이터 추가 단계--\n 2.--데이터 삭제 단계--\n");
    scanf("%d",&a);
    while (true) {
        switch (a) {
            case 1: {
                printf("정수를 입력하시오: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                queue_print(&queue);
            } break;
            case 2:
            {
                element = dequeue(&queue);
                printf("꺼내진 정수: %d \n", element);
                queue_print(&queue);
            } break;
            case 9:
                exit(1);
        }
    }


    return 0;
}