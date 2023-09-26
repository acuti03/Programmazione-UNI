/*
    Scrivere una funzione che restituisca la lunghezza (cioè il numero di elementi) di una
    lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct nodo{
    int dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;


void stampa(Lista head){
    while(head != NULL){
        printf("|%d| --> ", head->dato);
        head = head->next;
    }

    printf("NULL");
}


int lunghezza(Lista head, int cnt){
    if(head != NULL){
        return lunghezza(head->next, ++cnt);
    }
    return cnt;
}


void inserimentoInTesta(Lista *head, int d){
    Nodo *nodo = malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


int main(){
    srand(time(NULL));
    Lista head = NULL;
    int i;

    for(i = 0; i < rand()% 10 + 1; i++){
        inserimentoInTesta(&head, i);
    }

    stampa(head);
    printf("\nGli elementi della lista sono: %d", lunghezza(head, 0));


    printf("\n");
    return 0;
}