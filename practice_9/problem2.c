// 게임공학과, 2023180011, 김윤재

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode* head) {
    ListNode* p = head;
    while (p) {
        printf("%d->", p->data);
        p = p->link;
    }
    printf("NULL\n");
}


ListNode* insert_first(ListNode* head, int item) {
    printf("첫번째에 %d를 삽입합니다.\n", item);
    ListNode* new_node = (ListNode *)malloc(sizeof(ListNode));
    if (!new_node) {
        fprintf(stderr, "메모리 할당 에러\n"); exit(1);
    }
    new_node->data = item;
    new_node->link = head;
    return new_node;
}

ListNode* insert(ListNode* head, int pos, int item) {
    // 현재 리스트 길이 계산
    int len = 0;
    for (ListNode* p = head; p; p = p->link) len++;

    // 메세지 출력
    printf("%d번째에 %d를 삽입합니다.\n", pos, item);
    // 위치 검사
    if (pos < 1 || pos > len + 1) {
        printf("위치 오류\n");
        return head;  // 변경 없이 반환
    }
    // 맨 앞 삽입
    if (pos == 1) {
        return insert_first(head, item);
    }
    // 그 외 위치에 삽입
    ListNode* p = head;
    for (int i = 1; i < pos - 1; i++) {
        p = p->link;  // 삽입 직전 노드까지 이동
    }
    ListNode* new_node = malloc(sizeof(ListNode));
    if (!new_node) {
        fprintf(stderr, "메모리 할당 에러\n");
        exit(1);
    }
    new_node->data = item;
    new_node->link = p->link;
    p->link = new_node;
    return head;
}

ListNode* delete_first(ListNode* head) {
    if (!head) return NULL;
    ListNode* temp = head;
    head = head->link;
    free(temp);
    return head;
}

ListNode* delete(ListNode* head, int pos) {
    // 현재 리스트 길이 계산
    int len = 0;
    for (ListNode* p = head; p; p = p->link) len++;
    // 위치 검사
    if (pos < 1 || pos > len) {
        printf("위치 오류\n");
        return head;
    }
    // 삭제 전 메시지: “X번째를 삭제합니다.”
    printf("%d번째를 삭제합니다.\n", pos);
    // 실제 삭제
    if (pos == 1) {
        ListNode* tmp = head;
        head = head->link;
        free(tmp);
    } else {
        ListNode* p = head;
        for (int i = 1; i < pos - 1; i++) p = p->link;
        ListNode* tmp = p->link;
        p->link = tmp->link;
        free(tmp);
    }
    return head;
}

void replace(ListNode* head, int pos, int item) {
    printf("%d번째 요소를 %d로 교체합니다.\n", pos, item);
    ListNode* p = head;
    for (int i = 1; p && i < pos; i++) p = p->link;
    if (p) p->data = item;
}

int get_entry(ListNode* head, int pos) {
    ListNode* p = head;
    for (int i = 1; p && i < pos; i++) p = p->link;
    if (p) {
        printf("%d번째 값은 %d 입니다.\n", pos, p->data);
        return p->data;
    } else {
        printf("위치 오류\n");
        return -1;
    }
}

int is_empty(ListNode* head) {
    return head == NULL;
}

ListNode* clear(ListNode* head) {
    printf("리스트를 초기화 합니다.\n");
    ListNode* p = head;
    while (p) {
        ListNode* temp = p;
        p = p->link;
        free(temp);
    }
    return NULL;
}

int main(void) {
    ListNode* head = NULL;
    head = insert_first(head, 10); print_list(head);
    head = insert(head,2,20); print_list(head);
    head = insert(head,3,30); print_list(head);
    head = insert(head,4,40); print_list(head);
    head = insert(head,5,50); print_list(head);
    replace(head, 3, 35); print_list(head);
    head = insert(head,8,60); print_list(head);
    printf("첫번째에 노드를 삭제합니다.\n");
    head = delete_first(head); print_list(head);
    head = delete(head,1); print_list(head);
    get_entry(head,3);
    head = clear(head);
    if (is_empty(head))
        printf("리스트가 비어있습니다.\n");
    return 0;
}