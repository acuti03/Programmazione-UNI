#include "listaParole.h"

void nuovaLista(Lista *l){
    *l = NULL;
}

void stampa(Lista l){
    while (l != NULL) {
        if (l->dato.frequenze >= 4)
        printf("%s %d\n", l->dato.parola, l->dato.frequenze);
        l = l->next;
    }
}

void inserimentoInTesta(Lista *l, Dato d){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));

    aux->dato = d;
    aux->next = *l;
    *l = aux;
}

void aggiora(Lista *pl, char *s){
  // finchè 1. la lista non è vuota 2. non ho trovato una parola più corta di
  // s 3. non ho trovato s
    while (*pl != NULL && strlen((*pl)->dato.parola) >= strlen(s) &&
            strcmp((*pl)->dato.parola, s) != 0){
        // aggiorno pl in modo da puntare alla coda di *pl
        pl = &(*pl)->next;
    }
    // se ho trovato la parola da inserire
    if (*pl != NULL && strcmp((*pl)->dato.parola, s) == 0){
        // incremento il suo contatore
        (*pl)->dato.frequenze++;
    }
    else{
        // creo un nuovo dato
        Dato d;
        strcpy(d.parola, s);
        d.frequenze = 1;
        // lo inserisco in testa ad *pl
        inserimentoInTesta(pl, d);
    }
}

void eliminaTesta(Lista *l){
    Nodo *aux = *l;

    *l = (*l)->next;
    free(aux);
}

void eliminaParola(Lista *l, char *s){
    while(*l != NULL){
        if(strcmp((*l)->dato.parola, s) == 0){
            eliminaTesta(l);
            return;
        }
        else{
            l = &(*l)->next;
        }
    }
}