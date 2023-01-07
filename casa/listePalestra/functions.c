#include "headers.h"


void inizializzaLista(Lista *head){
    *head = NULL;
}


void stampa(Lista head){
    int i;

    while(head){
        printf("%s:\n", head->dato.CF);

        for(i = 0; i < 3; i++){
            if(head->dato.ingressi[i] < 0){
                printf("\tAccesso negato!\n");
            }
            else{
                printf("\tingressi rimanenti attivita %d: %d\n", i + 1, head->dato.ingressi[i]);
            }
        }
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


void riempiLista(Lista *head, char c[17]){
    Dato d;
    int i;

    strcpy(d.CF, c);
    for(i = 0; i < 3; i++){
        d.ingressi[i] = 4;
    }

    inserimentoInTesta(head, d);
}


void aggiornaLista(Lista *head, char c[17], int attivita){
    if(strcmp(c, (*head)->dato.CF) == 0){
        if(attivita == 1){
            (*head)->dato.ingressi[0]--;
        }
        if(attivita == 2){
            (*head)->dato.ingressi[1]--;
        }
        if(attivita == 3){
            (*head)->dato.ingressi[2]--;
        }
    }
}


void controllo(Lista *head, FILE *ft){
    int attivita;
    char CF[17];

    while(*head != NULL){
        while(fscanf(ft, "%s %d", CF , &attivita) > 0){
            aggiornaLista(head, CF, attivita);
        }
        rewind(ft);
        head = &(*head)->next;
    }
    
}