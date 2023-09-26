#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 1000

typedef struct{
    char nome[31];
    float calorie;
} Alimento;


typedef struct{
    Alimento dati[DIM];
    int nElementi; // DIMENSIONE LOGICA
} Lista;


int piena(Lista *l);
void listaVuota(Lista *l);
void inserisciInCoda(Lista *l, Alimento a);
float calcoloCalorie(char *alimento, Lista *l, float calorie);