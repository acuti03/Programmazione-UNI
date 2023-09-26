#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//  DEFINISCO LA MIA LISTA
typedef struct nodo{
    int dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;



//  FUNZIONI
void stampa(Lista l);
Lista *ricerca(Lista *l, int d);
void inserimentoInTesta(Lista *l, int d);
void inserimentoInCoda(Lista *l, int d);
void modifica(Lista *l, int d);
void eliminaNodo(Lista *l, int d);