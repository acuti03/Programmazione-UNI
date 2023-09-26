#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum { falso, vero } Bool;


typedef struct{
    int matricola;
    int punteggio;
    char prova;
} Record;


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


void stampa(Lista head);
void inizializza(Lista *head);
void aggiorna(Lista *head, Record r);
void insertionSort(Lista *head);