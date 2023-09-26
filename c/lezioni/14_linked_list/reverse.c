#include <stdio.h>
#include <stdlib.h>


typedef int Dato;

typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;


void nuovaLista(Lista *l){
    l = NULL;
}

void inserimentoTesta(Lista *l, int a){
    Nodo *aux;

    aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dato = a;
    aux->next = *l;
    *l = aux;
}

void listaCasuale(Lista *l, int nElementi){
    int i;

    for(i = 0; i < nElementi; i++){
        inserimentoTesta(l, rand()% 9);
    }
}

void reverse(Lista l1, Lista *l2){
    nuovaLista(l2);

    while (l1 != NULL){
        inserimentoTesta(l2, l1->dato);
        l1 = l1->next;
    }
    
}

void stampa(Lista l){
    while(l != NULL){
        printf("%d ", l->dato);
        l = l->next;
    }
    printf("\n\n");
}

int main(){
    Lista l1, l2;

    nuovaLista(&l1);
    listaCasuale(&l1, 5);
    stampa(l1);
    reverse(l1, &l2);
    stampa(l2);

    printf("\n");
    return 0;

}