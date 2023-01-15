#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    int totale;

    while(head != NULL){
        totale = head->dato.votoPratico + head->dato.votoTeorico;
        
        printf("%d : ", head->dato.matricola);
        if(totale > 30){
            printf("30 e lode\n");
        }
        else if(totale >= 18){
            printf("%d\n", totale);
        }
        else{
            printf("%d non superato\n", totale);
        }
        head = head->next;
    }
    
}


void eliminaInTesta(Lista *head){
    Nodo *nodo = *head;
    *head = (*head)->next;
    free(nodo);
}


void inserimentoInTesta(Lista *head, Dato d){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void aggiorna(Lista *head, Record r){
    while(*head != NULL && (*head)->dato.matricola != r.matricola){
        head = &(*head)->next;
    }

    if(*head == NULL){
        Dato d;

        d.matricola = r.matricola;
        if(r.prova == 'P'){
            d.votoPratico = r.punteggio;
        }
        else{
            d.votoTeorico = r.punteggio;
        }

        inserimentoInTesta(head, d);
    }
    else{
        if(r.prova == 'P'){
            (*head)->dato.votoPratico = r.punteggio;
        }
        else{
            (*head)->dato.votoTeorico = r.punteggio;
        }
    }
}


void inserimentoOrdinato(Lista *head, Dato d){
    while(*head != NULL && ((*head)->dato.votoPratico + (*head)->dato.votoTeorico) > (d.votoPratico + d.votoTeorico)){
        head = &(*head)->next;
    }
    inserimentoInTesta(head, d);   
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