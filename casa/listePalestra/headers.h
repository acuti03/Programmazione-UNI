#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct{
    char CF[17];
    int ingressi[3];
}Dato;


typedef struct nodo{
    Dato dato;
    struct nodo *next;
}Nodo;


typedef Nodo *Lista;


void inizializzaLista(Lista *head);
void stampa(Lista head);
void inserimentoInTesta(Lista *head, Dato d);
void riempiLista(Lista *head, char c[17]);
void aggiornaLista(Lista *head, char c[17], int attivita);
void controllo(Lista *head, FILE *ft);