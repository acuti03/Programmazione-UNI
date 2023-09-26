#include <stdio.h>

int main(){
    int a = 2;
    int *pa;

    pa = &a;
    printf("\nIndirizzo di pa: %x. \nContenuto di pa: %d", &pa, *pa);
    pa -= 4;
    printf("\nIndirizzo di pa: %x. \nContenuto di pa: %d", &pa, *pa);

    printf("\n");
    return 0;
}