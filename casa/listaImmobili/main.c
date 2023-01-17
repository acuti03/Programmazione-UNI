#include "headers.h"


int main(int argc, char **argv){
    FILE *f;
    FILE *ft; // parte 2
    Record riga;
    Lista head;
    int a;


//  inizializzazioni e controlli
    system("clear");
    inizializza(&head);

    if(argc != 2){
        perror("\nErrore di usabilita...\n");
        exit(EXIT_FAILURE);
    }

    f = fopen(argv[1], "rb");
    ft = fopen("vani.txt", "wt");

    if(f == NULL || ft == NULL){
        perror("\nErrore apertura file\n");
        exit(EXIT_FAILURE);
    }

//  aggiornamento lista
    while(fread(&riga, sizeof(Record), 1, f) > 0){
        inserimentoOrdinato(&head, riga);
    }

//  stampa parte 1
    printf("\n\n--- LISTA ---\n\n");
    stampa(head);

//  parte 2
    printf("\n\nScrivi il numero di vani: ");
    scanf("%d", &a);

    aggiornaLista(&head, a);

    printf("\n\n--- LISTA ---\n\n");
    stampa(head);
    scritturaFile(head, ft);



    fclose(f);
    fclose(ft);
    printf("\n");
    return EXIT_SUCCESS;
}