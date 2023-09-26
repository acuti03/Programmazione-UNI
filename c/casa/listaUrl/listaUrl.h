#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char URL[100];
    int ora;
    int minuti;
} Record;


typedef struct{
    char URL[100];
    int visite;
    int ora;
    int minuti;
} Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
}Nodo;


typedef Nodo *Lista;



void stampa(Lista head);
void inizializza(Lista *head);
void inserimentoIntesta(Lista *head, Dato d);
void aggiorna(Lista *head, Record r);
void ordinaLista(Lista *head);
void inserimentoOrdinato(Lista *head, Dato d);
void eliminaInTesta(Lista *head);
int verifica(Dato d1, Dato d2);
int diffOrario(int ora1, int ora2, int min1, int min2);