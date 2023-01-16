#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    float mediaTemp, mediaSat;

    while(head != NULL){
        mediaSat = head->dato.sommaSat / head->dato.rilevazioni;
        mediaTemp = head->dato.sommaTemp / head->dato.rilevazioni;

        printf("%s : %0.1f, %0.1f, %u\n", head->dato.cf, mediaTemp, mediaSat, head->dato.anomalia);
        head = head->next;
    }
}


void inserimentoInTesta(Lista *head, Dato d){
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


int annoNascita(char* s){
    return 1900 + 10 * (s[6] - '0') + (s[7] - '0');
}


void aggiorna(Lista *head, Record r){
    while(*head != NULL && strcmp((*head)->dato.cf, r.cf) != 0){
        head = &(*head)->next;
    }

    if(*head == NULL){
        Dato d;

        strcpy(d.cf, r.cf);
        d.rilevazioni = 0;
        d.sommaSat = 0;
        d.sommaTemp = 0;
        d.anomalia = falso;
        if(annoNascita(r.cf) >= 1950 && (r.temperatura > 37.5 || r.saturazione < 96)) d.anomalia = vero;

        inserimentoInTesta(head, d);
    }
    (*head)->dato.rilevazioni++;
    (*head)->dato.sommaSat += r.saturazione;
    (*head)->dato.sommaTemp += r.temperatura;
}


void elimina(Lista *head){
    int mediaTemp, mediaSat;

    while(*head != NULL){
        mediaSat = (*head)->dato.sommaSat / (*head)->dato.rilevazioni;
        mediaTemp = (*head)->dato.sommaTemp / (*head)->dato.rilevazioni;

        if((*head)->dato.anomalia == vero){
            eliminaInTesta(head);
        }
        else{
            head = &(*head)->next;
        }
    }
}