/*
  Scrivere una funzione che azzeri tutti gli elementi della lista di interi che
  riceve come parametro.
*/

#include <stdio.h>
#include <stdlib.h>

// CREO LA STRUTTURA
typedef struct nodo {
	int dato;
	struct nodo *next;
} Nodo;

typedef Nodo *Lista;


//	FUNZIONE DI STAMPA
void stampa(Lista head){
	if(head != NULL){
		printf("|%d| --> ", head->dato);
		stampa(head->next);
	}
}


//	FUNZIONE AZZERA
void azzera(Lista *head){
	while(*head != NULL){
		(*head)->dato = 0;
		head = &(*head)->next;
	}
}


//	INSERIMENTO IN TESTA
void inserimentoInTesta(Lista *head, int d){

	Nodo *nodo = malloc(sizeof(Nodo));
	nodo->dato = d;
	nodo->next = *head;
	*head = nodo;
}



int main() {
	Lista head = NULL;
	int i;

//	CREO I NODI E LI INSERISCO NELLA LISTA
	for(i = 0; i < 5; i++){
		inserimentoInTesta(&head, i);
	}

	stampa(head);
	azzera(&head); // azzero la lista
	printf("\n\n");
	stampa(head);

	printf("\n");
	return 0;
}
