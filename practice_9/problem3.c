// 게임공학과, 2023180011, 김윤재

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;

int is_empty(ListNode* head) {
    return head == NULL;
}

ListNode* clear(ListNode* head) {
    printf("리스트를 초기화 합니다.\n");
    if (!head) return NULL;
    // head가 꼬리, head->link가 첫 노드
    ListNode* first = head->link;
    ListNode* p = first;
    while (p != head) {
        ListNode* tmp = p->link;
        free(p);
        p = tmp;
    }
    free(head);
    return NULL;
}

void print_list(ListNode* head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    ListNode* p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head->link);
    printf("\n");
}

ListNode* insert_first(ListNode* head, int item) {
    printf("첫번째에 %d를 삽입합니다.\n", item);
    ListNode* node = malloc(sizeof(ListNode));
    if (!node) { fprintf(stderr, "메모리 할당 에러\n"); exit(1); }
    node->data = item;
    if (!head) {
        node->link = node;
        return node;
    }
    node->link = head->link;
    head->link = node;
    return head;
}

ListNode* insert_last(ListNode* head, int item) {
    printf("마지막에 %d를 삽입합니다.\n", item);
    ListNode* node = (ListNode *)malloc(sizeof(ListNode));
    if (!node) { fprintf(stderr, "메모리 할당 에러\n"); exit(1); }
    node->data = item;
    if (!head) {
        node->link = node;
        return node;
    }
    node->link = head->link;
    head->link = node;
    return node;
}

ListNode* insert(ListNode* head, int pos, int item) {
    int len = 0;
    if (head) {
        ListNode* q = head->link;
        do { len++; q = q->link; } while (q != head->link);
    }
    // 범위 벗어나면 pos 메시지 후 오류
    if (pos < 1 || pos > len + 1) {
        printf("%d번째에 %d를 삽입합니다.\n", pos, item);
        printf("위치 오류\n");
        return head;
    }
    // 맨 앞 삽입
    if (pos == 1) {
        return insert_first(head, item);
    }
    // 맨 뒤 삽입
    if (pos == len + 1) {
        return insert_last(head, item);
    }
    // 중간 삽입
    printf("%d번째에 %d를 삽입합니다.\n", pos, item);
    ListNode* p = head->link;
    for (int i = 1; i < pos - 1; i++) p = p->link;
    ListNode* node = (ListNode *)malloc(sizeof(ListNode));
    if (!node) { fprintf(stderr, "메모리 할당 에러\n"); exit(1); }
    node->data = item;
    node->link = p->link;
    p->link = node;
    return head;
}

ListNode* delete_first(ListNode* head) {
    if (!head) return NULL;
    ListNode* first = head->link;
    if (first == head) {
        free(head);
        return NULL;
    }
    head->link = first->link;
    free(first);
    return head;
}

ListNode* delete_last(ListNode* head) {
    if (!head) return NULL;
    printf("마지막 노드를 삭제합니다.\n");
    ListNode* p = head->link;
    if (p == head) {
        free(head);
        return NULL;
    }
    while (p->link != head) p = p->link;
    p->link = head->link;
    free(head);
    return p;
}

ListNode* delete(ListNode* head, int pos) {
    int len = 0;
    if (head) {
        ListNode* q = head->link;
        do { len++; q = q->link; } while (q != head->link);
    }
    printf("%d번째를 삭제합니다.\n", pos);
    if (pos < 1 || pos > len) {
        printf("위치 오류\n");
        return head;
    }
    if (pos == 1) return delete_first(head);
    if (pos == len) return delete_last(head);
    ListNode* p = head->link;
    for (int i = 1; i < pos - 1; i++) p = p->link;
    ListNode* tmp = p->link;
    p->link = tmp->link;
    free(tmp);
    return head;
}

// 값 탐색
void search(ListNode* head, int item) {
    if (!head) {
        printf("%d가 없습니다.\n", item);
        return;
    }
    ListNode* p = head->link;
    int pos = 1;
    do {
        if (p->data == item) {
            printf("%d번째에 있습니다.\n", pos);
            return;
        }
        p = p->link;
        pos++;
    } while (p != head->link);
    printf("%d가 없습니다.\n", item);
}

// 특정 위치 값 반환
int get_entry(ListNode* head, int pos) {
    int len = 0;
    if (head) {
        ListNode* q = head->link;
        do { len++; q = q->link; } while (q != head->link);
    }
    if (pos < 1 || pos > len) {
        printf("%d번째 값은 없습니다.\n", pos);
        return -1;
    }
    ListNode* p = head->link;
    for (int i = 1; i < pos; i++) p = p->link;
    printf("%d번째 값은 %d 입니다.\n", pos, p->data);
    return p->data;
}

int main(void){
ListNode* head = NULL;
head = insert_first(head, 10); print_list(head);
head = insert(head, 2, 20); print_list(head);
head = insert(head, 2, 30); print_list(head);
head = insert(head, 3, 40); print_list(head);
head = insert(head, 5, 50); print_list(head);
head = insert(head, 8, 60); print_list(head);
head = insert_last(head, 70); print_list(head);
printf("첫번째에 노드를 삭제합니다.\n");
head = delete_first(head); print_list(head);
head = delete(head, 1); print_list(head);
search(head, 30);
get_entry(head, 3);
head = clear(head);
if (is_empty(head)) 
printf("리스트가 비어있습니다.\n");
return 0;
}

