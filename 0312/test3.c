#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *pi;

    pi = (int*) malloc(sizeof(int));

    if (pi == NULL) {
        printf("메모리오류");
        exit(1);

    }
    *pi = 100;

    printf("%d \n",*pi);

    free(pi);

    return 0;
}