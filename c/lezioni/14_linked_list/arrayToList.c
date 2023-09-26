#include <stdio.h>
#include <stdlib.h>

#define DIM 10

typedef int Dato;

typedef struct nodo{
	Dato dato;
	struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void stampa(Lista l){
	if(l != NULL){
		printf("%d ", l->dato);
		stampa(l->next);
	}
}

void inizializzaLista(Lista *l){
	*l = NULL;
}

void inserimentoInTesta(Lista *l, int n){
	Nodo *aux = (Nodo *)malloc(sizeof(Nodo));

	aux->dato = n;
	aux->next = *l;
	*l = aux;
}

void inserimentoInCoda(Lista *l, int n){
	while(*l != NULL){
		l = &(*l)->next;
	}
	inserimentoInTesta(l, n);
}


int main(){
	Lista l;
	int a[DIM] = {1, 0, 4, 5, 9, 10, 8, 3, 7, 2};
	int i;

	inizializzaLista(&l);

	for(i = 0; i < DIM; i++){
		inserimentoInCoda(&l, a[i]);
	}

	stampa(l);


    printf("\n");
	return 0;
}