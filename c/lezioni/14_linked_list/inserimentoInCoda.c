#include <stdio.h>
#include <stdlib.h>


typedef int Dato;

typedef struct nodo{
    Dato dato;
    struct nodo* next;
} Nodo;

typedef Nodo *Lista;


void stampa(Lista l){
    while(l != NULL){
        printf("%d ", l->dato);
        l = l->next;
    }
    printf("\n");
}
//  INSERIMENTO DI UN SINGOLO DATO IN UNA LISTA
void inserimentoInTesta(Lista *l, int d){
    Nodo *aux;

    aux = (Nodo*)malloc(sizeof(Nodo));

    if(aux == NULL){
        exit(1);
    }
    aux->dato = d;
    aux->next = *l;
    *l = aux;
}

Lista* ricerca(Lista *l){
    while(*l != NULL){
        l = &(*l)->next;
    }
    
    return l;
}


void inserimentoInCoda(Lista *l, int d){
    l = ricerca(l);

    inserimentoInTesta(l, d);
}

int main(){
    Lista l;

    l = NULL;

    inserimentoInTesta(&l, 5);
    inserimentoInTesta(&l, 4);
    stampa(l);
    inserimentoInCoda(&l ,6);
    stampa(l);


    return 0;
}
