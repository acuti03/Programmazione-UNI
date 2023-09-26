#include "lista.h"

void creaLista(Lista *l){
    l->nElementi = 0;
}

int piena(Lista l){
    if(l.nElementi >= DIM){
        return 1;
    }

    return 0;
}

void inserimentoOrdinato(Lista *l, int n){
    int i;

    for(i = l->nElementi; l->dati[i - 1] > n && i > 0; i--){
        l->dati[i] = l->dati[i - 1];
    }

    l->dati[i] = n;
    l->nElementi++;
}

void stampa(Lista l){
    int i;

    printf("\nNumero di elementi: %d\n", l.nElementi);

    for(i = 0; i < l.nElementi; i++){
        printf("%d ", l.dati[i]);
    }
}