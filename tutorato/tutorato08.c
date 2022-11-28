#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void duplicati(){
    char s1[100];
    char s2[100];
}


void ricerca(int *a, int *elemento, int *occorrenze, int n){
    int i, j;
    int tmp;
    
    for(i = 0; i < n; i++){
        tmp = 0;
        for(j = i; j < n; j++){
            if(a[i] == a[j]){
                tmp++;
                if(tmp > *occorrenze){
                    *occorrenze = tmp;
                    *elemento = a[i];
                }
            }
        }
    }

}


void occorrenze(){
    srand(time(NULL));
    int n, k;
    int i;
    int elemento, occorrenze = 0;

    printf("Inserisci il numero di elementi:");
    do{
        scanf("%d", &n);
    }while(n < 0 && n > 100);

    int vet[n];

    printf("Inserisci il range degli elementi:");
    do{
        scanf("%d", &k);
    } while (k > n);

    printf("\nIL tuo array:\n");
    for(i = 0; i < n; i++){
        vet[i] = rand() % k;
        printf("%d ",vet[i]);
    }

    ricerca(vet, &elemento, &occorrenze, n);
    printf("\n\nL'elemento con le massime occorrenze è: %d e sono: %d",elemento, occorrenze);

}


int main(){
    int scelta;

    printf("\n1. occorreze\n");
    printf("\n2. rimuovi duplicati\n");
    printf(":");
    scanf("%d",&scelta);

    switch (scelta){
    case 1:
        system("clear");
        occorrenze();
        break;
    
    case 2:

    default:
        break;
    }

    printf("\n");
    return 0;

}