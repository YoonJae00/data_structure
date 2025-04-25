//
// Created by 김윤재 on 2025. 3. 26..
//


#include <stdio.h>

typedef struct studentTag {
    char name[10]; // 문자배열로 된 이름
    int age; // 나이를 나타내는 정수값
    double gpa; // 평균평점을 나타내는 실수값
} student;

int main() {

    student a = { "kim", 20, 4.3 };

    return 0;
}