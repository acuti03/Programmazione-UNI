#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5
#define MOD(a) a < 0 ? -a : a


int main(){
    srand(time(NULL));
    int i;
    int vet[5];
    int n;
    int min;

    for(i=0; i<DIM; i++){
        vet[i] = rand() % (100 - (-100) + 1) + (-100);
        vet[i] = MOD(vet[i]);
    }

    min = vet[0];

    for(i=0; i<DIM; i++){
        printf("%d ",vet[i]);
        if(vet[i] < min) min = vet[i];
    }

    printf("\nIl minimo è: %d\n", min);
    return 0;

}