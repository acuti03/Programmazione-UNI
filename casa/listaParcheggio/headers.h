#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char targa[8];
    float sosta;
} Record;


typedef struct{
    char targa[8];
    int accessi;
}Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
}Nodo;


typedef Nodo *Lista;


void inizializzaLista(Lista *head);
float importo(int accessi);
void stampa(Lista head);
void inserimentoInTesta(Lista *head, Dato d);
void aggiorna(Lista *head, char *targa);