#include <stdio.h>


int main(){
    int a;
    int *pa;

    pa = &a;

    scanf("%d", &a);
    printf("*pa: %d\n", *pa);

    return 0;
}