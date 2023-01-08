#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    while(head){
        printf("%s, vani: %d, distanza: %f\n", head->dato.indirizzo, head->dato.vani, head->dato.distanza);
        head = head->next;
    }
}


void inserimentoInTesta(Lista *head, Dato d){
    Nodo *nodo = malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void eliminaInTesta(Lista *head){
    Nodo *nodo = *head;
    *head = (*head)->next;
    free(nodo);
}


void inserimentoOrdinato(Lista *head, Dato d){
    while(*head != NULL && (*head)->dato.distanza < d.distanza){
        head = &(*head)->next;
    }
    inserimentoInTesta(head, d);
}


void ordina(Lista *head, float n){
    Lista headOrdinata;

    inizializza(&headOrdinata);

    while(*head != NULL){
        if((*head)->dato.vani >= n){
            inserimentoOrdinato(&headOrdinata, (*head)->dato);
        }
        eliminaInTesta(head);
    }
    *head = headOrdinata;
}



void aggiorna(Lista *head, Dato d){
    while(*head != NULL && d.distanza > (*head)->dato.distanza){
        head = &(*head)->next;
    }

    inserimentoInTesta(head, d);
}