//
// Created by 김윤재 on 2025. 3. 19..
//

#include <stdio.h>

int sub(int n)
{
    if( n < 0 ) return(0);
    else return (n + sub(n-3) );
}

int main(void) {

    int a = sub(10);

    printf("a %d", a);
    return 0;
}