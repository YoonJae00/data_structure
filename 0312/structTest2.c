//
// Created by 김윤재 on 2025. 3. 12..
//


#include <stdio.h>
#include <string.h>


struct student {
    int number;
    char name[10];
    double grade;
};

int main() {

    struct student c;
    c.number = 10;
    strcpy(c.name, "매롱매롱");
    c.grade=80.2;


    printf("학번 : %d \n",c.number);
    printf("이름 : %s \n",c.name);
    printf("성적  %.2lf \n",c.grade);
    printf("구조체 크기 : %d", sizeof(c));

    return 0;
}

