//
// Created by 김윤재 on 2025. 4. 19..
//

#include <stdio.h>
#include <c++/v1/cstdlib>
#include <malloc/malloc.h>
#include <secure/_string.h>

typedef struct {
    char name[100];
    int age;
    float gpa;
} student;

int main(void) {

    student *s;
    s = (student *)malloc(sizeof(student));
    if (s == NULL) {
        fprintf(stderr,"메모리가 부족해서 할당할 수 없습니다.\n");
        exit(1);
    }
    strcpy(s->name,"매렁");
    s->age = 20;
    free(s);
    return 0;
}
