//
// Created by 김윤재 on 2025. 3. 12..
//

#include <stdio.h>



int add(int,int);
int (*p)(int,int);

int main() {

    int res;
    int x,y;

    p = add;
    res = p(x,y);

    printf("두 정수 입력;");
    scanf("%d %d",&x, &y);

    printf("%d",res);
    return 0;
}