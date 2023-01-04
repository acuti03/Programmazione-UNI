#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int chip;
    char vaccinazione;
} Record;


typedef enum { falso, vero } Boolean;


typedef struct{
    int chip;
    Boolean vaccinatoC;
    Boolean vaccinatoP;
    Boolean vaccinatoE;
} Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
}Nodo;


typedef Nodo *Lista;


void inizializzaLista(Lista *head);
void stampa(Lista head);
void inserimentoInTesta(Lista *head, Dato d);
void aggiorna(Lista *head, Record r);