#include <stdio.h>
#include <string.h>
#include "headers.h"

void immettiPersona(Persona *p){
    strcpy(p->nome, "simone");
    p->eta = 19;
}

void stampaPersona(Persona *p){
    printf("\nIl nome della persona: %s\nL'età della persona: %d\n", p->nome, p->eta);
}