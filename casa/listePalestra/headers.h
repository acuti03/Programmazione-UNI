#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char cf[17];
    int attivita;
} Record;



typedef struct{
    char cf[17];
    int tentativi;
    int attivita1;
    int attivita2;
    int attivita3;
} Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;


typedef Nodo *Lista;


void stampa(Lista head);
void inizializza(Lista *head);
void aggiorna(Lista *head, Record r);
void inserisciCF(Lista *head, char *cf);