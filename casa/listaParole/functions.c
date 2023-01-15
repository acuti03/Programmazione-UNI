#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    while (head != NULL){
        head->dato.ripetizione >= 4 ? printf("%s : %d\n", head->dato.parola, head->dato.ripetizione) : 0;
        head = head->next;
    }
}


void inserimentoInTesta(Lista *head, Dato d){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void inserimentoOrdinato(Lista *head, Dato d){
    while(*head != NULL && strlen(d.parola) < strlen((*head)->dato.parola)){
        head = &(*head)->next;
    }
    inserimentoInTesta(head, d);
}


void eliminaInTesta(Lista *head){
    Nodo *nodo = *head;
    *head = (*head)->next;
    free(nodo);
}


void insertionSort(Lista *head){
    Lista headOrdinata;

    inizializza(&headOrdinata);
    while(*head != NULL){
        inserimentoOrdinato(&headOrdinata, (*head)->dato);
        eliminaInTesta(head);
    }
    *head = headOrdinata;
}


void aggiorna(Lista *head, char *p){
    while (*head != NULL && strcmp((*head)->dato.parola, p) != 0){
        head = &(*head)->next;
    }
    if(*head == NULL){
        Dato d;
        strcpy(d.parola, p);
        d.ripetizione = 0;
        inserimentoInTesta(head, d);
    }
    (*head)->dato.ripetizione++;
    
}



void eliminaParola(Lista *head, char *p){
    while(*head != NULL && strcmp((*head)->dato.parola, p) != 0){
        head = &(*head)->next;
    }
    if(*head != NULL){
        eliminaInTesta(head);
    }
}