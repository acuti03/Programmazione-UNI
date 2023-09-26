#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricola;
    int votoPratico;
    int votoTeorico;
} Dato;

typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;


typedef struct{
    int matricola;
    int voto;
    char tipo;
} Record;


void nuovaLista(Lista *l);
void inserimemtoInTesta(Lista *l, Dato d);
void aggiorna(Lista *l, Record r);
void stampa(Lista l);
void inserimentoOrdinato(Lista *l, Dato d);
int precede(Dato d1, Dato d2);
Lista insertionSort(Lista l1);