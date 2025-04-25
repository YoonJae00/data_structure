//
// Created by 김윤재 on 2025. 4. 18..
//


#include <stdio.h>

double power(double x, int n) {
    if( n==0 ) return 1;
    else if ( (n%2)==0 )
        return power(x*x, n/2);
    else return x*power(x*x, (n-1)/2);
}

int main() {

    double a = power(65536, 0);
    printf("%f", a);

    return 0;
}