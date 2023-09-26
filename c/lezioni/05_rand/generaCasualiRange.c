#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int i;
    int vet[20];

//  VOGLIO CHE MI STAMPI DA -100 A 100
    for(i=0; i<20; i++){
        vet[i] = (rand() % (100 - (-100) + 1)) - 100;
        printf("%d ", vet[i]);
    }

    printf("\n");
    return 0;
}