#include "headers.h"


void inizializza(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    while(head != NULL){
        printf("%d: ", head->dato.chip);
        
        if(head->dato.vaccinoC == falso){
            printf("Cimurro ");
        }
        if(head->dato.vaccinoP == falso){
            printf("Parviposi ");
        }
        if(head->dato.vaccinoE == falso){
            printf("Epatite ");
        }
        printf("\n");
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
    while(*head != NULL && (*head)->dato.chip != r.chip){
        head = &(*head)->next;
    }

    if(*head == NULL){
        Dato d;

        d.chip = r.chip;
        d.vaccinoC = falso;
        d.vaccinoP = falso;
        d.vaccinoE = falso;
        inserimentoInTesta(head, d);
    }

    switch(r.tipo){
        case 'C':{
            (*head)->dato.vaccinoC = vero;
            break;
        }
        case 'P':{
            (*head)->dato.vaccinoP = vero;
            break;
        }
        case 'E':{
            (*head)->dato.vaccinoE = vero;
            break;
        }
    }    
}


void eliminaInTesta(Lista *head){
    Nodo *nodo = *head;
    *head = (*head)->next;
    free(nodo);
}


int precede(Dato d1, Dato d2){
    int cnt1 = 0, cnt2 = 0;

    if(d1.vaccinoC == vero) cnt1++;
    if(d1.vaccinoP == vero) cnt1++;
    if(d1.vaccinoE == vero) cnt1++;

    if(d2.vaccinoC == vero) cnt2++;
    if(d2.vaccinoP == vero) cnt2++;
    if(d2.vaccinoE == vero) cnt2++;

    if(cnt1 == cnt2){
        return d1.chip < d2.chip;
    }

    return cnt1 > cnt2;
}


void inserimentoOrdinato(Lista *head, Dato d){
    while(*head != NULL && precede((*head)->dato, d)){
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


void inserimentoFile(Lista head, FILE *f){
    while (head != NULL){
        fprintf(f, "%d\n", head->dato.chip);
        head = head->next;
    }
    
}