#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i;
    int vet[20];

    for(i=0; i<20; i++){
        vet[i] = (rand() % 30) + 1;
        printf("%d\n",vet[i]);
    }

    printf("\n");
}
