/*
    Scrivere una funzione che, ricevuta come parametro una lista di interi, restituisca
    l’indirizzo di un vettore, allocato dinamicamente, contenente tutti gli elementi della lista.
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


void inserimentoInTesta(Lista *head, int d){
    Nodo *nodo = malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


int *creaVettore(Lista head, int dl){
    int *v = malloc(5 * sizeof(int));
    int i = 0;

    while(head && i < dl){
        v[i] = head->dato;
        head = head->next;
        i++;
    }

    return v;
}


int main(){
    srand(time(NULL));
    Lista head = NULL;
    int dl = rand()% 10 + 1;
    int dato;
    int *vet;
    int i = 0;


    for(i = 0; i < dl; i++){
        dato = rand()% 20;
        inserimentoInTesta(&head, dato);
    }

    vet = creaVettore(head, dl);
    stampa(head);

    printf("\n\n");
    for(i = 0; i < dl; i++){
        printf("%d ", vet[i]);
    }


    printf("\n");
    return 0;
}