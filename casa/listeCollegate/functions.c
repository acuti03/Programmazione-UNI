#include "headers.h"

//  STAMPA DI UNA LISTA
void stampa(Lista l){
    while(l){
        printf("%d ", l->dato);
		l = l->next;
    }
}


//	RICERCA DI UN DATO NELLA LISTA
Lista *ricerca(Lista *l, int d){
	while(*l != NULL && (*l)->dato != d){
		l = &(*l)->next;
	}
	return l;
}


//  CREAZIONE DI UN NODO ED INSERIMENTO IN TESTA
void inserimentoInTesta(Lista *l, int d){
	Nodo *nodo = malloc(sizeof(Nodo)); // alloco un nuovo nodo
	nodo->dato = d; // inserisco il dato nel nuovo nodo
	nodo->next = *l; // nel campo next inserisco la testa
	*l = nodo; // do a nodo il valore della testa, quindi diventerà la nuova testa
}


//	INSERIMENTO IN CODA
void inserimentoInCoda(Lista *l, int d){
	while(*l != NULL){ // scorro la lista fino all ultimo nodo
		l = &(*l)->next;
	}
	inserimentoInTesta(l, 5); // inserisco il nodo
		
}

//	MODIFICA DI UN DATO NELLA LISTA
void modifica(Lista *l, int d){
	l = ricerca(l, 5); // ricerca del dato

	if(l != NULL){
		(*l)->dato = ++d; // modifica del dato
	}
}

//	ELIMINAZIONE DI UN DATO NELLA LISTA
void eliminaNodo(Lista *l, int d){

/*  --- VERSIONE LUNGA ----

    Nodo *prev = NULL;
    Nodo *tmp = *l;

    if(tmp != NULL && tmp->dato == d){ // controllo della testa
        *l = tmp->next;
        free(tmp);
        return;
    }

    while(tmp != NULL && d != tmp->dato){ // controllo del resto della lista
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp == NULL){ // se tmp = NULL allora vuol dire che non ha trovato niente e che non devo 
                    //eliminare nulla
        return;
    }

    prev->next = tmp->next; // se ha trovato il nodo lo salto e libero la memoria
	free(tmp);
*/
//  ---- VERSIONE CORTA ----
    l = ricerca(l, d);
    Nodo *nodo = *l;
    *l = (*l)->next;

    free(nodo);
}
