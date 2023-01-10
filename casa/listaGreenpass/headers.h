#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum { falso, vero } boolean;


typedef struct{
    int giorno;
    int mese;
    int anno;
    char CF[17];
    char evento;
}Record;


typedef struct{
    boolean vaccino;
    boolean tampone;
    char CF[17];
}Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
}Nodo;


typedef Nodo *Lista;



void inizializza(Lista *head);
void inserimentoInTesta(Lista *head, Dato d);
void stampa(Lista head);
void aggiorna(Lista *head, Record r);