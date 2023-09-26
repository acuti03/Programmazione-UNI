#include <stdio.h>

#define ABS(a) a < 0 ? -a : a

int main(){
    int a = 12;

    printf("\nValore assoluto: %d", ABS(a));

    a = -10;
    
    printf("\nValore assoluto: %d\n", ABS(a));

    return 0;
}