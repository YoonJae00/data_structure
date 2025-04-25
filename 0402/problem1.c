//
// Created by 김윤재 on 2025. 4. 2..
//

#include <stdio.h>

int sub(int n) {
    int temp = 0;
    while (n > 0) {
        temp += n;
        n -= 3;
    }
    return temp;
}

int main() {

    int a = sub(10);
    printf("sub 호출 : %d",a);

    return 0;
}

