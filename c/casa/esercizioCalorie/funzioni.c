#include "funzioni.h"

void listaVuota(Lista *l){
//  INIZIALIZZO A 0 LA DIMENSIONE LOGICA
    l->nElementi = 0; //(*l).nElementi
}

int piena(Lista *l){
    return l->nElementi == DIM; // MI RITORNA 1 SE E' PIENA
}

void inserisciInCoda(Lista *l, Alimento a){
    l->dati[l->nElementi] = a;
    l->nElementi++;
}


float calcoloCalorie(char *alimento, Lista *l, float calorie){
    float calorieAlimento;
    int i;

    for(i = 0; i < l->nElementi; i++){
        if(strcmp(l->dati[i].nome, alimento) == 0){
            return (l->dati[i].calorie * calorie) / 100;
        }
    }


    return calorieAlimento;
}
