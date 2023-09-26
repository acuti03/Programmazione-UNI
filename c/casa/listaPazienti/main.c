#include "headers.h"


int main(int argc, char **argv){
    FILE *f;
    Lista head;
    Record riga;


//  inizializzazioni e controlli
    system("clear");
    inizializza(&head);
    if(argc != 2){
        printf("\nErrore di usabilità del programma...\n");
        exit(EXIT_SUCCESS);
    }

    f = fopen(argv[1], "rt");

    if(f == NULL){
        printf("\nErrore di lettura del file...\n");
        exit(EXIT_FAILURE);
    }

//  inserimento degli elementi nella lista
    while(fread(&riga, sizeof(Record), 1, f) > 0){
        aggiorna(&head, riga);
    }
    printf("\n\n--- LISTA 1 ---\n\n");
    stampa(head);

//  parte 2
    elimina(&head);
    printf("\n\n--- LISTA 2 ---\n\n");
    stampa(head);


    fclose(f);
    printf("\n");
    return EXIT_SUCCESS;
}