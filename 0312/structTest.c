//
// Created by 김윤재 on 2025. 3. 12..
//


// 구조체 like 클래스

#include <stdio.h>


struct employee {
    char name[10];
    int age;
    int salary;
};
int main() {

    struct employee a = {"hahaha", 10, 2000000};

    struct employee b;
    b.age=100;
    b.name="aaaaaa";





    return 0;
}