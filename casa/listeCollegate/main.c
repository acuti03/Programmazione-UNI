#include "functions.c"


int main(){
    Lista l;
//	INIZIALIZZO LA TESTA
    l = NULL;

//	INSERISCO IN TESTA ALCUNI ELEMENTI
	printf("\nInserimento in testa: ");
	for(int i = 0; i < 5; i++){
		inserimentoInTesta(&l , i);
	}
	stampa(l);

//	INSERISCO IN CODA
	printf("\n\nInserimento in coda: ");
	inserimentoInCoda(&l, 5);
	stampa(l);

//	RICERCO UN DATO NELLA LISTA E LO MODIFICO
	printf("\n\nModifico il dato 5 nella lista: ");
	modifica(&l, 5);
	stampa(l);

//	ELIMINAZIONE DI UN DATO NELLA LISTA
	printf("\n\nEliminazione di un dato (3) nella lista: ");
	eliminaNodo(&l, 3);
	stampa(l);


	printf("\n");
	return 0;
}