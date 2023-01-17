#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char targa[8];
    float durata;
} Record;


typedef struct{
    char targa[8];
    int accessi;
} Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;


typedef Nodo *Lista;


void inizializza(Lista *head);
void stampa(Lista head);
void aggiorna(Lista *head, Record r);