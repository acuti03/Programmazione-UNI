#include "headers.h"


int main(int argc, char **argv){
    FILE *f;
    Lista head;
    Record riga;

//  inizializzazione e controlli
    system("clear");
    inizializza(&head);
    if(argc != 2){
        printf("\nErrore...\n");
        exit(1);
    }

    f = fopen(argv[1], "rb");
    if(f == NULL){
        printf("\nErrore...\n");
        exit(1);
    }


//  lettura del file e controllo
    while(fread(&riga, sizeof(Record), 1, f) > 0){
        aggiorna(&head, riga);
    }

//  stampa
    printf("\n\n--- LISTA ---\n\n");
    stampa(head);


    printf("\n");
    return 0;
}