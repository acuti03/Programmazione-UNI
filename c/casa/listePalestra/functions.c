#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    while (head != NULL){
        printf("%s: %d %d %d\n", head->dato.cf, head->dato.attivita1, head->dato.attivita2, head->dato.attivita3);
        head = head->next;
    }
}


void inseimentoInTesta(Lista *head, Dato d){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void inserisciCF(Lista *head, char *cf){
    Dato d;
    strcpy(d.cf, cf);
    d.attivita1 = 4;
    d.attivita2 = 4;
    d.attivita3 = 4;
    d.tentativi = 3;
    inseimentoInTesta(head, d);
}


void aggiorna(Lista *head, Record r){
    while (*head != NULL && strcmp((*head)->dato.cf, r.cf) != 0){
        head = &(*head)->next;
    }
    if((*head)->dato.tentativi != 0){
        switch(r.attivita){
            case 1:{
                if((*head)->dato.attivita1 <=0){
                    printf("%s, Attivita 1, accesso negato\n", (*head)->dato.cf);
                    (*head)->dato.tentativi--;
                }
                else{
                    (*head)->dato.attivita1--;
                }
                break;
            }
            case 2:{
                if((*head)->dato.attivita2 <= 0){
                    printf("%s, Attivita 2, accesso negato\n", (*head)->dato.cf);
                    (*head)->dato.tentativi--;
                }
                else{
                    (*head)->dato.attivita2--;
                }
                break;
            }
            case 3:{
                if((*head)->dato.attivita3 <= 0){
                    printf("%s, Attivita 3, accesso negato\n", (*head)->dato.cf);
                    (*head)->dato.tentativi--;
                }
                else{
                    (*head)->dato.attivita3--;
                }
                break;
            }
        }
    }
    else{
        printf("%s: tessera annullata\n", (*head)->dato.cf);
    }
}