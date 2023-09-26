#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    while(head != NULL){
        printf("%s, %d, %0.3f\n", head->dato.indirizzo, head->dato.numeroVani, head->dato.distanza);
        head = head->next;
    }
    
}


void inserimentoInTesta(Lista *head, Record d){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void eliminaInTesta(Lista *head){
    Nodo *nodo = *head;
    *head = (*head)->next;
    free(nodo);
}


void inserimentoOrdinato(Lista *head, Record r){
    while (*head != NULL && (*head)->dato.distanza < r.distanza){
        head = &(*head)->next;
    }
    inserimentoInTesta(head, r);
}


int precede(Record r1, Record r2){
    return r1.numeroVani > r2.numeroVani || r1.numeroVani == r2.numeroVani && r1.distanza < r2.distanza;
}


void inserisci(Lista *head, Record r){
    while (*head != NULL && precede((*head)->dato, r)){
        head = &(*head)->next;
    }
    inserimentoInTesta(head, r);
}


void aggiornaLista(Lista *head, int vani){
    Lista headOrdinata;
    inizializza(&headOrdinata);

    while(*head != NULL){
        if(vani <= (*head)->dato.numeroVani){
            inserisci(&headOrdinata, (*head)->dato);
        }
        eliminaInTesta(head);
    }
    
    *head = headOrdinata;
}


void scritturaFile(Lista head, FILE *f){
    while(head != NULL){
        fprintf(f, "%s %d %0.3f\n", head->dato.indirizzo, head->dato.numeroVani, head->dato.distanza);
        head = head->next;
    }
    
}