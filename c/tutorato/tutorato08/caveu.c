#include <stdio.h>
#include <stdlib.h>
#define DIM 20

typedef struct{
    char nome[DIM];
    int valore;
} Pietra;


void inserimento(int *n, int *k){
    do{
        printf("\nScrivi il valore di n: ");
        scanf("%d", n);
    }while(*n > DIM);

    do{
        printf("Scrivi il valore di k: ");
        scanf("%d", k);
    }while(*k > *n);

}

void salvataggio(int *n, int *k, Pietra *p){
    int i;

    printf("\n");
    for(i = 0; i < *n; i++){
        printf("Nome pietra %d: ", i + 1);
        scanf("%s", p[i].nome);

        printf("Valore pietra %d: ", i + 1);
        scanf("%d", &p[i].valore);
    }
}

void ordinamento(int *n, int *k, Pietra *p){
    int i, j;
    int tmp;

    for(i = 0; i < *n; i++){
        for(j = i + 1; j < *n; j++){
            if(p[i].valore > p[j].valore){
                tmp = p[i].valore;
                p[i].valore = p[j].valore;
                p[j].valore = tmp;
            }
        }
    }
}

void stampa(int *k, Pietra *p){
    int i;

    printf("\n");
    for(i = 0; i < *k; i++){
        printf("La pietra %d: nome: %s, valore: %d\n", i + 1, p[i].nome, p[i].valore);
    }
}


int main(){
    Pietra pietra[DIM];
    int n,k;

    inserimento(&n, &k);
    salvataggio(&n, &k, pietra);
    ordinamento(&n, &k, pietra);
    stampa(&k, pietra);


    printf("\n");
    return 0;
}