#include <stdio.h>
#include <stdlib.h>

typedef int Dato;

typedef struct nodo{
    Dato dato;
    struct nodo* next;
} Nodo;

typedef Nodo *Lista;


void stampa(Lista l){
    if(l == NULL){
        printf("\n");
    }
    else{
        printf("%d ", l->dato);
        stampa(l->next);
    }

}

void aggiungiNodo(Lista *l, int d){
    Nodo *aux;

    aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = d;
    aux->next = *l;
    *l = aux;
}


int main(){
    Lista l;
    
    l = NULL;
    aggiungiNodo(&l, 1);
    aggiungiNodo(&l, 5);
    aggiungiNodo(&l, 2);
    stampa(l);


}