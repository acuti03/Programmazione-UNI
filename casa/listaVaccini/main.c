#include "headers.h"


int main(int argc, char **argv){
	FILE *f;
	Record riga;
	Lista head;

//	inizializzazione lista, file e controlli
	inizializzaLista(&head);
	if(argc != 2){
		printf("\nUtilizzo del programma errato");
		exit(1);
	}

	f = fopen(argv[1], "rb");
	if(f == NULL){
		printf("\nErrore...");
		exit(2);
	}

//	lettura file
	while(fread(&riga, sizeof(Record), 1, f) > 0){
		aggiorna(&head, riga);
	}
	
	printf("\nLista:\n\n");
	stampa(head);



	fclose(f);
	printf("\n");
	return 0;
}