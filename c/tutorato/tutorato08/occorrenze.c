#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void occorenze(int *a, int *n, int *elemento, int *ripetizioni){
    int i, j;
    int tmp;

    for(i = 0; i < *n; i++){
        tmp = 1;
        for(j = i + 1; j < *n; j++){
            if(*(a + i) == *(a + j)){
                tmp++;
            }
        }
        if(tmp > *ripetizioni){
            *ripetizioni = tmp;
            *elemento = *(a + i);
        }
    }
}


void riempimento(int *a, int *n, int *k){
    int i;
//  *(a + i) = a[i]
    for(i = 0; i < *n; i++){
        *(a + i) = rand() % *k;
        printf("%d ", *(a + i));
    }
}

int main(){
    srand(time(NULL));
    int n ,k;
    int elemento, ripetizioni = 1;

//  INSERIMENTO DI N E K
    do{
        scanf("%d",&n);
    }while(n > 100);

    do{
        scanf("%d",&k);
    }while(k > n);

    int vet[n];
    riempimento(vet, &n, &k);

    occorenze(vet, &n, &elemento, &ripetizioni);
    printf("\nL'elemento che si ripete di piu: %d ha %d ripetizioni", elemento, ripetizioni);

    printf("\n");
    return 0;
}