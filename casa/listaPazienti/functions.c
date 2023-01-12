#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    float mediaTemp;
    float mediaSat;

    while (head != NULL){
        mediaSat = head->dato.sommaSaturazione / head->dato.nRillevazioni;
        mediaTemp = head->dato.sommaTemperatura / head->dato.nRillevazioni;

        printf("%s, temperatura: %0.1f, saturazione: %0.1f\n", head->dato.CF, mediaTemp, mediaSat);
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
    while(*head != NULL && strcmp((*head)->dato.CF, r.CF) != 0){
        head = &(*head)->next;
    }
    
    if(*head == NULL){
        Dato d;
        strcpy(d.CF, r.CF);
        d.nRillevazioni = 0;
        d.sommaSaturazione = 0.0;
        d.sommaTemperatura = 0.0;
        d.anomalia = 0;
        inserimentoInTesta(head, d);
    }

    (*head)->dato.nRillevazioni++;
    (*head)->dato.sommaSaturazione += r.saturazione;
    (*head)->dato.sommaTemperatura += r.temperatura;

    if(r.temperatura > 37.5 || r.saturazione < 96.0){
        (*head)->dato.anomalia = 1;
    }
}


void eliminaInTesta(Lista *head){
    Nodo *nodo = *head;
    *head = (*head)->next;
    free(nodo);
}

int annoNascita(char *c){
    return 1900 + 10 * (c[6] - '0') + (c[7] - '0');
}


void elimina(Lista *head){
    int anno;

    while(*head != NULL){
        anno = annoNascita((*head)->dato.CF);
        if(anno >= 1950 && !(*head)->dato.anomalia){
            eliminaInTesta(head);
        }
        head = &(*head)->next;
    } 
}