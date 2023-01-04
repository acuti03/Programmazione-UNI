#include "headers.h"


int main(int argc, char **argv){
    FILE *f;
    Lista head;
    Record riga;


//  inizializzo e controllo
    inizializzaLista(&head);

    if(argc != 2){
        printf("\nUtilizzo del programma errato");
        exit(1);
    }

//  controllo
    f = fopen(argv[1], "rb");
    if(f == NULL){
        printf("\nErrore");
        exit(1);
    }

//  lettura file
    while(fread(&riga, sizeof(Record), 1, f) == 1){
        aggiorna(&head, riga.targa);
    }

    stampa(head);

    fclose(f);
    printf("\n");
    return 0;
}