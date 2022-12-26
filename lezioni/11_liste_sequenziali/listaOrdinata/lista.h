/*
    Lista ordinata
    Scrivere un programma che richieda all’utente un massimo di 50 numeri positivi,
    fermandosi quando l’utente scrive un numero minore o uguale a 0, e stampi i numeri
    positivi inseriti in ordine crescente.
    Per memorizzare i numeri inseriti, definire un ADT lista sequenziale in un file lista.c.
    Il programma principale (nel file main.c) dovrà riferirsi alla lista solo attraverso le
    operazioni disponibili nell’header lista.h, contenente la definizione dei tipi di dato e
    la dichiarazione delle funzioni condivise.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 50


typedef struct{
    int dati[DIM];
    int nElementi;
} Lista;


void creaLista(Lista *l);
int piena(Lista l);
void inserimentoOrdinato(Lista *l, int n);
void stampa(Lista l);


