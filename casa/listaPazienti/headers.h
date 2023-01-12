#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char CF[17];
    int ora;
    float temperatura;
    float saturazione;
}Record;


typedef struct{
    char CF[17];
    int nRillevazioni;
    float sommaTemperatura;
    float sommaSaturazione;
    int anomalia;
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