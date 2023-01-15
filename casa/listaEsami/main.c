#include "headers.h"


int main(int argc, char **argv){
    FILE *f;
    Lista head;
    Record riga;


//  inizializzazioni e controlli
    system("clear");
    inizializza(&head);
    if(argc != 2){
        printf("\nErrore di usabilità...\n");
        exit(EXIT_FAILURE);
    }

    f = fopen(argv[1], "rb");

    if(f == NULL){
        printf("\nErrore di lettura file...\n");
    }


//  aggiornamento lista
    while(fread(&riga, sizeof(Record), 1, f) > 0){
        aggiorna(&head, riga);
    }
    printf("\n\n--- LISTA PARTE 1 ---\n\n");
    stampa(head);


//  parte 2
    insertionSort(&head);
    printf("\n\n--- LISTA PARTE 2 ---\n\n");
    stampa(head);


    fclose(f);
    printf("\n");
    return EXIT_SUCCESS;
}