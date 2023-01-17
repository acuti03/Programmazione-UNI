#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char indirizzo[30];
    int numeroVani;
    float distanza;
} Record;


typedef struct nodo{
    Record dato;
    struct nodo *next;
} Nodo;


typedef Nodo *Lista;


void inizializza(Lista *head);
void stampa(Lista head);
void inserimentoOrdinato(Lista *head, Record r);
void aggiornaLista(Lista *head, int vani);
void scritturaFile(Lista head, FILE *f);