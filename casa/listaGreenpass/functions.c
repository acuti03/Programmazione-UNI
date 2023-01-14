#include "headers.h"


typedef enum{
    TamponeVaccino,
    Vaccino,
    Tampone,
} Greenpass;


void inizializza(Lista *head){
    *head = NULL;
}



void verifica(Lista head, Greenpass *g){
    if(head->dato.tampone && head->dato.vaccino){
        *g = TamponeVaccino;
        return;
    }
    if(head->dato.tampone){
        *g = Tampone;
    }
    if(head->dato.vaccino){
        *g = Vaccino;
    }
}


void stampa(Lista head){
    Greenpass greenpass;

    while (head){
        verifica(head, &greenpass);
        
        if(greenpass == TamponeVaccino){
            printf("%s: tampone e vaccino\n", head->dato.CF);
        }
        if(greenpass == Vaccino){
            printf("%s: vaccino\n", head->dato.CF);
        }
        if(greenpass == Tampone){
            printf("%s: tampone\n", head->dato.CF);
        }
        //printf("%s, vaccino: %u, tampone: %u\n", head->dato.CF, head->dato.vaccino, head->dato.tampone);
        head = head->next;
    }
    
}


void inserimentoInTesta(Lista *head, Dato d){
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void aggiorna(Lista *head, Record r){
    while(*head != NULL && strcmp((*head)->dato.CF, r.CF) != 0){
        head = &(*head)->next;
    }

    if(*head != NULL){
        if(r.evento == 'T') (*head)->dato.tampone = vero;
        else (*head)->dato.vaccino = vero;
        return;
    }

    Dato d;
    strcpy(d.CF, r.CF);

    if(r.evento == 'T'){
        d.tampone = vero;
        d.vaccino = falso;
    }
    else{
        d.vaccino = vero;
        d.tampone = falso;
    }
    inserimentoInTesta(head, d);
    
}