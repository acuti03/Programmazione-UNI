#include "headers.h"


void inizializzaLista(Lista *head){
	*head = NULL;
}


void inserimentoInTesta(Lista *head, Dato d){
	Nodo *nodo = malloc(sizeof(Nodo));
	nodo->dato = d;
	nodo->next = *head;
	*head = nodo;
}


void stampa(Lista head){
	while(head != NULL){
		printf("%d: ", head->dato.chip);

		if(head->dato.vaccinatoC == falso){
			printf("Cimurro ");
		}
		if(head->dato.vaccinatoE == falso){
			printf("Epatite ");
		}
		if(head->dato.vaccinatoP == falso){
			printf("Parvovirosi ");
		}

		printf("\n");
		head = head->next;
	}
}


void aggiorna(Lista *head, Record r){
	Dato d;

	while ((*head != NULL) && ((*head)->dato.chip != r.chip)){
		head = &(*head)->next;
	}

	if(*head == NULL){
		d.chip = r.chip;

		switch(r.vaccinazione){
			case 'C':{
				d.vaccinatoC = vero;
				d.vaccinatoP = falso;
				d.vaccinatoE = falso;
				break;
			}
			case 'P':{
				d.vaccinatoP = vero;
				d.vaccinatoC = falso;
				d.vaccinatoE = falso;
				break;
			}
			case 'E':{
				d.vaccinatoE = vero;
				d.vaccinatoP = falso;
				d.vaccinatoC = falso;
				break;;
			}
		}
		inserimentoInTesta(head, d);
	}
	else{
		switch(r.vaccinazione){
			case 'C':{
				(*head)->dato.vaccinatoC = vero;
				break;
			}
			case 'P':{
				(*head)->dato.vaccinatoP = vero;
				break;
			}
			case 'E':{
				(*head)->dato.vaccinatoE = vero;
				break;
			}
		}
	}
	
}