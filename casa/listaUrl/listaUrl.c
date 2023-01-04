#include "listaUrl.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    while (head){
        if(head->dato.visite >= 5){
            printf("%s -> visite: %d -> orario: %d:%d", head->dato.URL, head->dato.visite, head->dato.ora, head->dato.minuti);
            printf("\n");
        }
        head = head->next;
    }   
}


int diffOrario(int ora1, int ora2, int min1, int min2){
    if(ora1 != ora2){
        return ora1 - ora2;
    }
    return min1 - min2;
}


void inserimentoIntesta(Lista *head, Dato d){
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}


void aggiorna(Lista *head, Record r){
    while(*head != NULL && strcmp(r.URL, (*head)->dato.URL) != 0){
        head = &(*head)->next;
    }

    if(*head == NULL){
        Dato d;
        d.minuti = r.minuti;
        d.ora = r.ora;
        d.visite = 1;
        strcpy(d.URL, r.URL);
        inserimentoIntesta(head, d);
    }
    else{
        (*head)->dato.visite++;
//      parte 2
        int diff = diffOrario((*head)->dato.ora, r.ora, (*head)->dato.minuti, r.minuti);
        if(diff < 0){
            (*head)->dato.ora = r.ora;
            (*head)->dato.minuti = r.minuti;
        }
    }
    
}


int verifica(Dato d1, Dato d2){
    if(d1.visite != d2.visite){
        return d1.visite - d2.visite;
    }
    
    return -diffOrario(d1.ora, d2.ora, d1.minuti, d2.minuti);
}


void eliminaInTesta(Lista *head){
    Nodo *nodo = *head;
    *head = (*head)->next;
    free(nodo);
}


void inserimentoOrdinato(Lista *head, Dato d){
    while (*head && verifica((*head)->dato, d) >= 0){
        head = &(*head)->next;
    }
    inserimentoIntesta(head, d);
}


//  parte 2
void ordinaLista(Lista *head){
    Lista headOrdinata;
    inizializza(&headOrdinata);

    while(*head){
        inserimentoOrdinato(&headOrdinata, (*head)->dato);
        eliminaInTesta(head);
    }
    
    *head = headOrdinata;
}