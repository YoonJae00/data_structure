// 게임공학과, 2023180011, 김윤재

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int coef;               // 계수
    int expon;              // 차수
    struct ListNode *link;  // 다음 노드를 가리키는 포인터
} ListNode;

// 오류 처리: 메시지 출력 후 프로그램 종료
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_last(ListNode* head, int coef, int expon) {
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    if (!temp) error("메모리 할당 에러");
    temp->coef  = coef;
    temp->expon = expon;
    temp->link  = NULL;

    if (head == NULL) {
        return temp;
    } else {
        ListNode* p = head;
        while (p->link) {
            p = p->link;
        }
        p->link = temp;
        return head;
    }
}

ListNode* poly_add(ListNode* a, ListNode* b) {
    ListNode* head3 = NULL;  // 결과 리스트의 head
    int sum;

    // 두 리스트 모두 항이 남아 있는 동안
    while (a && b) {
        if (a->expon == b->expon) {
            // 차수가 같으면 계수 합산
            sum = a->coef + b->coef;
            if (sum != 0)
                head3 = insert_last(head3, sum, a->expon);
            a = a->link;
            b = b->link;
        }
        else if (a->expon > b->expon) {
            // a 항의 차수가 더 크면 a 항 삽입
            head3 = insert_last(head3, a->coef, a->expon);
            a = a->link;
        }
        else {
            // b 항의 차수가 더 크면 b 항 삽입
            head3 = insert_last(head3, b->coef, b->expon);
            b = b->link;
        }
    }
    // 남은 항 복사
    while (a) {
        head3 = insert_last(head3, a->coef, a->expon);
        a = a->link;
    }
    while (b) {
        head3 = insert_last(head3, b->coef, b->expon);
        b = b->link;
    }
    return head3;
}

void poly_print(ListNode* head) {
    printf("polynomial = ");
    for (ListNode* p = head; p; p = p->link) {
        printf("%d^%d + ", p->coef, p->expon);
    }
    printf("\n");
}
int main(void) {
    // 세 개의 다항식 리스트를 위한 head 포인터
    ListNode *list1 = NULL, *list2 = NULL, *list3 = NULL;

    list1 = insert_last(list1, 3, 12);
    list1 = insert_last(list1, 2, 8);
    list1 = insert_last(list1, 1, 0);

    list2 = insert_last(list2, 8, 12);
    list2 = insert_last(list2, -3, 10);
    list2 = insert_last(list2, 10, 6);

    poly_print(list1);
    poly_print(list2);

    list3 = poly_add(list1, list2);
    poly_print(list3);
    free(list1); free(list2); free(list3);

    return 0;
}