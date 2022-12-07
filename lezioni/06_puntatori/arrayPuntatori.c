#include <stdio.h>

int main() {
    int a[10], *p, i;

    for (i = 0, p = a; i < 10; i++, p++){
        *p = i;
        printf("\nIndirizzo di p: %x", p);
    }

    printf("\n\n");
    for (i = 0, p = a; i < 10; i++, p++){
        printf("%d\n", *p);
        printf("Indirizzo di p: %x\n", p);
    }

    printf("\n");
    return 0;
}