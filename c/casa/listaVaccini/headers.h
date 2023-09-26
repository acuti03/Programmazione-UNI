#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum { falso, vero } Bool;


typedef struct{
    int chip;
    char tipo;
} Record;


typedef struct{
    int chip;
    Bool vaccinoC;
    Bool vaccinoP;
    Bool vaccinoE;
} Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
} Nodo;


typedef Nodo *Lista;


void inizializza(Lista *head);
void stampa(Lista head);
void aggiorna(Lista *head, Record r);
void insertionSort(Lista *head);
void inserimentoFile(Lista head, FILE *f);