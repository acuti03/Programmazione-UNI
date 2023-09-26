#include <stdio.h>

int main(){
/*
    int x = 69;
    int *p1 = &x;
    int **p2 = &p1;

    printf("contenuto di x: [%d], indirizzo di x: [%p]\n", x, &x);
    printf("contenuto di p1: [%p], indirizzo di p1: [%p]\n", p1, &p1);
    printf("contenuto di p2: [%p], indirizzo di p2: [%p]\n", p2, &p2);
*/

    int vet[] = {1, 5, 6};
    int *p1 = (vet + 1);
    int **p2 = &p1;
    int ***p3 = &p2;

    printf("contenuto di vet[1]: %d, indirizzo di vet: %p\n", *(vet + 1), vet + 1);
    printf("contenuto di p1: %p, indirizzp di p1: %p\n", p1, &p1);
    printf("contenuto di p2: %p, indirizzp di p2: %p\n", p2, &p2);
    printf("contenuto di p3: %p, indirizzo id p3: %p\n", p3, &p3);
    printf("contenuto di vet tramite p3: %d\n", *((**p3 + 0)));

    printf("\n");
    return 0;
}