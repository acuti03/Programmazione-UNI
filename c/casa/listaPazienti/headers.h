#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum { falso, vero } Bool;


typedef struct {
    char cf[17];
    int ora;
    float temperatura;
    float saturazione;
} Record;


typedef struct{
    char cf[17];
    int rilevazioni;
    float sommaSat;
    float sommaTemp;
    Bool anomalia;
} Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;


typedef Nodo *Lista;


void stampa(Lista head);
void inizializza(Lista *head);
void aggiorna(Lista *head, Record r);
void elimina(Lista *head);