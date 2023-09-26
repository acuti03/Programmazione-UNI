#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    float totale;

    while(head != NULL){
        if(head->dato.accessi < 5) totale = 2.0 * head->dato.accessi;
        else if(head->dato.accessi > 5 && head->dato.accessi <= 10) totale = 1.9 * head->dato.accessi;
        else totale = 1.8 * head->dato.accessi;

        printf("%s %0.2f\n", head->dato.targa, totale);
        head = head->next;
    }
    
}



void inserimentoInTesta(Lista *head, Dato d){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void aggiorna(Lista *head, Record r){
    while(*head != NULL && strcmp((*head)->dato.targa, r.targa) != 0){
        head = &(*head)->next;
    }

    if(*head == NULL){
        Dato d;
        strcpy(d.targa, r.targa);
        d.accessi = 0;
        inserimentoInTesta(head, d);
    }
    (*head)->dato.accessi++;
}