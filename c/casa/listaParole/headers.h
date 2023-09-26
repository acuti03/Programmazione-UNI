#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char parola[31];
    int ripetizione;
}Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;


typedef Nodo *Lista;


void inizializza(Lista *head);
void stampa(Lista head);
void aggiorna(Lista *head, char *p);
void insertionSort(Lista *head);
void eliminaParola(Lista *head, char *p);