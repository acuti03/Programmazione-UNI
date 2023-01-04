#include "headers.h"


void inizializzaLista(Lista *head){
    *head = NULL;
}

float importo(int a){
    if(a <= 5) return a * 2.0;
    else if(a >= 6 && a <= 10) return a * 1.9;
    else return a * 1.8;
}


void stampa(Lista head){
    printf("\nLISTA: \n\n");
    while(head != NULL){
        printf("%s, importo: %.2f", head->dato.targa, importo(head->dato.accessi));
        printf("\n");
        head = head->next;
    }
}


void inserimentoInTesta(Lista *head, Dato d){
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void aggiorna(Lista *head, char *targa){

    while((*head != NULL) && (strcmp((*head)->dato.targa, targa) != 0)){
        head = &(*head)->next;
    }

    if(*head == NULL){
        Dato d;
        d.accessi = 1;
        strcpy(d.targa, targa);
        inserimentoInTesta(head, d);
    }else{
        (*head)->dato.accessi++;
    }
}


