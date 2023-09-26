/*
    Scrivere una funzione che restituisca l’elemento massimo di una lista di interi.
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
    while(head){
        printf("|%d| --> ", head->dato);
        head = head->next;
    }
    printf("NULL");
}


int massimo(Lista head){
    int max = head->dato;

    while(head){
        if(max < head->dato){
            max = head->dato;
        }
        head = head->next;
    }

    return max;
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
    int dato;
    int dl = rand()% 10 + 1;


    for(int i = 0; i < dl; i++){
        dato = rand()% 20 + 1;
        inserimentoInTesta(&head, dato);
    }

    stampa(head);
    printf("\n\nL'elemento massimo è: %d", massimo(head));

    printf("\n");
    return 0;
}