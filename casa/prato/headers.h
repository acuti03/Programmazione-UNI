#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

#define RIG 4
#define COL 6
#define PROB 0.2

typedef enum{
    Vinto,
    Perso,
    InCorso
} Stato;


typedef struct{
    float minata;
    int coperta;
} Casella;


typedef struct{
    Casella griglia[RIG][COL];
} Campo;


typedef struct{
    int riga;
    int colonna;
} Mossa;

float rnd_float(Campo *c, float a, float b);
void inizializza(Campo *c);
void stampaBordo();
void stampaIndici();
int mineVicine(Campo *c, int i, int j);
void stampa(Campo *c);
Stato statoGioco(Campo *c);
void eseguiMossa(Campo *c, Mossa *m);
void scriviMossa(Campo *c);

