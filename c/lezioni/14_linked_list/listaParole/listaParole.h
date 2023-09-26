#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char parola[31];
    int frequenze;
} Dato;

typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;


void nuovaLista(Lista *l);
void stampa(Lista l);
void inserimentoInTesta(Lista *l, Dato d);
void aggiora(Lista *l, char *s);
void eliminaTesta(Lista *l);
void eliminaParola(Lista *l, char *s);
