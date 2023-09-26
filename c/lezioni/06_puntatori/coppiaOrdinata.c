#include <stdio.h>

void scambia(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}


void verifica(int *a, int *b){
    if(*a > *b){
        scambia(a, b);
    }
}


int main(){
    int a = 3;
    int b = 2;

    verifica(&a, &b);
    printf("\nLa coppia ordinata (%d-%d)", a,b);

    printf("\n");
    return 0;
}