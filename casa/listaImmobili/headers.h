#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    char indirizzo[30];
    int vani;
    float distanza;
}Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;


typedef Nodo *Lista;



void stampa(Lista head);
void inizializza(Lista *head);
void inserimentoInTesta(Lista *head, Dato d);
void aggiorna(Lista *head, Dato d);
void ordina(Lista *head, float n);