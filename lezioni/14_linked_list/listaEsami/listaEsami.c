#include "listaEsami.h"


void nuovaLista(Lista *l){
    *l = NULL;
}

void inserimemtoInTesta(Lista *l, Dato d){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));

    aux->dato = d;
    aux->next = *l;
    *l = aux;
}


void aggiorna(Lista *l, Record r){
    while(*l != NULL && (*l)->dato.matricola != r.matricola){
        l = &(*l)->next;
    }

    if(*l == NULL){
        Dato d;

        d.matricola = r.matricola;
        d.votoPratico = -1;
        d.votoTeorico = -1;

        inserimemtoInTesta(l, d);
    }

    if(r.tipo == 'P'){
        (*l)->dato.votoPratico = r.voto;
    }
    else{
        (*l)->dato.votoTeorico = r.voto;
    }
    
}

int precede(Dato d1, Dato d2){
    if((d1.votoPratico < 12 || d1.votoTeorico < 6) && 
        (d2.votoPratico < 12 || d2.votoTeorico < 6) ||
        d1.votoPratico + d1.votoTeorico == d2.votoPratico + d2.votoTeorico){

        return d1.matricola > d2.matricola;
    }
    else{
        return d1.votoPratico + d1.votoTeorico > d2.votoPratico + d2.votoTeorico;
    }
}

void inserimentoOrdinato(Lista *l, Dato d){
    while(*l != NULL && precede((*l)->dato, d)){
        l = &(*l)->next;
    }
    inserimemtoInTesta(l, d);
}

Lista insertionSort(Lista l1){
    Lista l2;

    while(l1 != NULL){
        inserimentoOrdinato(&l2, l1->dato);
        l1 = l1->next;
    }
    
    return l2;
}


void stampa(Lista l){
    while(l != NULL){
        if(l->dato.votoPratico >= 12 && l->dato.votoPratico >= 6){
            if(l->dato.votoPratico + l->dato.votoTeorico > 30){
                printf("30 e lode");
            }
            else{
                printf("%d", l->dato.votoPratico + l->dato.votoTeorico);
            }
        }
        else{
            printf("Non superato");
        }

        l = l->next;
        printf("\n");
    }
}