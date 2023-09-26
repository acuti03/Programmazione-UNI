#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int massimo(int *vet, int *n){
    int i = 0;
    int max = vet[i];

    for(i = 0; i < *n; i++){
        if(vet[i] > max){
            max = vet[i];
        }
    }
    return max;
}


void lettura(int *n){
    srand(time(NULL));
    int i;

    scanf("%d",&*n);

    int vet[*n];

    for(i = 0; i < *n; i++){
        vet[i] = rand() % 100 + 1;
    }

    printf("\n");
    for(i = 0; i < *n; i++){
        printf("%d ",vet[i]);
    }

    printf("\nL'elemento massimo: %d",massimo(vet, n));
}


int main(){
    int n;
    lettura(&n);


    printf("\n");
    return 0;
}
